/*
 * Copyright (c) 2011-2013 libczmq++ developers (see AUTHORS)
 *
 * This file is part of libczmq++.
 *
 * libczmq++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) 
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBCZMQPP_POLLER_HPP
#define LIBCZMQPP_POLLER_HPP

#include <czmq++/define.hpp>
#include <czmq++/socket.hpp>

namespace czmqpp {

class CZMQPP_API poller
{
public:
    template <typename... SocketArgs>
    poller(SocketArgs&&... sockets);
    poller(const poller&) = delete;
    ~poller();

    zpoller_t* self();

    void add(socket& sock);
    socket wait(int timeout);
    bool expired();
    bool terminated();
private:
    zpoller_t* self_;
};

} // namespace czmqpp

#include <czmq++/impl/poller.ipp>

#endif

