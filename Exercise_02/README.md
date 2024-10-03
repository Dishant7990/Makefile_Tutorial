# Simple C Project with Makefile

This project demonstrates a basic C program that consists of multiple source files and a header file. The program calculates the factorial of a number and prints "Hello World!" using functions defined in different source files. The purpose of this project is to show how to compile multiple C files using a Makefile.

## Project Structure

The project consists of the following files:
- `main.c`: The main program that calls functions from other source files.
- `hello.c`: Defines the `print_hello()` function that prints "Hello World!".
- `factorial.c`: Defines the `factorial(int n)` function that calculates the factorial of a given number.
- `functions.h`: Header file containing function prototypes for `print_hello()` and `factorial(int n)`.

## File Descriptions

- **main.c**: Contains the `main` function, which calls the `print_hello` and `factorial` functions.
- **hello.c**: Implements the `print_hello` function that prints "Hello World!".
- **factorial.c**: Implements the recursive `factorial` function to compute the factorial of an integer.
- **functions.h**: Declares the function prototypes used in `hello.c` and `factorial.c`.

## Compilation

You can compile the program using the provided `Makefile`. 
Running the `make` command will compile all source files and generate the final executable `hello`.

### Makefile Usage

- `make`: Compiles the project and creates the executable `hello`.
- `make clean`: Removes object files and the executable, cleaning the build directory.

To compile the project, simply run:

- make

# Understanding Automatic Variables in Makefiles

This project demonstrates how automatic variables like `$<` and `$@` are used in Makefiles to simplify the process of compiling multiple source files in C projects.

## Automatic Variables in Makefiles

Makefiles are special format files used to automate the compilation process for projects with multiple source files. When writing Makefiles, certain automatic variables can be used to refer to the components of the current rule, making the Makefile more concise and flexible.

### Key Automatic Variables:

1. **`$<`**:
   - This represents the **first prerequisite** (or dependency) in the rule. In the context of a compilation rule, it refers to the source file that triggered the rule.
   - For example, in the rule:
     ```makefile
     %.o: %.c
         $(CC) $(CFLAGS) -c $< -o $@
     ```
     - Here, `$<` is the `.c` file (the source file) that is being compiled.

2. **`$@`**:
   - This represents the **target** of the rule. In most cases, it's the file you're trying to generate.
   - For example, in the same rule:
     ```makefile
     %.o: %.c
         $(CC) $(CFLAGS) -c $< -o $@
     ```
     - Here, `$@` is the `.o` file (the object file) that is being created.

## Example Breakdown:

Consider the following rule in the Makefile:

```makefile
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@


## Why Use Automatic Variables?

Using automatic variables in Makefiles allows you to write general rules for compiling and linking code, making it easier to manage complex projects. Instead of specifying the source and target files manually in each rule, you can rely on automatic variables to handle them dynamically.

By understanding and using variables like $< and $@, you can:
- Avoid repetitive code in your Makefiles.
- Handle multiple source files more easily.
- Reduce the risk of errors when compiling projects.

``` bash
dishant@LAPTOP-U0LEAJTC:~/Makefile_Tutorial/Exercise_02$ make
gcc -Wall -g -c main.c -o main.o
gcc -Wall -g -c hello.c -o hello.o
gcc -Wall -g -c factorial.c -o factorial.o
gcc -Wall -g -o hello main.o hello.o factorial.o

dishant@LAPTOP-U0LEAJTC:~/Makefile_Tutorial/Exercise_02$ ./hello
Hello World!
The factorial of 5 is 120

dishant@LAPTOP-U0LEAJTC:~/Makefile_Tutorial/Exercise_02$ make clean
rm -f main.o hello.o factorial.o hello
