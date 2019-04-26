#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
static int generarId(void);

int pan_initArray(Pantalla *list, int limite)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        list[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int pan_buscarLugarLibre(Pantalla *list, int limite)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(list[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


int pan_alta(Pantalla *list, int limite)
{
    char auxName[50];
    char auxDireccion[50];
    float auxPrecio;
    int tipo;
    int pos;//posicion

    pos=pan_buscarLugarLibre(list,limite);
    utn_getValidName(auxName);
    utn_getValidStringAlfaNumerico("Ingrese Direccion: ","Error, no es una direccion","Error, accediste el maximo de caracteres",auxDireccion,50,3);
    utn_getValidInt("1_LCD\n2_LED\n","No Ingreso ni 1 ni 2, Error\n",&tipo,1,2,3);
    utn_getValidFloat("Ingrese Precio: ","Error no es un precio",&auxPrecio,0,100000,3);

        strncpy(list[pos].nombre,auxName,50);
        strncpy(list[pos].direccion,auxDireccion,50);
        list[pos].precio=auxPrecio;
        list[pos].tipo=tipo;
        list[pos].idPantalla=generarId();
        list[pos].isEmpty=0;
    //list[pos].precio=precio;
    //list[pos].tipo=tipo;
    //list[pos].idPantalla=50;
    return 0;

}

int verificarSiExisteElId(Pantalla * list,int id, int limite)
{
    int retorno=-1;//si no existe
    if(list != NULL)
    {
        for(int i=0;i<limite;i++)
        {
           if(list[i].idPantalla == id)
           {
               return 0;//si ya existe el id retorna 0
           }
        }
    }
   return retorno;
}

/*int pan_printDebugArray(Pantalla *list, int limite)
{
    int i;
    int retorno=-1;
    if(list!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            printf("\n ID: %d -nombre:%s",list[i].idPantalla,list[i].nombre);
            retorno=0;
        }
    }
    return retorno;
}*/
int pan_printArray(Pantalla* list,int limite)
{
    int i;
    int flag;
    for(i=0;i<limite;i++)
    {
        if(list[i].isEmpty==0)
        {
            flag=0;
            printf("Lugar %d:  -   %s %s - Tipo: %d - Precio: %f - ID: %d\n",i+1,list[i].nombre,list[i].direccion,list[i].tipo,list[i].precio,list[i].idPantalla);
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

/*int opcionesMenu()
{
    int retorno;
    int respuesta;
    printf("\n1-Alta de pantalla \n");
    printf("-------------------------------------------\n");
    printf("2-Mostrar datos ingresados\n");
    printf("-------------------------------------------\n");
    printf("3-Modificar datos de pantalla\n");
    printf("-------------------------------------------\n");
    printf("4-Baja de pantalla\n");
    printf("-------------------------------------------\n");
    printf("5-generar archivo de reparto\n");
    printf("-------------------------------------------\n");
    printf("6-salir\n");
    printf("-------------------------------------------\n");
    fflush(stdin);
    scanf("%d",&respuesta);
    if(respuesta>0 && respuesta<6)
    {
        retorno=respuesta;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}*/

int pan_modificarId(Pantalla* list, int limite)
{
    char bufferNombre[50];
    char bufferDireccion[50];
    char bufferId;
    float auxPrecio;
    int auxId;
    int pos;
    int auxTipo;
    int retorno=0;

    do
    {
        if(utn_getValidStringNumerico("Ingrese el nuevo nombre","Error, no es un id","Error, excediste el maximo de caracteres",&bufferId,999999,3))
        {
            break;
        }
        auxId=bufferId;
        pos=verificarSiExisteElId(list,auxId,limite);
        if(pos==-1)
        {
            printf("\n----El ID no existe!----\n");
            break;
        }
        if(utn_getValidString("Ingrese el nuevo nombre","Error, no es un nombre","Error, excediste el maximo de caracteres",bufferNombre,50,3))
        {
            break;
        }
        if(utn_getValidString("Ingrese la nueva direccion","Error, no es un nombre","Error, excediste el maximo de caracteres",bufferDireccion,50,3))
        {
            break;
        }
           if(utn_getValidFloat("Ingrese el nuevo precio","Error, no es un nombre",&auxPrecio,0,999999,3))
        {
            break;
        }
        if(utn_getValidInt("1_LCD\n2_LED\n","No Ingreso ni 1 ni 2, Error\n",&auxTipo,1,2,3))
        {
            break;
        }
        strncpy(list[pos].nombre,bufferNombre,50);
        strncpy(list[pos].direccion,bufferDireccion,50);
        list[pos].precio=auxPrecio;
        list[pos].tipo=auxTipo;
        retorno=1;
    }while(retorno==0);
    return retorno;
}

/*int pan_bajaLogica(Pantalla* pPantalla, int len,char* msgE)
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
        posOfID=pan_findID(pPantalla,len,auxID);
        if(posOfID==-1)
        {
            printf("\n----El ID no existe!----\n");
            break;
        }
        pPantalla[posOfID].isEmpty=1;
        retorno=1;
    }while(retorno==0);
    return retorno;
}*/

static int generarId(void)
{
    static int idMax=0;
    return idMax++;
}
