# The compiler: gcc for C programs
CC = gcc

# Compiler flags:
CFLAGS += -Wall -Wextra -Werror

# headers file
DEPS += src/my_ls.h

# All files we need for our executable.
OBJFILES = src/main.c src/options.c src/print_content.c src/strcmp.c\
						 src/swap.c src/time_sort.c

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
