doc_DATA = README INSTALL COPYING

pkgconfig_DATA = libczmq++.pc

ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
    -I$(srcdir)/include \
    ${libczmq_CFLAGS}

#
# headers
#
czmq___includedir = $(includedir)/czmq++
czmq___include_HEADERS = \
    include/czmq++/czmqpp.hpp \
    include/czmq++/assert.hpp \
    include/czmq++/define.hpp \
    include/czmq++/authenticator.hpp \
    include/czmq++/certificate.hpp \
    include/czmq++/context.hpp \
    include/czmq++/message.hpp \
    include/czmq++/poller.hpp \
    include/czmq++/socket.hpp \
    include/czmq++/socket_opt.hpp \
    include/czmq++/thread.hpp

czmq___impl_includedir = $(includedir)/czmq++/impl
czmq___impl_include_HEADERS = \
    include/czmq++/impl/poller.ipp

#
# library
#
lib_LTLIBRARIES = src/libczmq++.la

src_libczmq___la_SOURCES = \
    src/authenticator.cpp \
    src/certificate.cpp \
    src/context.cpp \
    src/poller.cpp \
    src/message.cpp \
    src/socket.cpp \
    src/thread.cpp

#
# examples
#
EXTRA_PROGRAMS=examples/ironhouse2 examples/poller_test examples/thread_test

# add custom target
examples: ${EXTRA_PROGRAMS}

examples_ironhouse2_SOURCES=\
    examples/ironhouse2.cpp

examples_ironhouse2_LDADD=\
    src/libczmq++.la \
    ${libczmq_LIBS}

examples_poller_test_SOURCES=\
    examples/poller_test.cpp

examples_poller_test_LDADD=\
    src/libczmq++.la \
    ${libczmq_LIBS}

examples_thread_test_SOURCES=\
    examples/thread_test.cpp

examples_thread_test_LDADD=\
    src/libczmq++.la \
    ${libczmq_LIBS}

CLEANFILES=${EXTRA_PROGRAMS}
