#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#define LIBRE 0
#define OCUPADO 1

int pan_initArray(Pantalla* list, int limite)
{
    int retorno=-1;
    int i;
    if(list != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            list[i].isEmpty=LIBRE;
            retorno=0;
        }
    }
    return retorno;
}

int pan_buscarLugarLibre(Pantalla* list, int limite)
{
    int retorno=-1;
    int i;
    for(i=0; i<limite; i++)
    {
        if(list[i].isEmpty==LIBRE)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int generadorId(void)
{
    static int idMax=1;
    return idMax++;
}

int pan_altaPantalla(Pantalla* list, int limite)
{
    int retorno=-1;
    char auxNombre[51];
    char auxDireccion[51];
    float auxPrecio;
    int auxTipo;
    int pos;
    if( (utn_getValidName(auxNombre)==0) && (utn_getValidStringAlfaNumerico("Ingrese su direccion: ","Error, no es una opcion","Error, excediste el maximo de caracteres",auxDireccion,999999,3)==0)
            && (utn_getValidFloat("Ingrese el precio: ","Error, la repuesta no es valida",&auxPrecio,0,999999,3)==0)
            && (utn_getValidInt("Elija el tipo de pantalla\n\n1-LED\n2-LCD\n","Error, no es una opcion valida",&auxTipo,1,2,3)==0) )
    {
        pos=pan_buscarLugarLibre(list,limite);
        if(pos!=-1)
        {
            strncpy(list[pos].nombre,auxNombre,51);
            strncpy(list[pos].direccion,auxDireccion,51);
            list[pos].precio=auxPrecio;
            list[pos].tipo=auxTipo;
            list[pos].isEmpty=OCUPADO;
            list[pos].idPantalla=generadorId();
        }
    }
    return retorno;
}

int pan_printPantalla(Pantalla* list,int limite)
{
    int retorno=-1;
    int i;
    char auxTipo[20];
    if(list != NULL && limite>0)
    {

<<<<<<< HEAD
        for(i=0; i<limite; i++)//probar (i<limite-1) por lo que vi es valido
=======
        for(i=0; i<limite; i++)
>>>>>>> 463b014750cc2ac42752d0b40f96e91a3bb73c28
        {
            if(list[i].isEmpty==OCUPADO)
            {
                if(list[i].tipo==1)
                {
                    strncpy(auxTipo,"LED",20);
                }
                else
                {
                    strncpy(auxTipo,"LCD",20);
                }
                printf("\nNombre: %s \nDireccion: %s \nPrecio: %f\nTipo: %s\nID: %d",list[i].nombre,list[i].direccion,
                       list[i].precio,auxTipo,list[i].idPantalla);
                retorno=0;
            }
        }
    }
    return retorno;
}
int obtenerListaFiltrada(Pantalla* list,Pantalla* auxList, int limite, char* nombre)
{

    int retorno=-1;
    int i;
    int contadorAuxList=1;
    if(list != NULL && auxList != NULL && limite>0 && nombre !=NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(strncmp(list[i].nombre,nombre,51)==0)
            {
                auxList[contadorAuxList]=list[i];
                contadorAuxList++;
            }
        }
    }
    return retorno;
}

int pan_bajaPantalla(Pantalla* list, int limite)
{
    Pantalla auxList[limite];
    int retorno=-1;
    char auxName[51];
    int auxId;
    int indicePantallaABorrar;
    utn_getValidString("Ingrese el nombre","Error","Error, excediste el maximo de caracteres",auxName,51,3);
    obtenerListaFiltrada(list,auxList,limite,auxName);
    pan_printPantalla(auxList,(limite-1));
    if(utn_getValidInt("Ingrese el id: ","Error, repuesta incorrecta",&auxId,1,1001,3)==0)
        indicePantallaABorrar=pan_buscarEmpleadoPorId(list,limite,auxId);

    list[indicePantallaABorrar].isEmpty=LIBRE;

    return retorno;
}

int pan_buscarEmpleadoPorId(Pantalla* list, int limite,int idE)
{
    int retorno=-1;
    int i;
    for(i=0; i<limite; i++)
    {
        if(list[i].idPantalla==idE)
        {
            retorno=i;
        }
    }
    return retorno;
}
<<<<<<< HEAD

int pan_modificarPantalla(Pantalla* list, int limite)
{
    Pantalla auxList[limite];
    int  retorno=-1;
    char auxName[51];
    char nuevoNombre[51];
    char nuevaDireccion[51];
    int  nuevotipo;
    int  auxId;
    int  indicePantallaAModificar;
    utn_getValidString("Ingrese el nombre: ","Error","Error, excediste el maximo de caracteres",auxName,51,3);
    obtenerListaFiltrada(list,auxList,limite,auxName);
    pan_printPantalla(auxList,(limite-1));//probar con un for (i<limite-1)
    if(utn_getValidInt("\nIngrese el id: ","Error, repuesta incorrecta",&auxId,1,1001,3)==0)
    {
        indicePantallaAModificar=pan_buscarEmpleadoPorId(list,limite,auxId);
        if(utn_getValidInt("1-Modificar nombre\n2-Modificar direccion\n3-Tipo de pantalla\nIngrese opcion: ",
                           "Error",&indicePantallaAModificar,1,3,3))
        {
            switch(indicePantallaAModificar)
            {
                case 1:
                utn_getValidString("Ingrese nuevo nombre: ","Error","Error, excediste el maximo de caracteres",nuevoNombre,51,3);
                //strncpy(list[])
                break;
            }
        }
    }
    retorno=0;
    //if(indicePantallaAModificar)

    return retorno;
}

int pan_orderID(Pantalla* list, int limite)
{
    int i;
    int j;
    Pantalla buffer;
    for(i=0;i<limite-1;i++)
    {
        if(list[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<limite;j++)
        {
            if(list[j].isEmpty==1)
            {
                continue;
            }
            if(list[i].idPantalla>list[j].idPantalla)
            {
                buffer=list[i];
                list[i]=list[j];
                list[j]=buffer;
            }
        }
    }
    return 0;
}
=======
>>>>>>> 463b014750cc2ac42752d0b40f96e91a3bb73c28
