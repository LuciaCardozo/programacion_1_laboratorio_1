#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#define LIBRE 0
#define OCUPADO 1

static int generarId(void);

int pub_initPublicidad(Publicidad *list,int len)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty=LIBRE;
        }
        ret = 0;
    }
    return ret;
}

int pub_buscarLugarLibre(Publicidad *list,int len)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==LIBRE)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

int pub_addPublicidad(Publicidad *list, int len, int idPub,int idPantalla,int cantDeDia,char *cuit,char *nombre)
{
    int retorno=-1;
    int posLibre;

    posLibre=pub_buscarLugarLibre(list,len);
    if(list!=NULL && len>0)
    {
        if(posLibre!=-1)
        {
            list[posLibre].cantidadDeDia=cantDeDia;
            strncpy(list[posLibre].cuit,cuit,20);
            strncpy(list[posLibre].nombreArch,nombre,50);
            list[posLibre].idPan=idPantalla;
            list[posLibre].isEmpty=OCUPADO;
            list[posLibre].idPub=idPub;
        }
        retorno=0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addPersona'\n");
    }
    return retorno;
}

int pub_altaPublicidad(Publicidad *list,int len,Pantalla *listPan,int lenPan)
{
    char auxNombre[50];
    char auxCuit[20];
    int auxCantDeDia;
    int auxId;
    int auxIdPan;
    int PosIdPan;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        if(utn_getValidInt("Ingrese Id pantalla: ","Error.",&auxIdPan,1,1000,2)==0)
        {
            if(pan_buscarPantallaPorId(listPan,lenPan,auxIdPan,&posIdPan)==-1)
            {
                printf("No se encontro ID Pantalla");
            }
            else
            {
                if(utn_getValidString("Ingrese Cuit:","\nError.","Error, excediste el maximo de caracteres",auxCuit,12,2)==0 &&
                utn_getValidName(auxNombre)==0 && utn_getValidInt("Ingrese cantidad de dias: ","\nError.",&auxCantDeDia,1,99999,2)==0)
                {
                    auxId=generarId();
                    pub_addPublicidad(list,len,idPub,idPan,auxCantDeDia,auxCuit,auxNombre);
                    printf("\n------------------------\n");
                    printf("\nID de Pantalla: %d\nId Publicidad: %d\nNombre: %s\nCuit: %s\Cantidad de dias: %d\n",
                           auxIdPan,auxId,auxNombre,auxCuit,auxCantDeDia);
                    ret=0;

                }
            }
        }

    }
    return ret;
}

int pub_printfPublicidad(Publicidad *list,int len,Pantalla *listPan,int lenPan)
{
    int ret=-1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {
                pan_printfPantalla(listPan,lenPan);
                printf("\nId Publicidad: %d\n",list[i].idPub);
                printf("\nNombre: %s",list[i].nombre);
                printf("\nNombre: %s",list[i].cuit);
                printf("\nPrecio: %.2f",list[i].cantidadDeDia);
                if(list[i].tipo==1)
                {
                    printf("\nTipo: LED");
                }
                else if(list[i].tipo==2)
                {
                    printf("\nTipo: LCD");
                }
                printf("\n------------------------\n");
            }
        }
        ret=0;
    }
    return ret;
}

int pub_buscarPublicidadPorId(Publicidad *list,int len,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idPub==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}

int pan_bajaPantalla(Pantalla *list,int len,int id,Pantalla *listPan,int lenPan)/*falta baj publicidad*/
{
    int i;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idPub==id)
            {
                list[i].isEmpty=LIBRE;
            }
        }
        ret=0;
    }
    return ret;
}

int pub_modificarPublicacion(Publicacion *list, int len,int id)
{
    int ret = -1;
    char auxNombre[50];
    char auxCuit[50];
    float auxCantDeDia;
    int opciones;
    int auxId;
    int auxPos;
    if(utn_getValidString("Ingrese Cuit: ",char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)==0)
    {
        if(pan_buscarPantallaPorId(list,len,auxId,&auxPos)==-1)
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
                        strncpy(list[auxPos].nombre,auxNombre,50);
                        printf("%s-------------------------\n",list[auxPos].nombre);
                        break;
                    case 2:
                        utn_getValidStringAlfaNumerico("Ingrese direccion: ","\nError.","\nError, excediste el maximo de caracteres.",auxDireccion,50,2);
                        strncpy(list[auxPos].direccion,auxDireccion,50);
                        printf("%s-------------------------\n",list[auxPos].direccion);
                        break;
                    case 3:
                        utn_getValidFloat("Ingrese Precio: ","\nError.",&auxPrecio,0,99999,2);
                        list[auxPos].precio=auxPrecio;
                        break;
                    case 4:
                        utn_getValidInt("\nTipo de Pantalla\n1.LED\n2.LCD\nIngrese opcion:  ","\nError",&auxTipo,1,130,3);
                        list[auxPos].tipo=auxTipo;
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
