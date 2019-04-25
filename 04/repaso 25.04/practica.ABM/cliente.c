#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#define CANTIDAD 5
int cliente_initArray(ECliente* list,int limite)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        list[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


int buscarLugarLibre(ECliente* list, int limite)
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

int cliente_alta(ECliente *list, int limite)
{
    char auxName[50];
    char auxApellido[50];
    char auxDni[10];
    int auxId;
    int pos;//posicion

    pos=buscarLugarLibre(list,limite);
    utn_getValidName(auxName);
    utn_getValidLastName(auxApellido);
    utn_getValidStringNumerico("Ingrese su dni: ","Error, no es un dni valido\n","Error, accediste el maximo de caracteres\n",auxDni,10,3);

    utn_getValidInt("ingrese el id: ","Error, eso no es un ID",&auxId,0,99999,3);
    if(!verificarSiExisteElId(list,auxId,limite)==0)
    {
        strncpy(list[pos].nombre,auxName,50);
        strncpy(list[pos].apellido,auxApellido,50);
        strncpy(list[pos].dni,auxDni,10);
        list[pos].idCliente=auxId;
        list[pos].isEmpty=0;
    }
    else{
        printf("El Id Ya Existe");
    }


    //list[pos].precio=precio;
    //list[pos].tipo=tipo;
    //list[pos].idPantalla=50;
    return 0;

}

int verificarSiExisteElId(ECliente * lista,int id, int cantidad)
{
    int retorno=-1;//si no existe
    if(lista != NULL)
    {
        for(int i=0;i<CANTIDAD;i++)
        {
           if(lista[i].idCliente == id)
           {
               return 0;//si ya existe el id retorna 0
           }
        }
    }
   return retorno;
}
