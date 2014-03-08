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
#ifndef LIBCZMQPP_CERTIFICATE_HPP
#define LIBCZMQPP_CERTIFICATE_HPP

#include <string>
#include <czmq.h>
#include <czmq++/socket.hpp>

namespace czmqpp {

zcert_t* new_cert();
zcert_t* load_cert(const std::string& filename);

class certificate
{
public:
    certificate() = delete;
    certificate(zcert_t* self);
    certificate(certificate&& other);
    certificate(const certificate&) = delete;
    ~certificate();

    zcert_t* self();

    void set_meta(const std::string& name, const std::string& value);
    int save_public(const std::string& filename);
    int save(const std::string& filename);
    std::string public_text() const;
    void apply(socket& sock);

private:
    zcert_t* self_ = nullptr;
};

} // namespace czmqpp

#endif

