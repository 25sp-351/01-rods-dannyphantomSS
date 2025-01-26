# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Target executable
TARGET = rod_cutting

all: $(TARGET)

$(TARGET): rod_cutting.o
	$(CC) $(CFLAGS) -o $(TARGET) rod_cutting.o

rod_cutting.o: rod_cutting.c
	$(CC) $(CFLAGS) -c rod_cutting.c

clean:
	rm -f $(TARGET) *.o

