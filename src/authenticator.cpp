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
#include <czmq++/authenticator.hpp>

#include <czmq++/assert.hpp>

namespace czmqpp {

authenticator::authenticator(context& ctx)
{
    self_ = zauth_new(ctx.self());
}
authenticator::~authenticator()
{
    CZMQPP_ASSERT(self_);
    zauth_destroy(&self_);
}

zauth_t* authenticator::self()
{
    return self_;
}

void authenticator::allow(const std::string& address)
{
    zauth_allow(self_,
        const_cast<char*>(address.c_str()));
}
void authenticator::deny(const std::string& address)
{
    zauth_deny(self_,
        const_cast<char*>(address.c_str()));
}
void authenticator::configure_plain(
    const std::string& domain, const std::string& filename)
{
    zauth_configure_plain(self_,
        const_cast<char*>(domain.c_str()),
        const_cast<char*>(filename.c_str()));
}
void authenticator::configure_curve(
    const std::string& domain, const std::string& location)
{
    zauth_configure_curve(self_,
        const_cast<char*>(domain.c_str()),
        const_cast<char*>(location.c_str()));
}
void authenticator::set_verbose(bool verbose)
{
    zauth_set_verbose(self_, verbose);
}

} // namespace czmqpp


