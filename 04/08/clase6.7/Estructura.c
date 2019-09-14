#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "Estructura.h"
#define OCUPADO 1
#define LIBRE 0
static int generarId(void);

int initPersona(Persona *list,int len)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=OCUPADO;
        }
    ret = 0;
    }
    return ret;
}

int buscarLugarLibre(Persona *list,int len)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].id==OCUPADO)
            {
                ret=i;
            }
        }
    }
    return ret;
}

int addPersona(Persona *list,int len,char *name,int *edad,char *dni)
{
    char auxName[50];
    int auxEdad;
    char auxDni[50];
    int ret = -1;
    int i;
    if(list!=NULL && name!=NULL && edad>0 && dni>0)
    {
        for(i=0;i<len;i++)
        {
            if(utn_getValidName(auxName)==0 &&
                utn_getValidInt("Ingrese edad: ","\nERROR, no es una edad.",&auxEdad,0,130,2)==0 &&
                utn_getValidStringNumerico("Ingrese Dni: ","\nError.","\nError, superaste el largo de caracteres.\n",auxDni,8,2)==0)
                {
                    strncpy(list[i].nombre,auxName,50);
                    list[i].edad=auxEdad;
                    strncpy(dni,auxDni,50);
                    list[i].id=generarId();
                    ret = 0;
                }
        }
    }
    return ret;
}

int printfPersonas(Persona *list,int len,char *name,int *edad,char *dni)
{
    int ret=-1;
    int i;
    if(list!=NULL && len>0 && name!=NULL && edad>0 && dni!=NULL)
    {
        for(i=0;i<len;i++)
        {
            printf("\nNombre: %s",list[i].nombre);
            printf("\nEdad: %d",list[i].edad);
            printf("\nDni: %s",list[i].dni);
            printf("\nId: %d\n",list[i].id);
            printf("\n----------------\n");
        }
    }
    return ret;
}

int ordenarPorEdad(Persona *list,int len)
{
    int ret = -1;
    char aux[50];
    int auxInt;
    int i,j;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(list[i].edad>list[j].edad)
                {
                    auxInt=list[i].edad;
                    list[i].edad=list[j].edad;
                    list[j].edad=auxInt;

                    strncpy(aux,list[i].nombre,50); /*aux=list[i].nombre....nombre,edad,dni*/
                    strncpy(list[i].nombre,list[j].nombre,50);
                    strncpy(list[j].nombre,aux,50);

                    strcpy(aux,list[i].dni);
                    strcpy(list[i].dni,list[j].dni);
                    strcpy(list[j].dni,aux);

                    auxInt=list[i].id;
                    list[i].id=list[j].id;
                    list[j].id=auxInt;
                }
            }
        }
        ret = 0;
    }
    return ret;
}

static int generarId(void)
{
    static int idMax=0;
    return idMax++;
}
