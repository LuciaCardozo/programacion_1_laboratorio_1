#include <stdio.h>
#include <string.h>
#include "Empleado.h"
#define LIBRE 0
#define OCUPADO 1

int EEmpleado_initArray(EEmpleado *pEmpleado, int limite)
{
    int i;
    int retorno=-1;
    if(pEmpleado!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            pEmpleado[i].isEmpty=LIBRE;
        }
        retorno=0;
    }
    return retorno;
}

int EEmpleado_lugarLibreArray(EEmpleado *pEmpleado, int limite)
{
    int i;
    int retorno=-1;
    if(pEmpleado!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(pEmpleado[i].isEmpty==LIBRE)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int EEmpleado_printDebugArray(EEmpleado *pEmpleado, int limite)
{
    int i;
    int retorno=-1;
    if(pEmpleado!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            printf("\n ID: %d -nombre:%s",pEmpleado[i].idEmpleado,pEmpleado[i].name);
            retorno=0;
        }
    }
    return retorno;
}


