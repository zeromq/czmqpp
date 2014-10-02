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
#ifndef LIBCZMQPP_MESSAGE_HPP
#define LIBCZMQPP_MESSAGE_HPP

#include <vector>
#include <stdint.h>
#include <czmq.h>
#include <czmq++/socket.hpp>

namespace czmqpp {

typedef std::vector<uint8_t> data_chunk;
typedef std::vector<data_chunk> data_stack;

class CZMQPP_API message
{
public:
    void append(const data_chunk& part);
    void append(data_chunk&& part);
    const data_stack& parts() const;
    bool send(socket& sock);
    bool receive(socket& sock);

private:
    data_stack parts_;
};

} // namespace czmqpp

#endif

