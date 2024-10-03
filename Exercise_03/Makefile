# Makefile for Calculator Program

CC       = gcc
CFLAGS   = -Wall -g
LDFLAGS  = -lm
TARGET   = calculator
SRC      = main.c add.c sub.c mul.c div.c
OBJ      = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(TARGET)

