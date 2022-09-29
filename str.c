#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "filekez.h"
#include "kiir.h"
#include "str.h"
#include "debugmalloc.h"



void teljlistazas(Rekord *eleje)
{
    Rekord *a;
    printf("[Idx] Vnev Knev Nem Varos Tel E-mail Fogl\n");
    for(a = eleje;a!=NULL;a=a->kov)
    {
        printf("[%d] %s %s %s %s %s %s %s\n",a->idx, a->vnev,a->knev,a->nem,a->varos,a->szam,a->mail,a->foglalkozas);
    }
}
void feltlistazas(Rekord * eleje)
{
    printf("Mi alapjan szeretne keresni?\n");
    printf("1:Vnev 2:Knev 3:Nem 4:Varos 5:Tel 6:E-mail 7:Fogl\n");
    int m1;
    scanf("%d",&m1);
    char m2[50];
    printf("Mit keres?\n");
    scanf("%s",&m2);
    Rekord *a;
    int db = 0;
    switch (m1)
    {
        case 1:
            printf("Vezeteknev alapjan:\n");
            for(a=eleje;a!=NULL;a=a->kov)
            {
                if(strcmp(m2,a->vnev)==0)
                {
                    printf("[%d] %s %s %s %s %s %s %s\n",a->idx, a->vnev,a->knev,a->nem,a->varos,a->szam,a->mail,a->foglalkozas);
                    ++db;
                }
            }
            break;
        case 2:
            printf("Keresztnev alapjan:\n");
            for(a=eleje;a!=NULL;a=a->kov)
            {
                if(strcmp(m2,a->knev)==0)
                {
                    printf("[%d] %s %s %s %s %s %s %s\n",a->idx, a->vnev,a->knev,a->nem,a->varos,a->szam,a->mail,a->foglalkozas);
                    ++db;
                }
            }
            break;
        case 3:
            printf("Nem alapjan:\n");
            for(a=eleje;a!=NULL;a=a->kov)
            {
                if(strcmp(m2,a->nem)==0)
                {
                    printf("[%d] %s %s %s %s %s %s %s\n",a->idx, a->vnev,a->knev,a->nem,a->varos,a->szam,a->mail,a->foglalkozas);
                    ++db;
                }
            }
            break;
        case 4:
            printf("Varos alapjan:\n");
            for(a=eleje;a!=NULL;a=a->kov)
            {
                if(strcmp(m2,a->varos)==0)
                {
                    printf("[%d] %s %s %s %s %s %s %s\n",a->idx, a->vnev,a->knev,a->nem,a->varos,a->szam,a->mail,a->foglalkozas);
                    ++db;
                }
            }
            break;
        case 5:
            printf("Telefonszam alapjan:\n");
            for(a=eleje;a!=NULL;a=a->kov)
            {
                if(strcmp(m2,a->szam)==0)
                {
                    printf("[%d] %s %s %s %s %s %s %s\n",a->idx, a->vnev,a->knev,a->nem,a->varos,a->szam,a->mail,a->foglalkozas);
                    ++db;
                }
            }

            break;
        case 6:
            printf("E-mail alapjan:\n");
            for(a=eleje;a!=NULL;a=a->kov)
            {
                if(strcmp(m2,a->mail)==0)
                {
                    printf("[%d] %s %s %s %s %s %s %s\n",a->idx, a->vnev,a->knev,a->nem,a->varos,a->szam,a->mail,a->foglalkozas);
                    ++db;
                }
            }
            break;
        case 7:
            printf("Foglalkozas alapjan:\n");
            for(a=eleje;a!=NULL;a=a->kov)
            {
                if(strcmp(m2,a->foglalkozas)==0)
                {
                    printf("[%d] %s %s %s %s %s %s %s\n",a->idx, a->vnev,a->knev,a->nem,a->varos,a->szam,a->mail,a->foglalkozas);
                    ++db;
                }
            }
            break;
    }
    if(db==0)
    {
        printf("Nincs ilyen adat!");
    }
    else
    {
        printf("%ddb ilyen adat van.",db);
    }
    printf("\n");
}
int rmeret(Rekord *eleje)
{
    Rekord *a;
    int hossz = 0;
    for(a=eleje;a!=NULL;a=a->kov)
    {
        ++hossz;
    }
    return hossz;
}
void add(Rekord *eleje)
{
    Rekord *uj;
    uj = (Rekord*) malloc(sizeof(Rekord));
    printf("Kerem adja meg az uj adatot a kovetkezo formaban!\n");
    printf("Vnev Knev Nem Varos Tel E-mail Fogl\n");
    uj->idx = rmeret(eleje);
    scanf("%s %s %s %s %s %s %s",uj->vnev,uj->knev,uj->nem,uj->varos,uj->szam,uj->mail,uj->foglalkozas);
    Rekord *mozgo = eleje;
    while (mozgo->kov!=NULL)
    {
        mozgo=mozgo->kov;
    }
    mozgo->kov = uj;
    uj->kov = NULL;
}
void mod(Rekord *eleje)
{
    int hossz = rmeret(eleje);

    int m1;
    printf("Melyik indexet szeretne modositani?\n");
    scanf("%d",&m1);
    if(m1>=0 && m1<hossz)
    {
        Rekord *a;
        for(a=eleje;a!=NULL;a=a->kov)
        {
            if(a->idx==m1)
            {
                printf("Mit szeretne modositani?\n");
                printf("1:Vnev 2:Knev 3:Nem 4:Varos 5:Tel 6:E-mail 7:Fogl\n");
                int m2;
                scanf("%d",&m2);
                printf("Kerem irja be az uj adatot: ");
                switch (m2)
                {
                    case 1:
                        scanf("%s",a->vnev);
                        break;
                    case 2:
                        scanf("%s",a->knev);
                        break;
                    case 3:
                        scanf("%s",a->nem);
                        break;
                    case 4:
                        scanf("%s",a->varos);
                        break;
                    case 5:
                        scanf("%s",a->szam);
                        break;
                    case 6:
                        scanf("%s",a->mail);
                        break;
                    case 7:
                        scanf("%s",a->foglalkozas);
                        break;
                    default:
                        printf("Nincs ilyen adat!");
                        break;

                }
                
                

            }

        }
    }
    else
    {
        printf("Nincs ilyen index!");
    }
}
void lista_free(Rekord *eleje)
{
    Rekord * iter = eleje;
    while (iter != NULL)
    {
        Rekord *kov = iter->kov;
        free(iter);
        iter = kov;
    }

}

