AC_INIT([libczmqpp], [0.4.1], [genjix@riseup.net])
AC_USE_SYSTEM_EXTENSIONS
AC_LANG(C++)
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall -Werror])
AM_PROG_AR
LT_INIT
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_GNU_SOURCE
AX_CXX_COMPILE_STDCXX_11(noext,mandatory)

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([libczmq], [libczmq])

AM_CXXFLAGS="-ggdb -g3 -Wall -Wno-missing-braces -Wno-format-security -pedantic -Wextra -fstack-protector-all -DDEBUG"
AC_SUBST([AM_CXXFLAGS])

AC_ARG_WITH([pkgconfigdir], AS_HELP_STRING([--with-pkgconfigdir=PATH],
    [Path to the pkgconfig directory [[LIBDIR/pkgconfig]]]),
    [pkgconfigdir="$withval"], [pkgconfigdir='${libdir}/pkgconfig'])
AC_SUBST([pkgconfigdir])

AC_CONFIG_FILES([Makefile include/czmq++/Makefile src/Makefile libczmq++.pc])
AC_OUTPUT

