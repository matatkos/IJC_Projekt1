// error.h
// Řešení IJC-DU1, příklad a), 14.4.2022
// Autor: Matúš Snopek
// Přeloženo: gcc 9.4.0

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

//Vytiskne error s danou message
void Warning_msg(const char *fmt, ...);

//Error s exit kodom
void Error_exit(const char *fmt, ...);

