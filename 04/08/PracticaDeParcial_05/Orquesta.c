#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquesta.h"
#define LIBRE 0
#define OCUPADO 1

int initOrquesta(Orquesta* listOrquesta, int lenOrquesta)
{
    int ret = -1;
    int i;
    if(listOrquesta!=NULL && lenOrquesta>0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            listOrquesta[i].isEmpty=LIBRE;
        }
        ret = 0;
    }

    return ret;
}

int findFreePlace(Orquesta* listOrquesta, int lenOrquesta)
{
    int ret = -1;
    int i;
    if(listOrquesta!=NULL && lenOrquesta>0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            if(listOrquesta[i].isEmpty==LIBRE)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int findOrquestaById(Orquesta* listOrquesta, int lenOrquesta,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listOrquesta!=NULL && lenOrquesta>0 && id>=0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            if(listOrquesta[i].idOrquesta==id && listOrquesta[i].isEmpty==OCUPADO)
            {
                *posicion=i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}


int addOrquesta(Orquesta* listOrquesta, int lenOrquesta, int id, char *name,char *place,int tipo)
{
    int ret = -1;
    int posLibre;

    posLibre= findFreePlace(listOrquesta,lenOrquesta);
    if(listOrquesta!=NULL && lenOrquesta>0)
    {
        if(posLibre!=-1)
        {
            strncpy(listOrquesta[posLibre].nombre,name,50);
            strncpy(listOrquesta[posLibre].lugar,place,50);
            listOrquesta[posLibre].tipo=tipo;
            listOrquesta[posLibre].idOrquesta=id;
            listOrquesta[posLibre].isEmpty=OCUPADO;
        }
        ret = 0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addOrquesta'\n");
    }
    return ret;
}

int registerAnOrquesta(Orquesta *listOrquesta,int lenOrquesta)
{
    char auxName[50];
    char auxPlace[50];
    int auxTipo;
    int auxId;
    int ret = -1;
    if(listOrquesta!=NULL && lenOrquesta>0)
    {
        if(utn_getValidName(auxName)==0 &&
            utn_getValidString("Ingrese lugar: ","\nError, no es un lugar","\nError,excediste el maximo de caracteres.",
            auxPlace,50,2)==0 && utn_getValidInt("Ingrese Tipo\n1-Sinfónica\n2-Filarmónica\n3-Cámara\nIngrese opcion: ",
            "\nERROR, no es una sector.",&auxTipo,1,3,2)==0)
            {
                auxId=generarIdOrquesta();
                addOrquesta(listOrquesta,lenOrquesta,auxId,auxName,auxPlace,auxTipo);
                printf("\n---------------------------\n");
                printf("\nID de Orquesta: %d\nNombre: %s\nLugar: %s",
                auxId,auxName,auxPlace);
                switch(auxTipo)
                {
                    case 1:
                    printf("\nTipo: Sinfónica");
                    break;
                    case 2:
                    printf("\nTipo: Filarmónica");
                    break;
                    case 3:
                    printf("\nTipo: Cámara");
                    break;
                }
                ret=0;

            }
        }
    return ret;
}


int removeOrquesta(Orquesta* listOrquesta, int lenOrquesta,int id)
{
    int retorno=-1;
    int i;
    if(listOrquesta!=NULL && lenOrquesta>0 && id>0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            if(listOrquesta[i].isEmpty==OCUPADO)
            {
                if(listOrquesta[i].idOrquesta==id)
                {
                    listOrquesta[i].isEmpty=LIBRE;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

int printOrquestas(Orquesta *listOrquesta,int lenOrquesta)
{
    int i;
    int ret = -1;
    if(listOrquesta!=NULL && lenOrquesta>0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            if(listOrquesta[i].isEmpty==OCUPADO)
            {
                printf("\n---------------------------\n");
                printf("\nId del Orquesta: %d\nNombre: %s\nLugar: %s",
                       listOrquesta[i].idOrquesta,listOrquesta[i].nombre,listOrquesta[i].lugar);
                       switch(listOrquesta[i].tipo)
                       {
                            case 1:
                            printf("\nTipo: Sinfónica");
                            break;
                            case 2:
                            printf("\nTipo: Filarmónica");
                            break;
                            case 3:
                            printf("\nTipo: Cámara");
                            break;
                       }
            }
        }
        ret = 0;
    }
    return ret;
}

int printOrquestasById(Orquesta *listOrquesta,int lenOrquesta,int id)
{
    int i;
    int ret = -1;
    if(listOrquesta!=NULL && lenOrquesta>0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            if(listOrquesta[i].isEmpty==OCUPADO)
            {
                if(listOrquesta[i].idOrquesta==id)
                {
                    printf("\n---------------------------\n");
                    printf("\nId del Orquesta: %d\nNombre: %s\nLugar: %s",
                    listOrquesta[i].idOrquesta,listOrquesta[i].nombre,listOrquesta[i].lugar);
                        switch(listOrquesta[i].tipo)
                        {
                            case 1:
                            printf("\nTipo: Sinfónica");
                            break;
                            case 2:
                            printf("\nTipo: Filarmónica");
                            break;
                            case 3:
                            printf("\nTipo: Cámara");
                            break;
                        }
                        ret = 0;
                }
            }
        }
    }
    return ret;
}


int generarIdOrquesta(void)
{
    static int idMax=1;
    return idMax++;
}
