CC = gcc
CXX = g++
CFLAGS = -Wall -g
CXXFLAGS = -Wall -g
INCLUDES_C = -I./include/c
INCLUDES_CPP = -I./include/cpp
C_SOURCE_DIR = src/c
CPP_SOURCE_DIR = src/cpp
BUILD_DIR = build
BUILD_C_DIR = $(BUILD_DIR)/c
BUILD_CPP_DIR = $(BUILD_DIR)/cpp

C_SOURCES = $(wildcard $(C_SOURCE_DIR)/*.c)
CPP_SOURCES = $(wildcard $(CPP_SOURCE_DIR)/*.cpp)
C_OBJECTS = $(C_SOURCES:$(C_SOURCE_DIR)/%.c=$(BUILD_C_DIR)/%.o)
CPP_OBJECTS = $(CPP_SOURCES:$(CPP_SOURCE_DIR)/%.cpp=$(BUILD_CPP_DIR)/%.o)
C_EXECUTABLE = $(BUILD_DIR)/cshell
CPP_EXECUTABLE = $(BUILD_DIR)/cppshell

# default rule
all: $(C_EXECUTABLE) $(CPP_EXECUTABLE)

# rule for building C shell
$(C_EXECUTABLE): $(C_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES_C) -o $@ $^

# rule for building C++ shell
$(CPP_EXECUTABLE): $(CPP_OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES_CPP) -o $@ $^

# rule for building C objects
$(BUILD_C_DIR)/%.o: $(C_SOURCE_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES_C) -c $< -o $@

# rule for building C++ objects
$(BUILD_CPP_DIR)/%.o: $(CPP_SOURCE_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES_CPP) -c $< -o $@

# rule for cleaning the project
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
