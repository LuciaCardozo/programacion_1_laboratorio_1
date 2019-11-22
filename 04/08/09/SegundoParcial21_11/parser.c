#include "linkedList.h"
#include "cachorros.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int parser_parseEmpleados(char* fileName, LinkedList* listaCachorro)
{
    int ret = 0;
    char aux[6][50];
    Cachorro* pCach;
    FILE* pFile = NULL;
    if(fileName != NULL && listaCachorro != NULL)
    {
        pFile = fopen(fileName,"r");
        if(pFile != NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(aux),*(aux+1),*(aux+2),*(aux+3),*(aux+4),*(aux+5));
            do
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(aux),*(aux+1),*(aux+2),*(aux+3),*(aux+4),*(aux+5));

                pCach = cachorro_newParametros(*(aux),*(aux+1),*(aux+2),*(aux+3),*(aux+4),*(aux+5));
                if(pCach != NULL)
                {
                    if(!ll_add(listaCachorro,pCach))
                    {
                        ret = 1;
                    }
                }
            }while(!feof(pFile));
        }
        fclose(pFile);
    }

    return ret; /* OK*/
}
