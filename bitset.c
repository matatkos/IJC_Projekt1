// bitset.c
// Řešení IJC-DU1, příklad a), 14.4.2022
// Autor: Matúš Snopek
// Přeloženo: gcc 9.4.0
#include "bitset.h"
//Deklaracie funkcii
#ifdef USE_INLINE
extern bitset_index_t bitset_size(bitset_t meno_pola);
extern void bitset_setbit(bitset_t meno_pola, bitset_index_t index, int vyraz);
extern int bitset_getbit(bitset_t meno_pola, bitset_index_t index);
#endif
