#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#define LIBRE 0
#define OCUPADO 1

static int generarId(void);

int pan_initPantalla(Pantalla *listPan,int lenPan)
{
    int ret = -1;
    int i;
    if(listPan!=NULL && lenPan>0)
    {
        for(i=0; i<lenPan; i++)
        {
            listPan[i].isEmpty=LIBRE;
        }
        ret = 0;
    }
    return ret;
}

int pan_buscarLugarLibre(Pantalla *listPan,int lenPan)
{
    int ret = -1;
    int i;
    if(listPan!=NULL && lenPan>0)
    {
        for(i=0; i<lenPan; i++)
        {
            if(listPan[i].isEmpty==LIBRE)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

int pan_addPantalla(Pantalla *listPan, int lenPan, int idPan, char *name,char *adress,float precio,int tipo)
{
    int retorno=-1;
    int posLibre;

    posLibre=pan_buscarLugarLibre(listPan,lenPan);
    if(listPan!=NULL && lenPan>0)
    {
        if(posLibre!=-1)
        {
            strncpy(listPan[posLibre].nombre,name,50);
            strncpy(listPan[posLibre].direccion,adress,50);
            listPan[posLibre].tipo=tipo;
            listPan[posLibre].precio=precio;
            listPan[posLibre].isEmpty=OCUPADO;
            listPan[posLibre].idPan=idPan;
        }
        retorno=0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addPersona'\n");
    }
    return retorno;
}

int pan_altaPantalla(Pantalla *listPan,int lenPan)
{
    char auxNombre[50];
    char auxDireccion[50];
    int auxTipo;
    float auxPrecio;
    int auxId;
    int ret = -1;
    if(listPan!=NULL && lenPan>0)
    {
        if(utn_getValidName(auxNombre)==0 &&
            utn_getValidStringAlfaNumerico("Ingrese direccion: ","\nError.","\nError, excediste el maximo de caracteres.",auxDireccion,50,2)==0 &&
            utn_getValidFloat("Ingrese Precio: ","\nError.",&auxPrecio,0,99999,2)==0 &&
            utn_getValidInt("Tipo de pantalla\n1.LED\n2.LCD\nIngrese opcion: ","\nERROR, un tipo de pantalla.",&auxTipo,1,2,2)==0)
        {
            auxId=generarId();
            pan_addPantalla(listPan,lenPan,auxId,auxNombre,auxDireccion,auxPrecio,auxTipo);
            printf("\n------------------------\n");
            printf("\nID de Pantalla: %d\nNombre: %s\nDireccion: %s\nPrecio: %.2f\n",
                   auxId,auxNombre,auxDireccion,auxPrecio);
                if(auxTipo==1)
                {
                    printf("Tipo: LED");
                }
                else if(auxTipo==2)
                {
                    printf("Tipo: LCD");
                }
            ret=0;

        }
    }
    return ret;
}

int pan_printfPantalla(Pantalla *listPan,int lenPan)
{
    int ret=-1;
    int i;
    if(listPan!=NULL && lenPan>0)
    {
        for(i=0; i<lenPan; i++)
        {
            if(listPan[i].isEmpty==OCUPADO)
            {
                printf("\nId Pantalla: %d\n",listPan[i].idPan);
                printf("\nNombre: %s",listPan[i].nombre);
                printf("\nNombre: %s",listPan[i].direccion);
                printf("\nPrecio: %.2f",listPan[i].precio);
                if(listPan[i].tipo==1)
                {
                    printf("\nTipo: LED");
                }
                else if(listPan[i].tipo==2)
                {
                    printf("\nTipo: LCD");
                }
                printf("\n------------------------\n");
                ret=0;
            }
        }
    }
    return ret;
}

int pan_printfPantallaPorId(Pantalla *listPan,int lenPan,int id)
{
    int ret=-1;
    int i;
    if(listPan!=NULL && lenPan>0)
    {
        for(i=0; i<lenPan; i++)
        {
            if(listPan[i].isEmpty==OCUPADO)
            {
                if(listPan[i].idPan==id)
                {
                    printf("\nId Pantalla: %d\n",listPan[i].idPan);
                    printf("\nNombre: %s",listPan[i].nombre);
                    printf("\nNombre: %s",listPan[i].direccion);
                    printf("\nPrecio: %.2f",listPan[i].precio);
                    if(listPan[i].tipo==1)
                    {
                        printf("\nTipo: LED");
                    }
                    else if(listPan[i].tipo==2)
                    {
                        printf("\nTipo: LCD");
                    }
                    ret=0;
                }
            }
        }
    }
    return ret;
}

int pan_buscarPantallaPorId(Pantalla *listPan,int lenPan,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listPan!=NULL && lenPan>0)
    {
        for(i=0; i<lenPan; i++)
        {
            if(listPan[i].idPan==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}

int pan_bajaPantalla(Pantalla *listPan,int lenPan,int id)/*falta baj publicidad*/
{
    int i;
    int ret = -1;
    if(listPan!=NULL && lenPan>0)
    {
        for(i=0; i<lenPan; i++)
        {
            if(listPan[i].idPan==id)
            {
                listPan[i].isEmpty=LIBRE;
            }
        }
        ret=0;
    }
    return ret;
}

int pan_modificarPantalla(Pantalla *listPan, int lenPan,int id)
{
    int ret = -1;
    char auxNombre[50];
    char auxDireccion[50];
    float auxPrecio;
    int auxTipo;
    int opciones;
    int auxId;
    int auxPos;
    if(utn_getValidInt("\nIngrese el id: ","\nError, repuesta incorrecta.",&auxId,1,99999,2)==0)
    {
        if(pan_buscarPantallaPorId(listPan,lenPan,auxId,&auxPos)==-1)
        {
            printf("\nNo se encontro el ID");
        }
        else
        {
            do
            {
                if(utn_getValidInt("\n\n¿Que desea modificar?\n1-Nombre\n2-Direccion\n3-Precio\n4-Tipo\n5-Cancelar\nEliga la opcion: ",
                                   "Error",&opciones,1,5,2)==0)
                {
                    switch(opciones)
                    {
                    case 1:
                        utn_getValidString("\nIngrese nuevo nombre: ","\nError","\nError, excediste el maximo de caracteres.",auxNombre,50,2);
                        strncpy(listPan[auxPos].nombre,auxNombre,50);
                        printf("%s-------------------------\n",listPan[auxPos].nombre);
                        break;
                    case 2:
                        utn_getValidStringAlfaNumerico("Ingrese direccion: ","\nError.","\nError, excediste el maximo de caracteres.",auxDireccion,50,2);
                        strncpy(listPan[auxPos].direccion,auxDireccion,50);
                        printf("%s-------------------------\n",listPan[auxPos].direccion);
                        break;
                    case 3:
                        utn_getValidFloat("Ingrese Precio: ","\nError.",&auxPrecio,0,99999,2);
                        listPan[auxPos].precio=auxPrecio;
                        break;
                    case 4:
                        utn_getValidInt("\nTipo de Pantalla\n1.LED\n2.LCD\nIngrese opcion:  ","\nError",&auxTipo,1,130,3);
                        listPan[auxPos].tipo=auxTipo;
                        break;
                    case 5:
                        break;
                    default :
                        printf("No es una opcion");
                        break;
                    }
                }
            }while(opciones!=5);
        }

        ret=0;
    }
    return ret;
}


static int generarId(void)
{
    static int idMax=1;
    return idMax++;
}
