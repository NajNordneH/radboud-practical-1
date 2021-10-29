##
# Practical 1 Algorithms + Data Structures
#
# @file
# @version 0.1

CC=g++
CFLAGS=-Wall -o

headers :
	$(CC) $(CFLAGS) headers headers.cpp

main :
	$(CC) $(CFLAGS) main main.cpp

# end
