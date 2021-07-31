# The compiler: gcc for C programs
CC = gcc

# Compiler flags:
CFLAGS += -Wall -Wextra -Werror

# headers file
DEPS += src/my_readline.h

# All files we need for our executable.
OBJFILES = src/char_memset.c src/find_newline.c src/main.c src/my_readline.c\
						 src/strcat.c src/strcpy.c src/strlen.c 

# The name of the program that we are producing.
TARGET = my_readline

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
