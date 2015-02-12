AC_PREREQ([2.65])
AC_INIT([libczmqpp], [1.1.0], [genjix@riseup.net])
AC_LANG(C++)
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([subdir-objects])
AC_USE_SYSTEM_EXTENSIONS
AM_PROG_AR
LT_INIT
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_GNU_SOURCE
AX_CXX_COMPILE_STDCXX_11(noext,mandatory)
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Declare environment variables that affect the build.
#------------------------------------------------------------------------------
AC_ARG_VAR([CC], "C compiler to use, such as gcc or clang")
AC_ARG_VAR([CXX], "C++ compiler to use, such as g++ or clang++")
AC_ARG_VAR([PKG_CONFIG_PATH], "Additional directories for package discovery.")

# Support --with-pkgconfigdir option (after verifying package config install).
#------------------------------------------------------------------------------
PKG_PROG_PKG_CONFIG
AC_MSG_CHECKING(--with-pkgconfigdir option)
AC_ARG_WITH([pkgconfigdir], 
    AS_HELP_STRING([--with-pkgconfigdir=PATH], 
        [Path to pkgconfig directory.]),
    [pkgconfigdir=$withval], 
    [pkgconfigdir=${libdir}/pkgconfig])
AC_MSG_RESULT($pkgconfigdir)
AC_SUBST([pkgconfigdir])

# Require libczmq package min version.
#------------------------------------------------------------------------------
PKG_CHECK_MODULES([libczmq], [libczmq])

# Set warning levels.
#------------------------------------------------------------------------------
AX_CHECK_COMPILE_FLAG([-Wall],
    [CXXFLAGS="$CXXFLAGS -Wall"])

AX_CHECK_COMPILE_FLAG([-Wextra],
    [CXXFLAGS="$CXXFLAGS -Wextra"])

AX_CHECK_COMPILE_FLAG([-Wno-missing-braces],
    [CXXFLAGS="$CXXFLAGS -Wno-missing-braces"])

AX_CHECK_COMPILE_FLAG([-Wpedantic],
    [CXXFLAGS="$CXXFLAGS -Wpedantic"],
    AX_CHECK_COMPILE_FLAG([-pedantic],
        [CXXFLAGS="$CXXFLAGS -pedantic"]))
        
# socket.cpp accepts a non-literal format string with no args.
AX_CHECK_COMPILE_FLAG([-Wno-format-security],
    [CXXFLAGS="$CXXFLAGS -Wno-format-security"])

# Set compiler flags.
#------------------------------------------------------------------------------
AX_CHECK_COMPILE_FLAG([-fvisibility-inlines-hidden],
    [CXXFLAGS="$CXXFLAGS -fvisibility-inlines-hidden"])

AX_CHECK_COMPILE_FLAG([-fvisibility=internal],
    [CXXFLAGS="$CXXFLAGS -fvisibility=internal"],
    AX_CHECK_COMPILE_FLAG([-fvisibility=hidden],
        [CXXFLAGS="$CXXFLAGS -fvisibility=hidden"]))

AX_CHECK_COMPILE_FLAG([-fstack-protector],
    [AX_CHECK_LINK_FLAG([-fstack-protector], 
        [CXXFLAGS="$CXXFLAGS -fstack-protector"])])

AX_CHECK_COMPILE_FLAG([-fstack-protector-all],
    [AX_CHECK_LINK_FLAG([-fstack-protector-all],
        [CXXFLAGS="$CXXFLAGS -fstack-protector-all"])])

# Generate output files.
#------------------------------------------------------------------------------
AC_CONFIG_FILES([Makefile libczmq++.pc])
AC_OUTPUT

