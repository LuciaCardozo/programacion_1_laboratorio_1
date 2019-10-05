#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Instrumento.h"
#include "utn.h"
#define OCUPADO 1
#define LIBRE 0

int initInstrumentos(Instrumento* listInstrumento, int lenInstrumento)
{
    int ret = -1;
    int i;
    if(listInstrumento!=NULL && lenInstrumento>0)
    {
        for(i=0; i<lenInstrumento; i++)
        {
            listInstrumento[i].isEmpty=LIBRE;
        }
        ret = 0;
    }

    return ret;
}

int findFreePlaceInstrumento(Instrumento* listInstrumento, int lenInstrumento)
{
    int ret = -1;
    int i;
    if(listInstrumento!=NULL && lenInstrumento>0)
    {
        for(i=0; i<lenInstrumento; i++)
        {
            if(listInstrumento[i].isEmpty==LIBRE)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int findInstrumentoById(Instrumento* listInstrumento, int lenInstrumento,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listInstrumento!=NULL && lenInstrumento>0 && id>=0)
    {
        for(i=0; i<lenInstrumento; i++)
        {
            if(listInstrumento[i].idInstrumento==id && listInstrumento[i].isEmpty==OCUPADO)
            {
                *posicion=i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}


int addInstrumento(Instrumento* listInstrumento, int lenInstrumento, int id, char *name,int tipo)
{
    int ret = -1;
    int posLibre;

    posLibre= findFreePlaceInstrumento(listInstrumento,lenInstrumento);
    if(listInstrumento!=NULL && lenInstrumento>0)
    {
        if(posLibre!=-1)
        {
            strncpy(listInstrumento[posLibre].nombre,name,50);
            listInstrumento[posLibre].tipo=tipo;
            listInstrumento[posLibre].idInstrumento=id;
            listInstrumento[posLibre].isEmpty=OCUPADO;
        }
        ret = 0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addInstrumento'\n");
    }
    return ret;
}

int registerAnInstrumento(Instrumento *listInstrumento,int lenInstrumento)
{
    char auxName[50];
    int auxTipo;
    int auxId;
    int ret = -1;
    if(listInstrumento!=NULL && lenInstrumento>0)
    {
        if(utn_getValidName(auxName)==0 &&
            utn_getValidInt("\nTipo de instrumento\n1-Cuerdas\n2-Viento-madera\n3-Viento-metal\n4-Percusión\nIngrese opcion: ",
            "\nERROR, no es un tipo de instrumento.",&auxTipo,1,4,2)==0)
            {
                auxId=generarIdInstrumento();
                addInstrumento(listInstrumento,lenInstrumento,auxId,auxName,auxTipo);
                printf("\n---------------------------\n");
                printf("\nID de Instrumento: %d\nNombre: %s",
                auxId,auxName);
                switch(auxTipo)
                {
                    case 1:
                    printf("\nTipo: Cuerdas");
                    break;
                    case 2:
                    printf("\nTipo: Viento-madera");
                    break;
                    case 3:
                    printf("\nTipo: Viento-metal");
                    break;
                    case 4:
                    printf("\nTipo: Percusión");
                    break;
                }
                ret=0;
            }
        }
    return ret;
}
int printInstrumentos(Instrumento *listInstrumento,int lenInstrumento)
{
    int i;
    int ret = -1;
    if(listInstrumento!=NULL && lenInstrumento>0)
    {
        for(i=0; i<lenInstrumento; i++)
        {
            if(listInstrumento[i].isEmpty==OCUPADO)
            {
                printf("\n---------------------------\n");
                 printf("\nID de Instrumento: %d\nNombre: %s",
                listInstrumento[i].idInstrumento,listInstrumento[i].nombre);
                switch(listInstrumento[i].tipo)
                {
                    case 1:
                    printf("\nTipo: Cuerdas");
                    break;
                    case 2:
                    printf("\nTipo: Viento-madera");
                    break;
                    case 3:
                    printf("\nTipo: Viento-metal");
                    break;
                    case 4:
                    printf("\nTipo: Percusión");
                    break;
                }
            }
        }
        ret = 0;
    }
    return ret;
}

int printInstrumentosById(Instrumento *listInstrumento,int lenInstrumento,int id)
{
    int i;
    int ret = -1;
    if(listInstrumento!=NULL && lenInstrumento>0)
    {
        for(i=0; i<lenInstrumento; i++)
        {
            if(listInstrumento[i].isEmpty==OCUPADO)
            {
                if(listInstrumento[i].idInstrumento==id)
                {
                    printf("\n---------------------------\n");
                    printf("\nID de Instrumento: %d\nNombre: %s",
                    listInstrumento[i].idInstrumento,listInstrumento[i].nombre);
                    switch(listInstrumento[i].tipo)
                    {
                        case 1:
                            printf("\nTipo: Cuerdas");
                            break;
                        case 2:
                            printf("\nTipo: Viento-madera");
                            break;
                        case 3:
                            printf("\nTipo: Viento-metal");
                            break;
                        case 4:
                            printf("\nTipo: Percusión");
                            break;
                    }
                    ret = 0;
                }
            }
        }
    }
    return ret;
}


int generarIdInstrumento(void)
{
    static int idMax=1;
    return idMax++;
}
