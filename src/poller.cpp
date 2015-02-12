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
#include <czmq++/poller.hpp>

#include <czmq++/assert.hpp>

namespace czmqpp {

poller::~poller()
{
    CZMQPP_ASSERT(self_);
    zpoller_destroy(&self_);
}

zpoller_t* poller::self()
{
    return self_;
}

void poller::add(socket& sock)
{
    zpoller_add(self_, sock.self());
}
socket poller::wait(int timeout)
{
    auto sock_ptr = zpoller_wait(self_, timeout);
    return socket(sock_ptr);
}
bool poller::expired()
{
    return zpoller_expired(self_);
}
bool poller::terminated()
{
    return zpoller_terminated(self_);
}

} // namespace czmqpp

