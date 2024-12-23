# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = fork.c pipe.c kill.c write.c add.c 

# Object files
OBJECTS = fork pipe kill write add

# Default target
all: $(OBJECTS)

# Targets for each file
fork: fork.c
	$(CC) $(CFLAGS) -o $@ $<

pipe: pipe.c
	$(CC) $(CFLAGS) -o $@ $<

kill: kill.c
	$(CC) $(CFLAGS) -o $@ $<

write: write.c
	$(CC) $(CFLAGS) -o $@ $<

add: add.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean target to remove compiled files
clean:
	rm -f $(OBJECTS)
