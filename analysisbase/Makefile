
##Basic Makefile for my setup
#Only need to change this to the right package name (will be used to name shared library):
PACKAGE=analysisbase
#Then it will compile all .cpp in util/ as executables in bin/
#And all .cpp in src/ as objects, and then into a shared library; both in lib/

VPATH=src include lib bin util
TARGETS := $(notdir $(basename $(wildcard util/*.cpp)))
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(SOURCES:src/%.cpp=lib/%.o)
DIRS=lib bin

ROOTCFLAGS=`root-config --cflags`
CFLAGS=-c -g -Wall -fPIC $(ROOTCFLAGS)
ROOTLDFLAGS=`root-config --glibs`
LDFLAGS=-Wl,--no-as-needed $(ROOTLDFLAGS)

all: $(DIRS) $(TARGETS) lib$(PACKAGE).so

$(DIRS):
	mkdir -p $@

$(TARGETS): %:  %.cpp lib$(PACKAGE).so
	g++ $< -o bin/$@ -Iinclude $(ROOTCFLAGS) -Llib -l$(PACKAGE) $(LDFLAGS) -g -Wall

lib$(PACKAGE).so: $(OBJS)
	g++ -shared -Wall -g $(LDFLAGS) -o lib/$@ $^

lib/%.o: %.cpp %.h
	g++ $(CFLAGS) -Iinclude -o $@ $<

clean:
	rm -f lib/* bin/*
