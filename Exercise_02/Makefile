### Makefile

# Variables
# Compiler settings
CC = gcc
CFLAGS = -Wall -g


# Source and object files
SOURCES = main.c hello.c factorial.c
OBJECTS = $(SOURCES:.c=.o)

# Target executable
TARGET = hello

# Default target: build the executable
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build directory
clean:
	rm -f $(OBJECTS) $(TARGET)

