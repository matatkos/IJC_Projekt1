// eratosthenes.c
// Řešení IJC-DU1, příklad a), 14.4.2022
// Autor: Matúš Snopek
// Přeloženo: gcc 9.4.0


#include "eratosthenes.h"
#include <math.h>

void eratosthenes(bitset_t pole){
    unsigned long velkost = bitset_size(pole);
    unsigned long limit = sqrt(velkost);

    for(int i = 2; i< limit; i++){
        if(bitset_getbit(pole, i) == 0){
            for(int j = 2; i *j < velkost; j++){
                bitset_setbit(pole, i*j, 1);
            }
        }
    }
}
