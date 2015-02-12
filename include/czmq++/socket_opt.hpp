template <typename Function>
std::string _get_string_option(Function func)
{
    char* c_str = func(self_);
    std::string result(c_str);
    free(c_str);
    return result;
}

// Get socket options
int tos() {
    return zsocket_tos(self_);
}
int plain_server() {
    return zsocket_plain_server(self_);
}
std::string plain_username() {
    return _get_string_option(zsocket_plain_username);
}
std::string plain_password() {
    return _get_string_option(zsocket_plain_password);
}
int curve_server() {
    return zsocket_curve_server(self_);
}
std::string curve_publickey() {
    return _get_string_option(zsocket_curve_publickey);
}
std::string curve_secretkey() {
    return _get_string_option(zsocket_curve_secretkey);
}
std::string curve_serverkey() {
    return _get_string_option(zsocket_curve_serverkey);
}
std::string zap_domain() {
    return _get_string_option(zsocket_zap_domain);
}
int mechanism() {
    return zsocket_mechanism(self_);
}
int ipv6() {
    return zsocket_ipv6(self_);
}
int immediate() {
    return zsocket_immediate(self_);
}
int ipv4only() {
    return zsocket_ipv4only(self_);
}
int type() {
    return zsocket_type(self_);
}
int sndhwm() {
    return zsocket_sndhwm(self_);
}
int rcvhwm() {
    return zsocket_rcvhwm(self_);
}
int affinity() {
    return zsocket_affinity(self_);
}
char * zsocket_identity (void *zocket);
int rate() {
    return zsocket_rate(self_);
}
int recovery_ivl() {
    return zsocket_recovery_ivl(self_);
}
int sndbuf() {
    return zsocket_sndbuf(self_);
}
int rcvbuf() {
    return zsocket_rcvbuf(self_);
}
int linger() {
    return zsocket_linger(self_);
}
int reconnect_ivl() {
    return zsocket_reconnect_ivl(self_);
}
int reconnect_ivl_max() {
    return zsocket_reconnect_ivl_max(self_);
}
int backlog() {
    return zsocket_backlog(self_);
}
int maxmsgsize() {
    return zsocket_maxmsgsize(self_);
}
int multicast_hops() {
    return zsocket_multicast_hops(self_);
}
int rcvtimeo() {
    return zsocket_rcvtimeo(self_);
}
int sndtimeo() {
    return zsocket_sndtimeo(self_);
}
int tcp_keepalive() {
    return zsocket_tcp_keepalive(self_);
}
int tcp_keepalive_idle() {
    return zsocket_tcp_keepalive_idle(self_);
}
int tcp_keepalive_cnt() {
    return zsocket_tcp_keepalive_cnt(self_);
}
int tcp_keepalive_intvl() {
    return zsocket_tcp_keepalive_intvl(self_);
}
std::string tcp_accept_filter() {
    return _get_string_option(zsocket_tcp_accept_filter);
}
int rcvmore() {
    return zsocket_rcvmore(self_);
}
SOCKET fd() {
    return zsocket_fd(self_);
}
int events() {
    return zsocket_events(self_);
}
std::string last_endpoint() {
    return _get_string_option(zsocket_last_endpoint);
}

