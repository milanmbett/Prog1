#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filekez.h"
#include "str.h"
#include "kiir.h"
#include "debugmalloc.h"

int main()
{
    FILE *f = fopen("D:\\Programs\\C\\NHZ\\rekord.txt","r");
    if(letezik(f)==true)
    {
        fclose(f);
        char menu_input;
        bool exit = false;
        Rekord *eleje = NULL;
        eleje = feltolt(eleje);
        while(exit==false)
        {
            menuk();
            char menu_input;
            scanf(" %c",&menu_input);
            switch(menu_input)
            {
                case '1':
                    teljlistazas(eleje);
                    break;
                case '2':
                    feltlistazas(eleje);
                    break;
                case '3':
                    add(eleje);
                    break;
                case '4':
                    mod(eleje);
                    break;
                case '5':
                    vcard_import(eleje);
                    break;
                case '6':
                    vcard_export(eleje);
                    break;
                case '0':
                    lement(eleje);
                    lista_free(eleje);
                    exit = true;
                    break;
                default:
                    printf("\nNem ertelmezett menupont\n");
                    break;
            }
        }
    }

    else
    {
        printf("Nem lehetett beolvasni a fajlt!");
    }

}
