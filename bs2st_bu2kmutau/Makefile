
##Basic Makefile for my setup
#Only need to change this to the right package name (will be used to name shared library):
PACKAGE=bs2st_bu2kmutau
#Then it will compile all .cpp in util/ as executables in bin/
#And all .cpp in src/ as objects, and then into a shared library; both in lib/

MYDEPSLD=-L../analysisbase/lib -lanalysisbase
MYDEPSC=-I../analysisbase/include

VPATH=src include lib bin util
TARGETS := $(notdir $(basename $(wildcard util/*.cpp)))
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(SOURCES:src/%.cpp=lib/%.o)
DIRS=lib bin

ROOTCFLAGS=`root-config --cflags`
CFLAGS=-c -g -Wall -Wl,--no-as-needed -fPIC $(ROOTCFLAGS)
ROOTLDFLAGS=`root-config --glibs`
UNAME_S:=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS=-Wl,--no-as-needed $(ROOTLDFLAGS)
else
	LDFLAGS=$(ROOTLDFLAGS)
endif

all: $(DIRS) $(TARGETS) lib$(PACKAGE).so

$(DIRS):
	mkdir -p $@

$(TARGETS): %:  %.cpp lib$(PACKAGE).so
	g++ $< -o bin/$@ -Iinclude $(ROOTCFLAGS) $(MYDEPSC) -Llib -l$(PACKAGE) $(LDFLAGS) $(MYDEPSLD) -g -Wall

lib$(PACKAGE).so: $(OBJS)
	g++ -shared -Wall -g $(LDFLAGS) $(MYDEPSLD) -o lib/$@ $^

lib/%.o: %.cpp %.h
	g++ $(CFLAGS) $(MYDEPSC) -Iinclude -o $@ $<

clean:
	rm -f lib/* bin/*
