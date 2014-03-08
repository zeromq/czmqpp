// Need to autogenerate these.
inline void set_curve_server(int curve_server) {
    zsocket_set_curve_server(self_, curve_server);
}
inline void set_curve_serverkey(const std::string& curve_serverkey) {
    zsocket_set_curve_serverkey(self_, curve_serverkey.c_str());
}

