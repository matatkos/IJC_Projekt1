// ppm.c
// Řešení IJC-DU1, příklad b), 14.4.2022
// Autor: Matúš Snopek
// Přeloženo: gcc 9.4.0


#include "ppm.h"
#include "error.h"
#include <stdio.h>
#include <string.h>



struct ppm *ppm_read(const char *filename){
    FILE *fp =fopen(filename, "r");
    char cont[3];
    int x;
    int y;
    int color;

    if(!fp){
        Warning_msg("Chybny format1");
        fclose(fp);
        return NULL;
    }
    fscanf(fp, "%s %d %d %d ", cont, &x, &y, &color);

    if(strcmp(cont, "P6") != 0 ){
        Warning_msg("Chybny format2\n");
        fclose(fp);
        return NULL;
    }


    if(color < 0 || color > 255){
        Warning_msg("Zle zadana farba\n");
        fclose(fp);
        return NULL;
    }

    unsigned long size = 3*x*y;
    unsigned long max_size = 3 * 8000 * 8000;

    if(size > max_size){
        Warning_msg("Moc velky obrazok\n");
        fclose(fp);
        return NULL;
    }
    struct ppm *img = malloc(sizeof(struct ppm) + 3*x*y);

    if(img == NULL){
        Warning_msg("Nepodarilo sa alokovat obrazok\n");
        fclose(fp);
        return NULL;
    }

    img->xsize = x;
    img->ysize = y;
    int i = 0;
    while((img->data[i] = (char)fgetc(fp)) != EOF){
        i++;
        if(i>max_size-1){
            Warning_msg("Chybny format4\n");
            free(img);
            fclose(fp);
            return NULL;
        }
    }

    fclose(fp);
    return img;
}

void ppm_free(struct ppm *p){
    free(p);
}
