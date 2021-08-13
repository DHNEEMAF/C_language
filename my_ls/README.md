![linkedin_banner_image_1](https://user-images.githubusercontent.com/67286684/123856903-7efc5880-d8d6-11eb-8dd8-5d6a811fad59.png)

# my_ls project in C programming language

Behaves similarly to the linux ls command.

For each operand that names a file of a type other than directory, my_ls displays its name as well as any requested, associated information.

If no operands are given, the contents of the current directory are displayed. If more than one operand is given, non-directory operands are displayed first; directory and non-directory operands are sorted separately and in lexicographical order.

 # Requirements

Code must be compiled with the flags -Wall -Wextra -Werror.

# The following options are available:

 1. "-a" Include directory entries whose names begin with a dot (.).
 2. "-t" Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.

# Authorized function(s)

- malloc(3) 
- free(3)
- printf(3)
- write(2)
- stat(2)
- lstat(2)
- opendir(2)
- closedir(2)
- readdir(2)

# Unauthorized function(s)

- Any functions/syscalls which does not appear in the previous list

 # Instruction on how to compile and use my_ls.

 1. Because I created a makefile for this program, you can compile by typing "make"
- It will give you the output "my_ls"
 2. Feel free to create your own directories with different type of files in them.
 3. type in your terminal:
 "./my_ls -a" to list all the files in the directory, including the hidden files.
 "./my_ls -t" to sort all the files from most recently modified to least recently
 modified files, and lexicographical order after. 
 4. add -g3 -fsanitize=address in the CFLAGS inside Makefile to see memory leaks
 5. To clean/remove the .o files, type "make clean" in your terminal
