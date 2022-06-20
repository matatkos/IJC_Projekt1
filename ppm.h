// ppm.h
// Řešení IJC-DU1, příklad b), 14.4.2022
// Autor: Matúš Snopek
// Přeloženo: gcc 9.4.0

#include <stdio.h>
//Struktura obsahujuca x-ovu velkost a y-ovu velkost obrazka a k tomu jeho data
struct ppm{
    unsigned xsize;
    unsigned ysize;
    char data[];
};

//Funkcia na citanie dat z obrazka
struct ppm * ppm_read(const char *filename);

//Uvolnenie pamati obrazka
void ppm_free(struct ppm *p);
