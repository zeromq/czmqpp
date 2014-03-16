#include <thread>
#include <czmq++/czmq.hpp>

void client_task(const std::string& server_public_text)
{
    //  Load our persistent certificate from disk
    czmqpp::certificate client_cert =
        czmqpp::load_cert("client_cert.txt");
    assert(client_cert.self());

    //  Create client socket and configure it to use full encryption
    czmqpp::context ctx;
    assert(ctx.self());
    czmqpp::socket client(ctx, ZMQ_PULL);
    assert(client.self());
    client_cert.apply(client);
    client.set_curve_serverkey(server_public_text);
    int rc = client.connect("tcp://127.0.0.1:9000");
    assert(rc == 0);

    //  Wait for our message, that signals the test was successful
    czmqpp::message msg;
    msg.receive(client);
    assert(msg.parts().size() == 1);
    assert((msg.parts()[0] == czmqpp::data_chunk{{0xde, 0xad, 0xbe, 0xef}}));
    puts("Ironhouse test OK");
}

void server_task(czmqpp::certificate server_cert)
{
    czmqpp::context ctx;
    assert(ctx.self());

    // Start the authenticator and tell it do authenticate clients
    // via the certificates stored in the .curve directory.
    czmqpp::authenticator auth(ctx);
    auth.set_verbose(true);
    auth.allow("127.0.0.1");
    auth.configure_curve("*", ".curve");

    czmqpp::socket server(ctx, ZMQ_PUSH);
    assert(server.self());
    server_cert.apply(server);
    server.set_curve_server(1);
    int rc = server.bind("tcp://*:9000");
    assert(rc != -1);

    //  Send our test message, just once
    czmqpp::message msg;
    msg.append(czmqpp::data_chunk{{0xde, 0xad, 0xbe, 0xef}});
    msg.send(server);

    zclock_sleep(200);
}

int main()
{
    //  Create the certificate store directory and client certs
    czmqpp::certificate client_cert = czmqpp::new_cert();
    int rc = zsys_dir_create(".curve");
    assert(rc == 0);
    client_cert.set_meta("name", "Client test certificate");
    client_cert.save_public(".curve/testcert.pub");
    rc = client_cert.save("client_cert.txt");
    assert(rc == 0); 

    //  Create the server certificate
    czmqpp::certificate server_cert(czmqpp::new_cert());

    //  Now start the two detached threads; each of these has their
    //  own ZeroMQ context.
    std::string server_public_text = server_cert.public_text();
    std::thread server_thread(server_task, std::move(server_cert));
    std::thread client_thread(client_task, server_public_text);
    
    client_thread.join();
    server_thread.join();
    return 0;
}

