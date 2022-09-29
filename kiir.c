#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filekez.h"
#include "str.h"
#include "kiir.h"

void menuk()
{
    printf("\nTelefonkonyv\n\n");
    printf("Irja be a megfelelo szamot a menupont eleresehez!\n");
    printf("[1]Telefonkonyv listazasa\n");
    printf("[2]Felteteles listazas\n");
    printf("[3]Elem hozzaadasa\n");
    printf("[4]Elem modosita\n");
    printf("[5]vCard import\n");
    printf("[6]vCard export\n");
    printf("[0]Kilepes\n");
}
