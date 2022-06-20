// bitset.h
// Řešení IJC-DU1, příklad a), 14.4.2022
// Autor: Matúš Snopek
// Přeloženo: gcc 9.4.0
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "error.h"
#ifndef BITSET_H
#define BITSET_H


typedef unsigned long *bitset_t;

typedef unsigned long bitset_index_t;


//Vytvori pole a inicializuje pole
//Zaciname od velkosti + 1 ,lebo 0. index je velkost pola
#define bitset_create(meno_pola, velkost) unsigned long meno_pola[((velkost/((sizeof(unsigned long)* CHAR_BIT))) + (velkost%(sizeof(unsigned long)*CHAR_BIT) > 0 ? 1 : 0))+1] = {velkost, 0};\
    static_assert(velkost>64 && velkost<500000002, "Zle zadana velkost pola") \

//Alokuje pole
#define bitset_alloc(meno_pola, velkost) \
    assert(velkost>64 && velkost<500000002);  \
    meno_pola = (bitset_t)calloc(((velkost / ((sizeof(unsigned long)*CHAR_BIT))) + (velkost%(sizeof(unsigned long)*CHAR_BIT) > 0 ? 1 : 0))+1, sizeof(unsigned long));\
    meno_pola[0] = velkost;



#ifdef USE_INLINE
    //Vracia velkost pola
    inline unsigned long bitset_size(bitset_t meno_pola){
            return meno_pola[0];
        }

    //Nastavuje bit s danym indexom bud na 1 alebo 0
    inline void bitset_setbit(bitset_t meno_pola, unsigned long index, int vyraz){
            if(index >= bitset_size(meno_pola) || index < 0){
                Error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(meno_pola));
            }
            else{
               (vyraz ?
                (meno_pola[index/(sizeof(unsigned long)*CHAR_BIT)+1] |=
                ((unsigned long)1 << (index%(sizeof(unsigned long)*CHAR_BIT))))
                :
                (meno_pola[index/(sizeof(unsigned long)*CHAR_BIT)+1] &=
                ~((unsigned long)1 << (index%(sizeof(unsigned long)*CHAR_BIT)))) );
            }
        }

    //Uvolnuje pamat
    inline void bitset_free(bitset_t meno_pola){
        free(meno_pola);
    }

    //Vracia hodnotu daneho bitu na indexy v poli
    inline int bitset_getbit(bitset_t meno_pola, bitset_index_t index){
        if(index >= bitset_size(meno_pola) || index < 0){
            Error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long) index, (unsigned long)bitset_size(meno_pola));
        }
        return (int)(meno_pola[(index/(sizeof(unsigned long)*CHAR_BIT))+1] & ((unsigned long)1 << (index%(sizeof(unsigned long)*CHAR_BIT)))>0 );
    }



#else

    #define bitset_free(meno_pola) free(meno_pola)


    #define bitset_size(meno_pola) meno_pola[0]
it(meno_pola,index,vyraz) \
            do{                                          \
                if((unsigned long)index >= bitset_size(meno_pola) || index < 0){ \
                    Error_exit("bitset_setbit: Ind
#define bitset_setbex %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(meno_pola)); \
                }                                     \
                if(vyraz) meno_pola[index/(sizeof(unsigned long)*CHAR_BIT) + 1] |= ((unsigned long)1 << (index%(sizeof(unsigned long)*CHAR_BIT)) );\
                else meno_pola[index/(sizeof(unsigned long)*CHAR_BIT) + 1] &= ~((unsigned long)1 << (index%(sizeof(unsigned long)*CHAR_BIT)) ); \
            }                                         \
            while(0)

    #define bitset_getbit(meno_pola, index) \
            (index >= bitset_size(meno_pola) || index < 0) ? \
                Error_exit("bitset_getbit: Index %ld mimo rozsah 0..%ld", (unsigned long)index, (unsigned long)bitset_size(meno_pola)), 0 \
            : \
                (unsigned long)((meno_pola[index/(sizeof(unsigned long)*CHAR_BIT) + 1] & ((unsigned long)1 << (index%(sizeof(unsigned long)*CHAR_BIT))) ) > 0)

#endif

#endif

