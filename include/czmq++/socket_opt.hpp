// Need to autogenerate these.
inline void set_curve_server(int curve_server) {
    zsocket_set_curve_server(self_, curve_server);
}
inline void set_curve_serverkey(const std::string& curve_serverkey) {
    zsocket_set_curve_serverkey(self_, curve_serverkey.c_str());
}
inline void set_zap_domain(const std::string& zap_domain) {
    zsocket_set_zap_domain(self_, zap_domain.c_str());
}
inline void set_subscribe(const std::string& subscribe) {
    zsocket_set_subscribe(self_, subscribe.c_str());
}
inline void set_identity(const std::string& identity) {
    zsocket_set_identity(self_, identity.c_str());
}
inline void set_linger(int linger) {
    zsocket_set_linger(self_, linger);
}

