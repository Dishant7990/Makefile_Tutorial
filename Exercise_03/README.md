# Makefile Macros and Special Variables

This document explains the usage of macros (variables) in a Makefile, along with an example of a simple calculator program where each arithmetic operation is implemented in a separate `.c` file.

## Macros (Variables)

In a Makefile, macros are defined as `KEY = VALUE` pairs. These macros simplify and standardize the values used in commands. Below is an example of defining macros in a Makefile:

```makefile
CC       = gcc
CFLAGS   = -Wall -g
LDFLAGS  = -lm
TARGET   = calculator
SRC      = main.c add.c sub.c mul.c div.c
OBJ      = $(SRC:.c=.o)
```
- **CC** is the C compiler.
- **CFLAGS** contains compiler options (warnings enabled with -Wall, debugging info with -g).
- **LDFLAGS** contains linker flags (e.g., -lm for math library linking).
- **TARGET** is the name of the final executable.
- **SRC** is a list of the source files.
- **OBJ**  converts the .c files into .o object files.

## Special Macros
- `$@` : The name of the target (the file being made).
- `$?` : The names of the changed dependencies (files that have been modified).
- `$<` : The name of the first dependency (used in implicit rules).
- `$*` : The stem (the base name shared between the target and the dependent file).

## Example Rule Using Special Macros
```
$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
```
- `$@` represents the target calculator.
- `$(OBJ)` refers to all object files (main.o, add.o, sub.o, etc.).

## Conventional Macros

Makefiles use various built-in variables (macros) for programs and their arguments. These macros make it easier to reference programs and compiler flags.

## Program Macros
| Macro   | Description                                           |
|-------  |-------------------------------------------------------|
| **CC**  | C compiler program; default is `cc`.                  |
| **RM**  | Remove file program; default is `rm -f`.              |

## Program Argument Macros

| Macro    | Description                                  |
|----------|----------------------------------------------|
| **CFLAGS** | Extra flags for the C compiler.            |
| **LDFLAGS** | Extra flags for the linker.                |

### Output
```
:~/Makefile_Tutorial/Exercise_03$ make
gcc -Wall -g -c main.c -o main.o
gcc -Wall -g -c add.c -o add.o
gcc -Wall -g -c sub.c -o sub.o
gcc -Wall -g -c mul.c -o mul.o
gcc -Wall -g -c div.c -o div.o
gcc -Wall -g -o calculator main.o add.o sub.o mul.o div.o -lm

:~/Makefile_Tutorial/Exercise_03$ ls
Makefile  README.md  add.c  add.o  calculator  calculator.h  div.c  div.o  main.c  main.o  mul.c  mul.o  sub.c  sub.o

:~/Makefile_Tutorial/Exercise_03$ ./calculator
Addition:        10 + 5 = 15
Subtraction:     10 - 5 = 5
Multiplication:  10 * 5 = 50
Division:        10 / 5 = 2

:~/Makefile_Tutorial/Exercise_03$ make clean
rm -f main.o add.o sub.o mul.o div.o calculator
```
