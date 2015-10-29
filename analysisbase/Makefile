
##Basic Makefile for my setup
#Only need to change this to the right package name (will be used to name shared library):
PACKAGE=analysisbase
#Then it will compile all .cpp in util/ as executables in bin/
#And all .cpp in src/ as objects, and then into a shared library; both in lib/

VPATH=src include lib bin util
TARGETS := $(notdir $(basename $(wildcard util/*.cpp)))
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(SOURCES:src/%.cpp=lib/%.o)

all: $(TARGETS) $(OBJS)

$(TARGETS): %:  %.cpp lib$(PACKAGE).so
	g++ $< -o bin/$@ -Iinclude -Llib -l$(PACKAGE)

lib$(PACKAGE).so: $(OBJS)
	g++ -shared -Wall -o lib/$@ $^

lib/%.o: %.cpp
	g++ -g -Wall -fPIC -Iinclude -o $@ -c $<

clean:
	rm -f lib/* bin/*
