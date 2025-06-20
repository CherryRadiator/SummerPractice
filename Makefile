# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Target executable name
TARGET = complexTest

# Source files
SOURCES = src/bitonicSort.cpp src/fileIO.cpp src/lsdSort.cpp src/menu.cpp src/main.cpp

# Object files (automatically generated from sources)
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependency tracking)
HEADERS = include/bitonicSort.h include/fileIO.h include/lsdSort.h include/menu.h include/main.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Mark targets that don't create files
.PHONY: all clean rebuild