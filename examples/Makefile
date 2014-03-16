CXXFLAGS=$(shell pkg-config --cflags libczmq++) -ggdb
LIBS=$(shell pkg-config --libs libczmq++)

default: all

ironhouse2.o: ironhouse2.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

ironhouse2: ironhouse2.o
	$(CXX) -o $@ $< $(LIBS)

poller_test.o: poller_test.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

poller_test: poller_test.o
	$(CXX) -o $@ $< $(LIBS)

thread_test.o: thread_test.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

thread_test: thread_test.o
	$(CXX) -o $@ $< $(LIBS)

all: ironhouse2 poller_test thread_test

clean:
	rm -f ironhouse2 poller_test thread_test
	rm -f *.o

