CXXFLAGS=$(shell pkg-config --cflags libczmq++) -ggdb
LIBS=$(shell pkg-config --libs libczmq++)

default: all

ironhouse2.o: ironhouse2.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

ironhouse2: ironhouse2.o
	$(CXX) -o $@ $< $(LIBS)

all: ironhouse2

clean:
	rm -f ironhouse2
	rm -f *.o

