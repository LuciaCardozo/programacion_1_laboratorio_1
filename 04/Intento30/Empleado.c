#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "utn.h"


int Empleado_inicializarArray(Empleado* pEmpleado,int limite)
{
    int i;
    for(i=0; i<limite;i++)
    {
        pEmpleado[i].isEmpty=1;
        pEmpleado[i].legajo=-1;
    }
    return 0;
}

int Empleado_mostrarArray(Empleado* pEmpleado,int limite)
{
    int i;
    int flag;
    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==0)
        {
            flag=0;
            printf("Lugar %d:  -   %s %s - Legajo: %d - ID: %d\n",i+1,pEmpleado[i].nombre,pEmpleado[i].apellido,pEmpleado[i].legajo,pEmpleado[i].idEmpleado);
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int Empleado_alta(Empleado* pEmpleado,int limite,int pIndex,int idE,char* msgE)
{
    char bufferName[20];
    char bufferSurname[20];
    char bufferLegajo[20];
    int auxLegajo;
    int retorno=0;
    while(retorno==0)
    {
        if(getStringLetras(bufferName,"\nIngrese Nombre: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferSurname,"\nIngrese Apellido: ",msgE))
        {
            break;
        }
        if(getStringNumeros(bufferLegajo,"\nIngrese Legajo: ",msgE))
        {
            break;
        }
        auxLegajo=atoi(bufferLegajo);
        if(Empleado_findLegajo(pEmpleado,limite,auxLegajo)!=-1)
        {
            printf("\n----El legajo ya existe----\n");
            break;
        }
        strncpy(pEmpleado[pIndex].nombre,bufferName,sizeof(bufferName));
        strncpy(pEmpleado[pIndex].apellido,bufferSurname,sizeof(bufferSurname));
        pEmpleado[pIndex].legajo=auxLegajo;
        pEmpleado[pIndex].isEmpty=0;
        pEmpleado[pIndex].idEmpleado=idE;
        retorno=1;
    }
    return retorno;
}

int Empleado_modifyFromLegajo(Empleado* pEmpleado, int limite,char* msgE)
{
    char bufferLegajo[20];
    char bufferName[20];
    char bufferSurname[20];
    int auxLegajo;
    int posOfLegajo;
    int retorno=0;

    do
    {
        if(getStringNumeros(bufferLegajo,"\nIngrese Legajo a modificar: ",msgE))
        {
            break;
        }
        auxLegajo=atoi(bufferLegajo);
        posOfLegajo=Empleado_findLegajo(pEmpleado,limite,auxLegajo);
        if(posOfLegajo==-1)
        {
            printf("\n----El legajo no existe!----\n");
            break;
        }
        if(getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferSurname,"\nIngrese NUEVO Apellido: ",msgE))
        {
            break;
        }
        strncpy(pEmpleado[posOfLegajo].nombre,bufferName,sizeof(bufferName));
        strncpy(pEmpleado[posOfLegajo].apellido,bufferSurname,sizeof(bufferSurname));
        retorno=1;
    }while(retorno==0);
    return retorno;
}

int Empleado_modifyFromID(Empleado* pEmpleado, int limite,char* msgE)
{
    char bufferID[20];
    char bufferName[20];
    char bufferSurname[20];
    char bufferLegajo[20];
    int auxID;
    int posOfID;
    int auxLegajo;
    int retorno=0;

    do
    {
        if(getStringNumeros(bufferID,"\nIngrese ID: ",msgE))
        {
            break;
        }
        auxID=atoi(bufferID);
        posOfID=Empleado_findID(pEmpleado,limite,auxID);
        if(posOfID==-1)
        {
            printf("\n----El ID no existe!----\n");
            break;
        }
        if(getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferSurname,"\nIngrese NUEVO Apellido: ",msgE))
        {
            break;
        }
           if(getStringNumeros(bufferLegajo,"\nIngrese NUEVO Legajo: ",msgE))
        {
            break;
        }
        auxLegajo=atoi(bufferLegajo);
        if(Empleado_findLegajo(pEmpleado,limite,auxLegajo)!=-1)
        {
            printf("\n----El legajo ya existe----\n");
            break;
        }
        strncpy(pEmpleado[posOfID].nombre,bufferName,sizeof(bufferName));
        strncpy(pEmpleado[posOfID].apellido,bufferSurname,sizeof(bufferSurname));
        pEmpleado[posOfID].legajo=auxLegajo;
        retorno=1;
    }while(retorno==0);
    return retorno;
}

int Empleado_bajaLogica(Empleado* pEmpleado, int limite,char* msgE)
{
    char bufferID[20];
    int auxID;
    int posOfID;
    int retorno=0;

    do
    {
        if(getStringNumeros(bufferID,"\nIngrese ID: ",msgE))
        {
            break;
        }
        auxID=atoi(bufferID);
        posOfID=Empleado_findID(pEmpleado,limite,auxID);
        if(posOfID==-1)
        {
            printf("\n----El ID no existe!----\n");
            break;
        }
        pEmpleado[posOfID].legajo=-1;
        pEmpleado[posOfID].isEmpty=1;
        retorno=1;
    }while(retorno==0);
    return retorno;
}

int Empleado_ordenarNameAtoZ(Empleado* pEmpleado, int limite)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<limite-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<limite;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(strcmp(pEmpleado[i].nombre,pEmpleado[j].nombre)>0)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_ordenarSurnameAtoZ(Empleado* pEmpleado, int limite)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<limite-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<limite;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(strcmp(pEmpleado[i].apellido,pEmpleado[j].apellido)>0)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_orderByLegajo(Empleado* pEmpleado, int limite)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<limite-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<limite;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(pEmpleado[i].legajo>pEmpleado[j].legajo)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_orderByID(Empleado* pEmpleado, int limite)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<limite-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<limite;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(pEmpleado[i].idEmpleado>pEmpleado[j].idEmpleado)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_findLegajo(Empleado* pEmpleado, int limite, int valor)
{
    int i;
    int ret=-1;
    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].legajo==valor)
        {
            ret=i;
        }
    }
    return ret;
}

