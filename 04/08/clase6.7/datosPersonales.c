#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"

int dat_addPersona(Datos *list,int len,char *name,char *lastName,Direccion *listDir,char *adress,int number)
{
    int i;
    int ret = -1;
    char auxNom[20];
    char auxApel[20];
    char auxDir[20];
    int auxNum;
    if(list!=NULL && len>0 && name!=NULL && lastName!=NULL && listDir!=NULL && adress!=NULL && number>0)
    {
        for(i=0;i<len;i++)
        {
            if(utn_getValidName(auxNom)==0 && utn_getValidLastName(auxApel)==0 &&
                utn_getValidName(auxDir)==0)
        }
    }
}
