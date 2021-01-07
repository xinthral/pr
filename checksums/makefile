####
# Program: Crypto
# Author: Xinthral
# Date Created: 5/12/2020
# Updated last: 1/7/2021
####

# Name of the compiler, gcc or g++ for C++ programs
CC = gcc
# Flags used in compiling
CFLAGS = -g -std=c99 -pedantic -Wall -Wextra -O1
# Flags used in linking, e.g. -lm if you need the math library
LDFLAGS =
# Target excutable name
EXEC = chksum.exe 
# All the object files that are need to build the executable
OBJECTS = Crypto.o Key.o Checksum.o
COMPILD = Crypto Key Checksum

# Default rule, links the *.o files to create the executable
# Typing "make" causes this to happen
${EXEC}: ${OBJECTS}
	${CC} ${LDFLAGS} ${OBJECTS} -o ${EXEC}

# Rule to build the object file for the main program
Crypto.o: Crypto.c Key.h Checksum.h
	${CC} ${CFLAGS} -c Crypto.c

# Rule to build the object file for Key data type
Key.o: Key.c Key.h Checksum.h
	${CC} ${CFLAGS} -c Key.c

# Rule to build the object file for Checksum data type
Checksum.o: Checksum.c Checksum.h
	${CC} ${CFLAGS} -c Checksum.c

# Execute the test program
# Typing "make run" causes this to happen
run: Crypto
	./Crypto

# Blow away all the object files and executable file
# Typing "make clean" causes this to happen
clean:
	rm -f ${EXEC} ${OBJECTS} ${COMPILD}
