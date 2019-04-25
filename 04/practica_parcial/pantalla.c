#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"

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

/*int pan_idAutoIncremental(int limite)
{
    int i;
    int id;
    for(i=1;i<limite;i++)
    {
        id=limite*i;
    }
}*/

int pan_alta(Pantalla *list, int limite)
{
    char name[50];
    char direccion[50];
    float precio;
    int tipo;
    int pos;//posicion
    pos=pan_buscarLugarLibre(list,limite);
    utn_getValidName(name);
    utn_getValidStringAlfaNumerico("Ingrese Direccion: ","Error, no es una direccion","Error, accediste el maximo de caracteres",direccion,50,3);
    utn_getValidFloat("Ingrese Precio: ","Error no es un precio",&precio,0,100000,3);

    utn_getValidInt("1_LCD\n2_LED\n","No Ingreso ni 1 ni 2, Error",&tipo,1,2,1);
    strncpy(list[pos].nombre,name,50);
    strncpy(list[pos].direccion,direccion,50);
    list[pos].precio=precio;
    list[pos].tipo=tipo;
    list[pos].idPantalla=50;
    return 0;

}

