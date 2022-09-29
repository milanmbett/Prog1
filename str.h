#ifndef NHZ_STR_H
#define NHZ_STR_H
#include "debugmalloc.h"
typedef struct Rekord
{
    int idx;
    char vnev[50+1];
    char knev[50+1];
    char nem[1+1]; ///N-0 F-1
    char varos[30+1];
    char szam[15+1];
    char mail[30+1];
    char foglalkozas[50+1];
    struct Rekord *kov;
}Rekord;
void teljlistazas(Rekord *eleje);
void feltlistazas(Rekord * eleje);
void lista_free(Rekord *eleje);
void mod(Rekord *eleje);
int rmeret(Rekord *eleje);
void add(Rekord *eleje);
#endif
