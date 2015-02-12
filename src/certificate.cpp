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
#include <czmq++/certificate.hpp>

#include <czmq++/assert.hpp>

namespace czmqpp {

certificate::certificate()
    : self_(new_cert())
{
    // May be invalid (unlikely).
}
certificate::certificate(zcert_t* self)
    : self_(self)
{
    // May be invalid.
}
certificate::certificate(certificate&& other)
    : self_(other.self_)
{
    // May be invalid.
    // Transfer of pointer ownership.
    other.self_ = nullptr;
}
certificate::certificate(const std::string& filename)
    : self_(zcert_load(filename.c_str()))
{
    // May be invalid.
}
certificate::~certificate()
{
    reset(nullptr);
}

void certificate::reset(zcert_t* self)
{
    if (valid())
        zcert_destroy(&self_);

    // May be invalid.
    self_ = self;
}
zcert_t* certificate::self()
{
    return self_;
}
bool certificate::valid() const
{
    return self_ != nullptr;
}

void certificate::set_meta(const std::string& name, const std::string& value)
{
    zcert_set_meta(self_, name.c_str(), value.c_str());
}
int certificate::save(const std::string& filename)
{
    return zcert_save(self_, filename.c_str());
}
int certificate::save_public(const std::string& filename)
{
    return zcert_save_public(self_, filename.c_str());
}
int certificate::save_secret(const std::string& filename)
{
    return zcert_save_secret(self_, filename.c_str());
}
std::string certificate::public_text() const
{
    return std::string(zcert_public_txt(self_));
}
void certificate::apply(socket& sock)
{
    zcert_apply(self_, sock.self());
}

///////////////////////////////////////////////////////////////////////////////
// DEPRECATED: abstraction leak, use of constructor is recommended.
///////////////////////////////////////////////////////////////////////////////
zcert_t* new_cert()
{
    return zcert_new();
}

///////////////////////////////////////////////////////////////////////////////
// DEPRECATED: abstraction leak, use of constructor is recommended.
///////////////////////////////////////////////////////////////////////////////
zcert_t* load_cert(const std::string& filename)
{
    return zcert_load(filename.c_str());
}


} // namespace czmqpp

