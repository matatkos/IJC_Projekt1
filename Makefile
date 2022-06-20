CC=gcc
CFLAGS=-O2 -g -std=c11 -pedantic -Wall -Wextra
all: primes primes-i steg-decode

primes: primes.o error.o eratosthenes.o bitset.o
	$(CC) $(CFLAGS) primes.o error.o eratosthenes.o bitset.o -o primes -lm

primes-i: primes.o error.o eratosthenes.o bitset.o
	$(CC) $(CFLAGS) -DUSE_INLINE primes.o error.o eratosthenes.o bitset.o -o primes-i -lm

steg-decode: steg-decode.o error.o eratosthenes.o ppm.o bitset.o
	$(CC) $(CFLAGS) steg-decode.o error.o eratosthenes.o ppm.o bitset.o -o steg-decode -lm

primes.o: primes.c
	$(CC) -c primes.c

error.o: error.c error.h
	$(CC) -c error.c

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) -c eratosthenes.c

bitset.o: bitset.c bitset.h
	$(CC) -DUSE_INLINE -c bitset.c

ppm.o: ppm.c ppm.h
	$(CC) -c ppm.c

steg-decode.o: steg-decode.c
	$(CC) -c steg-decode.c

run: primes primes-i
	ulimit -s 40000 && ./primes
	ulimit -s 40000 && ./primes-i

clean:
	rm primes
	rm primes-i
	rm steg-decode
	rm *.o