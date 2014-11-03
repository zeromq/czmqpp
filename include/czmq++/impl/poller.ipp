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
#include <czmq++/assert.hpp>

namespace czmqpp {

#define UNUSED(parameter) (void)(parameter)

template <typename... SocketArgs>
poller::poller(SocketArgs&&... sockets)
{
    auto unmask = [](socket& s)
    {
        return s.self();
    };

    self_ = zpoller_new(unmask(sockets)..., NULL);
    CZMQPP_ASSERT(self_);

    // unmask generates an unused parameter warning when called as:
    // czmqpp::poller::poller(SocketArgs&& ...) [with SocketArgs = {}]
    UNUSED(unmask);
}

} // namespace czmqpp

