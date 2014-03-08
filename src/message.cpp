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
#include <czmq++/message.hpp>

#include <czmq++/assert.hpp>

namespace czmqpp {

void message::append(const data_chunk& part)
{
    parts_.push_back(part);
}
void message::append(data_chunk&& part)
{
    parts_.emplace_back(std::move(part));
}
const data_stack& message::parts() const
{
    return parts_;
}
bool message::send(socket& sock)
{
    zframe_t* frame;
    int flags = ZFRAME_MORE;
    for (auto it = parts_.begin(); it != parts_.end(); ++it)
    {
        if (it == parts_.end() - 1)
            flags = 0;
        frame = zframe_new(it->data(), it->size());
        if (zframe_send(&frame, sock.self(), flags) == -1)
            return false;
    }
    return true;
}
bool message::receive(socket& sock)
{
    int more = 1;
    while (more)
    {
        zframe_t* frame = zframe_recv(sock.self());
        if (!frame)
        {
            zframe_destroy(&frame);
            return false;
        }
        more = zframe_more(frame);
        static_assert (
            sizeof (byte) == sizeof (uint8_t), "Incorrect byte size");
        uint8_t* first = zframe_data(frame);
        uint8_t* last = first + zframe_size(frame);
        parts_.emplace_back(data_chunk(first, last));
        zframe_destroy(&frame);
    }
    return true;
}

} // namespace czmqpp

