#include <czmq++/czmqpp.hpp>

int main()
{
    czmqpp::context ctx;
    assert(ctx.self());

    //  Create a few sockets
    czmqpp::socket vent(ctx, ZMQ_PUSH);
    int rc = vent.bind("tcp://*:9000");
    assert(rc != -1);

    czmqpp::socket sink(ctx, ZMQ_PULL);
    rc = sink.connect("tcp://localhost:9000");
    assert(rc != -1);
    czmqpp::socket bowl(ctx, ZMQ_PULL);
    czmqpp::socket dish(ctx, ZMQ_PULL);

    //  Set-up poller
    czmqpp::poller poller(bowl, sink, dish);
    assert(poller.self());

    zstr_send(vent.self(), "Hello, World");

    //  We expect a message only on the sink
    czmqpp::socket which = poller.wait(-1);
    assert(which == sink);
    assert(poller.expired() == false);
    assert(poller.terminated() == false);
    char *message = zstr_recv(which.self());
    assert(streq(message, "Hello, World"));
    free(message);

    return 0;
}

