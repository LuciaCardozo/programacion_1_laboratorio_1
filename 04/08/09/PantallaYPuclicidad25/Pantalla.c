#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#define LIBRE 0
#define OCUPADO 1

static int generarId(void);

int pan_initPantalla(Pantalla *list,int len)
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

int pan_buscarLugarLibre(Pantalla *list,int len)
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

int pan_addPantalla(Pantalla *list, int len, int idPan, char *name,char *adress,float precio,int tipo)
{
    int retorno=-1;
    int posLibre;

    posLibre=pan_buscarLugarLibre(list,len);
    if(list!=NULL && len>0)
    {
        if(posLibre!=-1)
        {
            strncpy(list[posLibre].nombre,name,50);
            strncpy(list[posLibre].direccion,adress,50);
            list[posLibre].tipo=tipo;
            list[posLibre].precio=precio;
            list[posLibre].isEmpty=OCUPADO;
            list[posLibre].idPan=idPan;
        }
        retorno=0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addPersona'\n");
    }
    return retorno;
}

int pan_altaPantalla(Pantalla *list,int len)
{
    char auxNombre[50];
    char auxDireccion[50];
    int auxTipo;
    float auxPrecio;
    int auxId;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        if(utn_getValidName(auxNombre)==0 &&
            utn_getValidStringAlfaNumerico("Ingrese direccion: ","\nError.","\nError, excediste el maximo de caracteres.",auxDireccion,50,2)==0 &&
            utn_getValidFloat("Ingrese Precio: ","\nError.",&auxPrecio,0,99999,2)==0 &&
            utn_getValidInt("Tipo de pantalla\n1.LED\n2.LCD\nIngrese opcion: ","\nERROR, un tipo de pantalla.",&auxTipo,1,2,2)==0)
        {
            auxId=generarId();
            pan_addPantalla(list,len,auxId,auxNombre,auxDireccion,auxPrecio,auxTipo);
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

int pan_printfPantalla(Pantalla *list,int len)
{
    int ret=-1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {
                printf("\nNombre: %s",list[i].nombre);
                printf("\nNombre: %s",list[i].direccion);
                printf("\nPrecio: %.2f",list[i].precio);
                printf("\nId Pantalla: %d\n",list[i].idPan);
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

int pan_buscarPantallaPorId(Pantalla *list,int len,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idPan==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}

int pan_bajaPantalla(Pantalla *list,int len,int id)/*falta baj publicidad*/
{
    int i;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idPan==id)
            {
                list[i].isEmpty=LIBRE;
            }
        }
        ret=0;
    }
    return ret;
}

int pan_modificarPantalla(Pantalla *list, int len,int id)
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

/*if(indicePantallaAModificar)*/




/*int ret = -1;
int auxId;
char auxName[50];
char auxLastName[50];
int auxEdad;
char auxDni[10];
int opciones;
if(list!=NULL && len>0)
{

    do
    {
        per_printfPersonas(list,len);
        if(utn_getValidInt("Ingrese Id a modificar: ","\nERROR, no es una id.",&auxId,0,99999,2)==0)
        {
            if(buscarPersonaPorId(list,len,auxId)==-1)
            {
                printf("EL ID NO EXISTE\n");
            }
            else
            {
                if(utn_getValidInt("\tMODIFICAR\n1.Nombre\n2.Apellido\n3.Edad\n4.Dni\n5.Salir\nIngrese opcion: ","\nERROR, no es una id.",&opciones,1,5,2)==0)
                {
                    switch(opciones)
                    {
                        case 1:
                        if(utn_getValidName(auxName)==0)
                        {
                            strncpy(list[auxId].nombre,auxName,50);
                            printf("Nombre modificado: %s",list[auxId].nombre);
                        }
                        break;
                        case 2:
                        break;
                        case 3:
                        break;
                        case 4:
                        break;
                        case 5:
                        break;
                        default :
                        printf("\nOpcion incorrecta");
                        break;
                    }
                }
            }

        }
    }while(opciones!=5);
    ret=0;
}

return ret;*/


int menu(Pantalla *list,int len)
{
    pan_initPantalla(list,len);
    int opciones;
    int auxId;
    int auxPos;
    do
    {
        printf("\n------------------------\n");
        if(utn_getValidInt("\n1-Alta\n2-Modificar\n3-Baja\n4-Mostrar\n5-Salir\nIngrese opcion: ","Error",&opciones,1,5,3)==0)
        {
            switch(opciones)
            {
            case 1:
                if(pan_altaPantalla(list,len)==0)
                {
                    printf("\n------------------------\n");
                    printf("\n\tALTA EXITOSA\n");
                }
                else
                {
                    printf("ERROR,No hay lugar");
                }
                break;
            case 2:
                pan_printfPantalla(list,len);
                if(pan_modificarPantalla(list,len,auxId)==0)
                {
                    printf("\nModificacion exitosa");
                }
                else
                {
                    printf("\nNO EXISTE ID.");
                }
                break;
            case 3:

                pan_printfPantalla(list,len);
                if(utn_getValidInt("\nIngrese id: ","ERROR",&auxId,1,1000,2)==0)
                {
                    if(pan_buscarPantallaPorId(list,len,auxId,&auxPos)!=-1)
                    {
                        pan_bajaPantalla(list,len,auxId);
                        printf("\nBAJA EXITOSA\n");
                    }
                    else
                    {
                        printf("\nNO EXISTE ID.");
                    }
                }
                break;
            case 4:
                pan_printfPantalla(list,len);
                break;
            case 5:
                break;
            default:
                printf("opcion incorrecta.");
                break;
            }

        }
    }
    while(opciones!=5);

    return 0;
}

static int generarId(void)
{
    static int idMax=1;
    return idMax++;
}
