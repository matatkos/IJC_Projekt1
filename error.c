// error.c
// Řešení IJC-DU1, příklad a), 14.4.2022
// Autor: Matúš Snopek
// Přeloženo: gcc 9.4.0


#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void Warning_msg(const char *fmt, ...){
    va_list  ap;
    va_start(ap, fmt);
    fprintf(stderr, "CHYBA:");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

void Error_exit(const char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "CHYBA:");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(1);
}

