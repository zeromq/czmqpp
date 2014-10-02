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
#ifndef LIBCZMQPP_DEFINES_HPP
#define LIBCZMQPP_DEFINES_HPP

#include <cassert>

#define CZMQPP_ASSERT assert

// See http://gcc.gnu.org/wiki/Visibility

// Generic helper definitions for shared library support
#if defined _MSC_VER || defined __CYGWIN__
    #define CZMQPP_HELPER_DLL_IMPORT __declspec(dllimport)
    #define CZMQPP_HELPER_DLL_EXPORT __declspec(dllexport)
    #define CZMQPP_HELPER_DLL_LOCAL
#else
    #if __GNUC__ >= 4
        #define CZMQPP_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
        #define CZMQPP_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
        #define CZMQPP_HELPER_DLL_LOCAL  __attribute__ ((visibility ("internal")))
    #else
        #define CZMQPP_HELPER_DLL_IMPORT
        #define CZMQPP_HELPER_DLL_EXPORT
        #define CZMQPP_HELPER_DLL_LOCAL
    #endif
#endif

// Now we use the generic helper definitions above to
// define BC_API and BC_INTERNAL.
// BC_API is used for the public API symbols. It either DLL imports or
// DLL exports (or does nothing for static build)
// BC_INTERNAL is used for non-api symbols.

#if defined LIBCZMQPP_STATIC
    #define CZMQPP_API
    #define CZMQPP_INTERNAL
#elif defined LIBCZMQPP_EXPORTS
    #define CZMQPP_API      CZMQPP_HELPER_DLL_EXPORT
    #define CZMQPP_INTERNAL CZMQPP_HELPER_DLL_LOCAL
#else
    #define CZMQPP_API      CZMQPP_HELPER_DLL_IMPORT
    #define CZMQPP_INTERNAL CZMQPP_HELPER_DLL_LOCAL
#endif

#endif

