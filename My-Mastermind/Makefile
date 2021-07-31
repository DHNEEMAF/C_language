# The compiler: gcc for C programs
CC = gcc

# Compiler flags:
CFLAGS += -Wall -Wextra -Werror 
DEPS += src/mastermind.h

# All the .o files we need for our executable.
OBJFILES = src/main.c src/mastermind.c

# The name of the program that we are producing.
TARGET = mastermind

# When we just run "make", what gets built? 
# This is a "phony" target
# that just tells make what other targets to build.
all: $(TARGET)

# The executable
$(TARGET): $(OBJFILES) $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

# A "phony" target to remove built files and backups
.PHONY: clean
clean:
	rm -f *.o $(TARGET)