int Empleado_findID(Empleado* pEmpleado, int limite, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].idEmpleado==idE)
        {
            ret=i;
        }
    }
    return ret;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "utn_strings.h"


int Empleado_inicializarArray(Empleado* pEmpleado,int limite)
{
    int i;
    for(i=0; i<limite;i++)
    {
        pEmpleado[i].isEmpty=1;
        pEmpleado[i].legajo=-1;
    }
    return 0;
}

int Empleado_mostrarArray(Empleado* pEmpleado,int limite)
{
    int i;
    int flag;
    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==0)
        {
            flag=0;
            printf("Lugar %d:  -   %s %s - Legajo: %d - ID: %d\n",i+1,pEmpleado[i].nombre,pEmpleado[i].apellido,pEmpleado[i].legajo,pEmpleado[i].idEmpleado);
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int Empleado_alta(Empleado* pEmpleado,int limite,int pIndex,int idE,char* msgE)
{
    char bufferName[20];
    char bufferSurname[20];
    char bufferLegajo[20];
    int auxLegajo;
    int retorno=0;
    while(retorno==0)
    {
        if(getStringLetras(bufferName,"\nIngrese Nombre: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferSurname,"\nIngrese Apellido: ",msgE))
        {
            break;
        }
        if(getStringNumeros(bufferLegajo,"\nIngrese Legajo: ",msgE))
        {
            break;
        }
        auxLegajo=atoi(bufferLegajo);
        if(Empleado_findLegajo(pEmpleado,limite,auxLegajo)!=-1)
        {
            printf("\n----El legajo ya existe----\n");
            break;
        }
        strncpy(pEmpleado[pIndex].nombre,bufferName,sizeof(bufferName));
        strncpy(pEmpleado[pIndex].apellido,bufferSurname,sizeof(bufferSurname));
        pEmpleado[pIndex].legajo=auxLegajo;
        pEmpleado[pIndex].isEmpty=0;
        pEmpleado[pIndex].idEmpleado=idE;
        retorno=1;
    }
    return retorno;
}

int Empleado_modifyFromLegajo(Empleado* pEmpleado, int limite,char* msgE)
{
    char bufferLegajo[20];
    char bufferName[20];
    char bufferSurname[20];
    int auxLegajo;
    int posOfLegajo;
    int retorno=0;

    do
    {
        if(getStringNumeros(bufferLegajo,"\nIngrese Legajo a modificar: ",msgE))
        {
            break;
        }
        auxLegajo=atoi(bufferLegajo);
        posOfLegajo=Empleado_findLegajo(pEmpleado,limite,auxLegajo);
        if(posOfLegajo==-1)
        {
            printf("\n----El legajo no existe!----\n");
            break;
        }
        if(getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferSurname,"\nIngrese NUEVO Apellido: ",msgE))
        {
            break;
        }
        strncpy(pEmpleado[posOfLegajo].nombre,bufferName,sizeof(bufferName));
        strncpy(pEmpleado[posOfLegajo].apellido,bufferSurname,sizeof(bufferSurname));
        retorno=1;
    }while(retorno==0);
    return retorno;
}

int Empleado_modifyFromID(Empleado* pEmpleado, int limite,char* msgE)
{
    char bufferID[20];
    char bufferName[20];
    char bufferSurname[20];
    char bufferLegajo[20];
    int auxID;
    int posOfID;
    int auxLegajo;
    int retorno=0;

    do
    {
        if(getStringNumeros(bufferID,"\nIngrese ID: ",msgE))
        {
            break;
        }
        auxID=atoi(bufferID);
        posOfID=Empleado_findID(pEmpleado,limite,auxID);
        if(posOfID==-1)
        {
            printf("\n----El ID no existe!----\n");
            break;
        }
        if(getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",msgE))
        {
            break;
        }
        if(getStringLetras(bufferSurname,"\nIngrese NUEVO Apellido: ",msgE))
        {
            break;
        }
           if(getStringNumeros(bufferLegajo,"\nIngrese NUEVO Legajo: ",msgE))
        {
            break;
        }
        auxLegajo=atoi(bufferLegajo);
        if(Empleado_findLegajo(pEmpleado,limite,auxLegajo)!=-1)
        {
            printf("\n----El legajo ya existe----\n");
            break;
        }
        strncpy(pEmpleado[posOfID].nombre,bufferName,sizeof(bufferName));
        strncpy(pEmpleado[posOfID].apellido,bufferSurname,sizeof(bufferSurname));
        pEmpleado[posOfID].legajo=auxLegajo;
        retorno=1;
    }while(retorno==0);
    return retorno;
}

int Empleado_bajaLogica(Empleado* pEmpleado, int limite,char* msgE)
{
    char bufferID[20];
    int auxID;
    int posOfID;
    int retorno=0;

    do
    {
        if(getStringNumeros(bufferID,"\nIngrese ID: ",msgE))
        {
            break;
        }
        auxID=atoi(bufferID);
        posOfID=Empleado_findID(pEmpleado,limite,auxID);
        if(posOfID==-1)
        {
            printf("\n----El ID no existe!----\n");
            break;
        }
        pEmpleado[posOfID].legajo=-1;
        pEmpleado[posOfID].isEmpty=1;
        retorno=1;
    }while(retorno==0);
    return retorno;
}

int Empleado_ordenarNameAtoZ(Empleado* pEmpleado, int limite)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<limite-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<limite;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(strcmp(pEmpleado[i].nombre,pEmpleado[j].nombre)>0)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_ordenarSurnameAtoZ(Empleado* pEmpleado, int limite)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<limite-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<limite;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(strcmp(pEmpleado[i].apellido,pEmpleado[j].apellido)>0)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_orderByLegajo(Empleado* pEmpleado, int limite)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<limite-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<limite;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(pEmpleado[i].legajo>pEmpleado[j].legajo)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_orderByID(Empleado* pEmpleado, int limite)
{
    int i;
    int j;
    Empleado buffer;
    for(i=0;i<limite-1;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<limite;j++)
        {
            if(pEmpleado[j].isEmpty==1)
            {
                continue;
            }
            if(pEmpleado[i].idEmpleado>pEmpleado[j].idEmpleado)
            {
                buffer=pEmpleado[i];
                pEmpleado[i]=pEmpleado[j];
                pEmpleado[j]=buffer;
            }
        }
    }
    return 0;
}

int Empleado_findLegajo(Empleado* pEmpleado, int limite, int valor)
{
    int i;
    int ret=-1;
    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].legajo==valor)
        {
            ret=i;
        }
    }
    return ret;
}

int Empleado_findID(Empleado* pEmpleado, int limite, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].idEmpleado==idE)
        {
            ret=i;
        }
    }
    return ret;
}

int Empleado_posLibre(Empleado* pEmpleado, int limite)
{
    int i;
    int ret=-1;
    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
int Empleado_posLibre(Empleado* pEmpleado, int limite)
{
    int i;
    int ret=-1;
    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
