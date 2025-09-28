CC = g++
CFLAGS = -Wall -g -Wextra
OBJS = parallel_eratosthenes.cpp

make:
	$(CC) $(OBJS) -o parallel_eratosthenes $(CFLAGS)

clean:
	rm parallel_eratosthenes

recomp: clean make