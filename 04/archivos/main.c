#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

int main()
{
    Persona* arrayPersona[QTY_ARRAYPER];
    persona_initArray(arrayPersona,QTY_ARRAYPER);
    persona_addPersona(arrayPersona,QTY_ARRAYPER,"\nDATO NO VALIDO\n",3);
    char a[32];
    char b[32];
    char c[32];
    char d[32];
    pFile = fopen("data.csv","r");
    if(pFile == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",a,b,c,d);
        printf("retorna: %d",r);
        if(r==4)
        {
            persona_newParametros()
        }
            //printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);
        else
            break;
    }
    while(!feof(pFile));
    fclose(pFile);

    return 0;
}
