// primes.c
// Řešení IJC-DU1, příklad a), 14.4.2022
// Autor: Matúš Snopek
// Přeloženo: gcc 9.4.0


#include <stdio.h>
#include <time.h>
#include "error.h"
#include "eratosthenes.h"
int main() {
    time_t cas;
    cas = clock();
    bitset_create(pole,300000000);
    eratosthenes(pole);
    unsigned long prvocisla[10];
    int counter = 0;
    for(unsigned long i = (unsigned long) bitset_size(pole) - 1; counter <= 9; i-- ){
        if(bitset_getbit(pole, i) == 0){
            prvocisla[counter] = i;
            counter++;
        }
    }
    for(int j = 9; j >= 0; j--){
        printf("%lu\n",prvocisla[j]);
    }
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-cas)/CLOCKS_PER_SEC);
    return 0;
}
