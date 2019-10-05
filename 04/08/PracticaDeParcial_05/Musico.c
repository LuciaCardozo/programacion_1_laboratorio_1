#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utn.h"
#include "Musico.h"
#define OCUPADO 1
#define LIBRE 0
int initMusicos(Musico* listMusico, int lenMusico)
{
    int ret = -1;
    int i;
    if(listMusico!=NULL && lenMusico>0)
    {
        for(i=0; i<lenMusico; i++)
        {
            listMusico[i].isEmpty=LIBRE;
        }
        ret = 0;
    }

    return ret;
}

int findFreePlaceMusico(Musico* listMusico, int lenMusico)
{
    int ret = -1;
    int i;
    if(listMusico!=NULL && lenMusico>0)
    {
        for(i=0; i<lenMusico; i++)
        {
            if(listMusico[i].isEmpty==LIBRE)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int findMusicoById(Musico* listMusico, int lenMusico,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listMusico!=NULL && lenMusico>0 && id>=0)
    {
        for(i=0; i<lenMusico; i++)
        {
            if(listMusico[i].idMusico==id && listMusico[i].isEmpty==OCUPADO)
            {
                *posicion=i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}


int addMusico(Musico* listMusico, int lenMusico, int id, char *name,char *lastName,int edad)
{
    int ret = -1;
    int posLibre;

    posLibre= findFreePlaceMusico(listMusico,lenMusico);
    if(listMusico!=NULL && lenMusico>0)
    {
        if(posLibre!=-1)
        {
            strncpy(listMusico[posLibre].nombre,name,50);
            strncpy(listMusico[posLibre].apellido,lastName,50);
            listMusico[posLibre].edad=edad;
            listMusico[posLibre].idMusico=id;
            listMusico[posLibre].isEmpty=OCUPADO;
        }
        ret = 0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addMusico'\n");
    }
    return ret;
}

int registerAnMusico(Musico *listMusico,int lenMusico)
{
    char auxName[50];
    char auxLastName[50];
    int auxEdad;
    int auxId;
    int ret = -1;
    if(listMusico!=NULL && lenMusico>0)
    {
        if(utn_getValidName(auxName)==0 && utn_getValidLastName(auxLastName)==0 &&
            utn_getValidInt("Ingrese Edad: ","\nERROR, no es una Edad.",&auxEdad,0,130,2)==0)
            {
                auxId=generarIdMusico();
                addMusico(listMusico,lenMusico,auxId,auxName,auxLastName,auxEdad);
                printf("\n---------------------------\n");
                printf("\nID de Musico: %d\nNombre: %s\nApellido: %s\nEdad: %d\n",
                auxId,auxName,auxLastName,auxEdad);
                ret=0;
            }
        }
    return ret;
}

int modifyAnMusico(Musico *listMusico,int lenMusico)
{
    int ret=-1;
    int auxEdad;
    /*int auxIdInstrumento;*/
    int auxId;
    int auxPos;
    int opciones;
    if(listMusico!=NULL && lenMusico>0)
    {
        if(utn_getValidInt("\nIngrese el id: ","\nError, repuesta incorrecta.",&auxId,1,99999,2)==0)
        {

            if(findMusicoById(listMusico,lenMusico,auxId,&auxPos)==-1)
            {
                printf("\nError, no se encontro Id");
            }
            else
            {
                do
                {
                    if(utn_getValidInt("\n\nQue desea modificar?\n1-Edad\n2-Id de Instrumento\n3-Salir\nIngrese opcion: ",
                                        "Error",&opciones,1,3,3)==0)
                    {

                        switch(opciones)
                        {
                            case 1:
                                utn_getValidInt("\nIngrese nuevo Edad: ","\nError",&auxEdad,0,130,2);
                                listMusico[auxPos].edad=auxEdad;
                                break;
                            case 2:
                                printf("\n......Falta id de instrumento......");
                                break;
                            case 3:
                                break;
                            default:
                                printf("\nError, No es una opcion");
                                break;
                        }
                        ret=0;
                    }
                }while(opciones!=3);
            }
        }
    }
    return ret;
}


int removeMusico(Musico* listMusico, int lenMusico,int id)
{
    int retorno=-1;
    int i;
    if(listMusico!=NULL && lenMusico>0 && id>0)
    {
        for(i=0; i<lenMusico; i++)
        {
            if(listMusico[i].idMusico==id)
            {
                listMusico[i].isEmpty=LIBRE;
                retorno=0;
            }
        }
    }
    return retorno;
}

int printMusicos(Musico *listMusico,int lenMusico)
{
    int i;
    int ret = -1;
    if(listMusico!=NULL && lenMusico>0)
    {
        for(i=0; i<lenMusico; i++)
        {
            if(listMusico[i].isEmpty==OCUPADO)
            {
                printf("\n---------------------------\n");
                printf("\nId del Musico: %d\nNombre: %s\nApellido: %s\nEdad: %d\n",
                       listMusico[i].idMusico,listMusico[i].nombre,listMusico[i].apellido,listMusico[i].edad);
            }
        }
        ret = 0;
    }
    return ret;
}

int printMusicosById(Musico *listMusico,int lenMusico,int id)
{
    int i;
    int ret = -1;
    if(listMusico!=NULL && lenMusico>0)
    {
        for(i=0; i<lenMusico; i++)
        {
            if(listMusico[i].isEmpty==OCUPADO)
            {
                if(listMusico[i].idMusico==id)
                {
                    printf("\n---------------------------\n");
                    printf("\nId del Empleado: %d\nNombre: %s\nApellido: %s\nEdad: %d\n",
                           listMusico[i].idMusico,listMusico[i].nombre,listMusico[i].apellido,listMusico[i].edad);
                           ret = 0;
                }
            }
        }
    }
    return ret;
}


int generarIdMusico(void)
{
    static int idMax=1;
    return idMax++;
}
