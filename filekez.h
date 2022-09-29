#ifndef NHZ_FILEKEZ_H
#define NHZ_FILEKEZ_H
#include <stdbool.h>
#include "str.h"
#include "debugmalloc.h"
bool letezik(FILE *f);
int fhossz();
Rekord*feltolt(Rekord *eleje);
void lement(Rekord *eleje);
void vcard_import(Rekord *eleje);
void vcard_export(Rekord *eleje);
#endif
