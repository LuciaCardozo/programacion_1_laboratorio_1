#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Estructura.h"
#define OCUPADO 1
#define LIBRE 0

int initPersona(Persona *list,int len)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=LIBRE;
        }
    ret = 0;
    }
    return ret;
}

int addPersona(Persona *list,int len,int *id,char *name,int *edad,int *dni)
{
    char auxName[50];
    int auxEdad;
    int auxDni;
    int ret = -1;
    int i;
    if(list!=NULL && id>0 && name!=NULL && edad>0 && dni>0)
    {
        for(i=0;i<len;i++)
        {
            if(utn_getValidName(auxName)==0 &&
                utn_getValidStringNumerico("Ingrese edad: ","ERROR.","ERROR, superaste el largo de caracteres",&auxEdad,120,2)==0 &&
                utn_getValidStringNumerico("Ingrese DNI: ","ERROR.","ERROR, superaste el largo de caracteres",&auxDni,99999999,2)==0)
                {
                    strncpy(name,list[i].nombre,50);
                    list[i].edad=auxEdad;
                    list[i].dni=auxDni;
                    ret = 0;
                }
        }
    }
    return ret;
}
