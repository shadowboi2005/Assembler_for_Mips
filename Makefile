# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++20

# Source files
SOURCES = linereader.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
EXEC = linereader

all:$(EXEC)
	@./linereader test.s