// Set socket options
void set_tos(int tos) {
    zsocket_set_tos(self_, tos);
}
void set_router_handover(int router_handover) {
    zsocket_set_router_handover(self_, router_handover);
}
void set_router_mandatory(int router_mandatory) {
    zsocket_set_router_mandatory(self_, router_mandatory);
}
void set_probe_router(int probe_router) {
    zsocket_set_probe_router(self_, probe_router);
}
void set_req_relaxed(int req_relaxed) {
    zsocket_set_req_relaxed(self_, req_relaxed);
}
void set_req_correlate(int req_correlate) {
    zsocket_set_req_correlate(self_, req_correlate);
}
void set_conflate(int conflate) {
    zsocket_set_conflate(self_, conflate);
}
void set_plain_server(int plain_server) {
    zsocket_set_plain_server(self_, plain_server);
}
void set_plain_username(const std::string& plain_username) {
    zsocket_set_plain_username(self_, plain_username.c_str());
}
void set_plain_password(const std::string& plain_password) {
    zsocket_set_plain_password(self_, plain_password.c_str());
}
void set_curve_server(int curve_server) {
    zsocket_set_curve_server(self_, curve_server);
}
void set_curve_publickey(const std::string& curve_publickey) {
    zsocket_set_curve_publickey(self_, curve_publickey.c_str());
}
//void zsocket_set_curve_publickey_bin (void *zocket, const byte *curve_publickey);
void set_curve_secretkey(const std::string& curve_secretkey) {
    zsocket_set_curve_secretkey(self_, curve_secretkey.c_str());
}
//void zsocket_set_curve_secretkey_bin (void *zocket, const byte *curve_secretkey);
void set_curve_serverkey(const std::string& curve_serverkey) {
    zsocket_set_curve_serverkey(self_, curve_serverkey.c_str());
}
//void zsocket_set_curve_serverkey_bin (void *zocket, const byte *curve_serverkey);
void set_zap_domain(const std::string& zap_domain) {
    zsocket_set_zap_domain(self_, zap_domain.c_str());
}
void set_ipv6(int ipv6) {
    zsocket_set_ipv6(self_, ipv6);
}
void set_immediate(int immediate) {
    zsocket_set_immediate(self_, immediate);
}
void set_router_raw(int router_raw) {
    zsocket_set_router_raw(self_, router_raw);
}
void set_ipv4only(int ipv4only) {
    zsocket_set_ipv4only(self_, ipv4only);
}
void set_delay_attach_on_connect(int delay_attach_on_connect) {
    zsocket_set_delay_attach_on_connect(self_, delay_attach_on_connect);
}
void set_sndhwm(int sndhwm) {
    zsocket_set_sndhwm(self_, sndhwm);
}
void set_rcvhwm(int rcvhwm) {
    zsocket_set_rcvhwm(self_, rcvhwm);
}
void set_affinity(int affinity) {
    zsocket_set_affinity(self_, affinity);
}
void set_subscribe(const std::string& subscribe) {
    zsocket_set_subscribe(self_, subscribe.c_str());
}
void set_unsubscribe(const std::string& unsubscribe) {
    zsocket_set_unsubscribe(self_, unsubscribe.c_str());
}
void set_identity(const std::string& identity) {
    zsocket_set_identity(self_, identity.c_str());
}
void set_rate(int rate) {
    zsocket_set_rate(self_, rate);
}
void set_recovery_ivl(int recovery_ivl) {
    zsocket_set_recovery_ivl(self_, recovery_ivl);
}
void set_sndbuf(int sndbuf) {
    zsocket_set_sndbuf(self_, sndbuf);
}
void set_rcvbuf(int rcvbuf) {
    zsocket_set_rcvbuf(self_, rcvbuf);
}
void set_linger(int linger) {
    zsocket_set_linger(self_, linger);
}
void set_reconnect_ivl(int reconnect_ivl) {
    zsocket_set_reconnect_ivl(self_, reconnect_ivl);
}
void set_reconnect_ivl_max(int reconnect_ivl_max) {
    zsocket_set_reconnect_ivl_max(self_, reconnect_ivl_max);
}
void set_backlog(int backlog) {
    zsocket_set_backlog(self_, backlog);
}
void set_maxmsgsize(int maxmsgsize) {
    zsocket_set_maxmsgsize(self_, maxmsgsize);
}
void set_multicast_hops(int multicast_hops) {
    zsocket_set_multicast_hops(self_, multicast_hops);
}
void set_rcvtimeo(int rcvtimeo) {
    zsocket_set_rcvtimeo(self_, rcvtimeo);
}
void set_sndtimeo(int sndtimeo) {
    zsocket_set_sndtimeo(self_, sndtimeo);
}
void set_xpub_verbose(int xpub_verbose) {
    zsocket_set_xpub_verbose(self_, xpub_verbose);
}
void set_tcp_keepalive(int tcp_keepalive) {
    zsocket_set_tcp_keepalive(self_, tcp_keepalive);
}
void set_tcp_keepalive_idle(int tcp_keepalive_idle) {
    zsocket_set_tcp_keepalive_idle(self_, tcp_keepalive_idle);
}
void set_tcp_keepalive_cnt(int tcp_keepalive_cnt) {
    zsocket_set_tcp_keepalive_cnt(self_, tcp_keepalive_cnt);
}
void set_tcp_keepalive_intvl(int tcp_keepalive_intvl) {
    zsocket_set_tcp_keepalive_intvl(self_, tcp_keepalive_intvl);
}
void set_tcp_accept_filter(const std::string& tcp_accept_filter) {
    zsocket_set_tcp_accept_filter(self_, tcp_accept_filter.c_str());
}

