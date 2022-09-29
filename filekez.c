#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "str.h"
#include "kiir.h"
#include "filekez.h"
#include "debugmalloc.h"

bool letezik(FILE *f)
{
    if(f==NULL)
        return false;
    return true;
}
int fhossz()
{
    FILE *f1 = fopen("D:\\Programs\\C\\NHZ\\rekord.txt","r");
    int hossz=0;
    char k;
    do
    {
        k = getc(f1);
        if(k=='\n'||k=='\r')
        {
            hossz++;
        }

    }
    while(k!=EOF);
    return hossz;
}
Rekord * feltolt(Rekord *eleje)
{
    FILE *f = fopen("D:\\Programs\\C\\NHZ\\rekord.txt","r");
    int hossz = fhossz();
    for (int i = 0; i < hossz; ++i)
    {
        Rekord *uj;
        uj = (Rekord*)malloc(sizeof(Rekord));
        uj->idx = i;
        fscanf(f,"%s %s %s %s %s %s %s",uj->vnev,uj->knev,uj->nem,uj->varos,uj->szam,uj->mail,uj->foglalkozas);
        uj->kov = NULL;
        if(eleje == NULL)
        {
            eleje = uj;
        }
        else
        {
            Rekord *mozgo = eleje;
            while(mozgo->kov!=NULL)
                mozgo = mozgo->kov;
            mozgo->kov = uj;
        }
    }
    fclose(f);
    return eleje;
}
void lement(Rekord *eleje)
{
    FILE *f = fopen("D:\\Programs\\C\\NHZ\\rekord.txt","w");
    Rekord *a;
    for(a=eleje;a!=NULL;a=a->kov)
    {
        fprintf(f,"%s %s %s %s %s %s %s",a->vnev,a->knev,a->nem,a->varos,a->szam,a->mail,a->foglalkozas);
        fprintf(f,"\n");
    }
    fclose(f);
}
void vcard_import(Rekord *eleje)
{
    printf("Kerem adja meg a cimet!\n");
    char cim[150];
    scanf("%s",cim);
    FILE *v = fopen(cim,"r");
    if(letezik(v)==false)
    {
        printf("Nincs ilyen fajl!");
    }
    else
    {

        Rekord *uj;
        uj = (Rekord*) malloc(sizeof(Rekord));
        uj->idx = rmeret(eleje);
        Rekord *mozgo = eleje;
        while (mozgo->kov!=NULL)
        {
            mozgo=mozgo->kov;
        }
        mozgo->kov = uj;
        uj->kov = NULL;


        for(int i = 0;i<11;++i)
        {
            char sor[150+1];
            int idx = 0;
            int idx2 = 0;
            char temp[50+1];
            for(int j = 0; j<51;++j)
            {
                temp[j] = 0;
            }
            char szemet[50+1];
            if(i==2)
            {
                fscanf(v,"%s %s",sor,szemet);
            }
            else
            {
                fscanf(v,"%s",sor);
            }
            switch(i)
            {
                case 2: ///Knev
                    while(sor[idx]!=':')
                    {
                        ++idx;
                    }
                    ++idx;
                    while(sor[idx]!=0)
                    {
                        temp[idx2] = sor[idx];
                        ++idx;
                        ++idx2;
                    }
                    temp[idx+1] = '\0';
                    strcpy(uj->knev,temp);
                    break;
                case 3: ///Vnev
                    idx =0;
                    idx2 = 0;
                    while(sor[idx]!=':')
                    {
                        ++idx;
                    }
                    ++idx;
                    while(sor[idx]!=';')
                    {
                        temp[idx2] = sor[idx];
                        ++idx;
                        ++idx2;
                    }
                    temp[idx+1] = '\0';
                    strcpy(uj->vnev,temp);
                    break;
                case 4: ///Nem
                    idx =0;
                    idx2 = 0;
                    while(sor[idx]!=':')
                    {
                        ++idx;
                    }
                    ++idx;
                    if(sor[idx]=='M')
                    {
                        uj->nem[0] = '1';
                        uj->nem[1] = '\0';
                    }
                    else
                    {
                        uj->nem[0] = '0';
                        uj->nem[1] = '\0';
                    }
                    break;
                case 5: ///Mail
                    idx =0;
                    idx2 = 0;
                    while(sor[idx]!=':')
                    {
                        ++idx;
                    }
                    ++idx;
                    while(sor[idx]!=0)
                    {
                        temp[idx2] = sor[idx];
                        ++idx;
                        ++idx2;
                    }
                    temp[idx+1] = '\0';
                    strcpy(uj->mail,temp);
                    break;
                case 6: ///Tel
                    idx =0;
                    idx2 = 0;
                    while(sor[idx]!=':')
                    {
                        ++idx;
                    }
                    ++idx;
                    while(sor[idx]!=0)
                    {
                        temp[idx2] = sor[idx];
                        ++idx;
                        ++idx2;
                    }
                    temp[idx+1] = '\0';
                    strcpy(uj->szam,temp);
                    break;
                case 7: ///varos
                    while(sor[idx]!=':')
                    {
                        ++idx;
                    }
                    ++idx;
                    while(sor[idx]!=':')
                    {
                        ++idx;
                    }
                    idx = idx+4;
                    while(sor[idx]!=';')
                    {
                        temp[idx2] = sor[idx];
                        ++idx;
                        ++idx2;
                    }
                    temp[idx+1] = '\0';
                    strcpy(uj->varos,temp);

                    break;
                case 8: ///Fogl
                    idx =0;
                    idx2 = 0;
                    while(sor[idx]!=':')
                    {
                        ++idx;
                    }
                    ++idx;
                    while(sor[idx]!=0)
                    {
                        temp[idx2] = sor[idx];
                        ++idx;
                        ++idx2;
                    }
                    temp[idx+1] = '\0';
                    strcpy(uj->foglalkozas,temp);
                    break;
            }
        }
    }

}
void vcard_export(Rekord *eleje)
{
    printf("Melyik indexet szeretne vCard-ban exportalni?\n");
    int m1;
    scanf("%d",&m1);
    int hossz = rmeret(eleje);

    if(m1>=0 && m1<hossz)
    {
        Rekord *a;
        for(a=eleje;a!=NULL;a=a->kov)
        {
            if(m1==a->idx)
            {

                char cim[1000];
                printf("Kerek egy cimet!\n");
                scanf("%s",cim);
                strcat(cim,a->vnev);
                strcat(cim,a->knev);
                strcat(cim,".vcf");



                FILE *f = fopen(cim,"w");
                fprintf(f,"BEGIN:VCARD\n");
                fprintf(f,"VERSION:3.0\n");
                fprintf(f,"FN;CHARSET=UTF-8:%s %s\n",a->knev,a->vnev);
                fprintf(f,"N;CHARSET=UTF-8:%s;%s;;;\n",a->vnev,a->knev);
                if(a->nem==0)
                {
                    fprintf(f,"GENDER:F\n");
                }
                    else
                {
                    fprintf(f,"GENDER:M\n");
                }
                fprintf(f,"EMAIL;CHARSET=UTF-8;type=HOME,INTERNET:%s\n",a->mail);
                fprintf(f,"TEL;TYPE=CELL:%s\n",a->szam);
                fprintf(f,"ADR;CHARSET=UTF-8:TYPE=HOME:;;;%s;;;\n",a->varos);
                fprintf(f,"TITLE;CHARSET=UTF-8:%s\n",a->foglalkozas);

                fprintf(f,"END:VCARD\n");
                fclose(f);
            }
        }
    }
    else
    {
        printf("Nincs ilyen index");
    }
}
