# variables
CC = gcc
CXX = g++
CFLAGS = -Wall -g
CXXFLAGS = -Wall -g
INCLUDES = -I./include
C_SOURCES = $(wildcard src/*.c)
CPP_SOURCES = $(wildcard src/*.cpp)
C_OBJECTS = $(C_SOURCES:.c=.o)
CPP_OBJECTS = $(CPP_SOURCES:.cpp=.o)
C_EXECUTABLE = cshell
CPP_EXECUTABLE = cppshell

# default rule
all: $(C_EXECUTABLE) $(CPP_EXECUTABLE)

# rule for building c shell
$(C_EXECUTABLE): $(C_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

# rule for building c++ shell
$(CPP_EXECUTABLE): $(CPP_OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# rule for building c objects
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# rule for building c++ objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# rule for cleaning the project
clean:
	rm -f $(C_EXECUTABLE) $(CPP_EXECUTABLE) $(C_OBJECTS) $(CPP_OBJECTS)

.PHONY: all clean
