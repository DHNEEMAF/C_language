# The compiler: gcc for C programs
CC = gcc

# Compiler flags:
CFLAGS += -Wall -Wextra -Werror

# headers file
DEPS += src/my_printf.h

# All files we need for our executable.
OBJFILES = src/convert.c src/main.c src/my_printf.c src/my_puts.c\
						 src/my_strlen.c src/swap.c

# The name of the program that we are producing.
TARGET = my_ls

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
