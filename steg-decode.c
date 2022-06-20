// steg-decode.c
// Řešení IJC-DU1, příklad b), 14.4.2022
// Autor: Matúš Snopek
// Přeloženo: gcc 9.4.0


#include "error.h"
#include "eratosthenes.h"
#include "bitset.h"
#include "ppm.h"

int main(int argc, char *argv[]){

    if(argc > 2 || argc < 2){
        Error_exit("Chybny format11\n");
    }
    struct ppm *img = ppm_read(argv[1]);
    if(img == NULL){
        Error_exit("Chybny format56\n");
    }
    unsigned long *array;
    bitset_alloc(array, 3 * img->xsize * img->ysize);
    eratosthenes(array);

    unsigned char c;
    int shift =0;
    char ch = 0;
    char uschova= 0;
    int end = 0;

    for(int i = 29; i < 3 * img->xsize * img->ysize; i++){

        if(bitset_getbit(array, i) == 0){
            c = img->data[i];
            ch = c & 0x01;
            uschova ^= ch << shift;
            shift ++;
        }
        if(shift > 7){
            printf("%c", uschova);
            if(uschova == '\0'){
                end = 1;
                break;
            }
            shift = 0;
            c = 0;
            ch = 0;
            uschova = 0;
        }
    }

    if(!end){
        bitset_free(array);
        ppm_free(img);
        Error_exit("Znak \0 nebol najdeny");
    }
    bitset_free(array);
    ppm_free(img);
    return 0;
}