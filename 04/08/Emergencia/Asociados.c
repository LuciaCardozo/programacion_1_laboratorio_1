#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociados.h"
#include "utn.h"
#define LIBRE 0
#define OCUPADO 1

static int generarIdAsociados(void);

int asoc_initAsociados(Asociados *listAsoc,int lenAsoc)
{
    int ret = -1;
    int i;
    if(listAsoc!=NULL && lenAsoc>0)
    {
        for(i=0; i<lenAsoc; i++)
        {
            listAsoc[i].isEmpty=LIBRE;
        }
        ret = 0;
    }
    return ret;
}

int asoc_buscarLugarLibre(Asociados *listAsoc,int lenAsoc)
{
    int ret = -1;
    int i;
    if(listAsoc!=NULL && lenAsoc>0)
    {
        for(i=0; i<lenAsoc; i++)
        {
            if(listAsoc[i].isEmpty==LIBRE)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

int asoc_addAsociados(Asociados *listAsoc, int lenAsoc, int id, char *nombre,char *apellido,char *dni,int edad)
{
    int retorno=-1;
    int posLibre;

    posLibre=asoc_buscarLugarLibre(listAsoc,lenAsoc);
    if(listAsoc!=NULL && lenAsoc>0)
    {
        if(posLibre!=-1)
        {
            strncpy(listAsoc[posLibre].nombre,nombre,50);
            strncpy(listAsoc[posLibre].apellido,apellido,50);
            strncpy(listAsoc[posLibre].dni,dni,20);
            listAsoc[posLibre].edad=edad;
            listAsoc[posLibre].isEmpty=OCUPADO;
            listAsoc[posLibre].idAsociado=id;
        }
        retorno=0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addPersona'\n");
    }
    return retorno;
}

int asoc_altaAsociados(Asociados *listAsoc,int lenAsoc)
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[20];
    int auxEdad;
    int auxId;
    int ret = -1;
    if(listAsoc!=NULL && lenAsoc>0)
    {
        if(utn_getValidName(auxNombre)==0 &&
            utn_getValidLastName(auxApellido)==0 &&
            utn_getValidStringNumerico("\nIngrese DNI: ","\nError","\nError, excediste el maximo de caractres",auxDni,20,2)==0 &&
            utn_getValidInt("\nIngrese edad: ","\nERROR, no es una edad.",&auxEdad,1,130,2)==0)
        {
            auxId=generarIdAsociados();
            asoc_addAsociados(listAsoc,lenAsoc,auxId,auxNombre,auxApellido,auxDni,auxEdad);
            printf("\n------------------------\n");
            printf("\nID de Pantalla: %d\nNombre: %s\nApellido: %s\nDni: %s\nEdad: %d\n",
                   auxId,auxNombre,auxApellido,auxDni,auxEdad);
            ret=0;

        }
    }
    return ret;
}

int asoc_printfAsociados(Asociados *listAsoc,int lenAsoc)
{
    int ret=-1;
    int i;
    if(listAsoc!=NULL && lenAsoc>0)
    {
        for(i=0; i<lenAsoc; i++)
        {
            if(listAsoc[i].isEmpty==OCUPADO)
            {
                printf("\nId Asociado: %d\n",listAsoc[i].idAsociado);
                printf("\nNombre: %s",listAsoc[i].nombre);
                printf("\nApellido: %s",listAsoc[i].apellido);
                printf("\nDni: %s",listAsoc[i].dni);
                printf("\Edad: %d",listAsoc[i].edad);
                printf("\n------------------------\n");
                ret=0;
            }
        }
    }
    return ret;
}

int asoc_printfAsociadosPorId(Asociados *listAsoc,int lenAsoc,int id)
{
    int ret=-1;
    int i;
    if(listAsoc!=NULL && lenAsoc>0)
    {
        for(i=0; i<lenAsoc; i++)
        {
            if(listAsoc[i].isEmpty==OCUPADO)
            {
                if(listAsoc[i].idAsociado==id)
                {
                    printf("\nId Pantalla: %d\n",listAsoc[i].idAsociado);
                    printf("\nNombre: %s",listAsoc[i].nombre);
                    printf("\nNombre: %s",listAsoc[i].apellido);
                    printf("\nDni: %s",listAsoc[i].dni);
                    printf("\Edad: %d",listAsoc[i].edad);
                    ret=0;
                }
            }
        }
    }
    return ret;
}

int asoc_buscarAsociadoPorId(Asociados *listAsoc,int lenAsoc,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listAsoc!=NULL && lenAsoc>0)
    {
        for(i=0; i<lenAsoc; i++)
        {
            if(listAsoc[i].idAsociado==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}

int asoc_bajaAsociado(Asociados *listAsoc,int lenAsoc,int id)/*falta baj publicidad*/
{
    int i;
    int ret = -1;
    if(listAsoc!=NULL && lenAsoc>0)
    {
        for(i=0; i<lenAsoc; i++)
        {
            if(listAsoc[i].idAsociado==id)
            {
                listAsoc[i].isEmpty=LIBRE;
            }
        }
        ret=0;
    }
    return ret;
}

int asoc_modificarAsociado(Asociados *listAsoc, int lenAsoc,int id)
{
    int ret = -1;
    char auxNombre[50];
    char auxApellido[50];
    int opciones;
    int auxId;
    int auxPos;
    if(utn_getValidInt("\nIngrese el id: ","\nError, repuesta incorrecta.",&auxId,1,99999,2)==0)
    {
        if(asoc_buscarAsociadoPorId(listAsoc,lenAsoc,auxId,&auxPos)==-1)
        {
            printf("\nNo se encontro el ID");
        }
        else
        {
            do
            {
                if(utn_getValidInt("\n\n¿Que desea modificar?\n1-Nombre\n2-Apellido\n3-Cancelar\nEliga la opcion: ",
                                   "Error",&opciones,1,3,2)==0)
                {
                    switch(opciones)
                    {
                    case 1:
                        utn_getValidString("\nIngrese nuevo nombre: ","\nError","\nError, excediste el maximo de caracteres.",auxNombre,50,2);
                        strncpy(listAsoc[auxPos].nombre,auxNombre,50);
                        printf("%s-------------------------\n",listAsoc[auxPos].nombre);
                        break;
                    case 2:
                        utn_getValidString("\nIngrese nuevo nombre: ","\nError","\nError, excediste el maximo de caracteres.",auxApellido,50,2);
                        strncpy(listAsoc[auxPos].apellido,auxApellido,50);
                        printf("%s-------------------------\n",listAsoc[auxPos].apellido);
                        break;
                    case 3:
                        break;
                    default :
                        printf("No es una opcion");
                        break;
                    }
                }
            }while(opciones!=3);
        }

        ret=0;
    }
    return ret;
}

int menu(Asociados *listAsoc,int lenAsoc)
{
    asoc_initAsociados(listAsoc,lenAsoc);
    int auxId;
    int auxPosId;
    int opciones;
    if(listAsoc!=NULL && lenAsoc>0)
    {
        do
        {
            if(utn_getValidInt("\n1-Alta del asociado\n2-Modificar datos del asociado\n3-Baja del asociado\n4-Mostrar\n5-Salir\nIngrese opcion: ","\nError.",
             &opciones,1,5,2)==0)
             {
                switch(opciones)
                {
                    case 1:
                        if(asoc_altaAsociados(listAsoc,lenAsoc)==0)
                        {
                            printf("\nAlta exitosa");
                        }
                        else
                        {
                            printf("\nError, no pudo dar la alta");
                        }
                        break;
                    case 2:
                        asoc_printfAsociados(listAsoc,lenAsoc);
                        if(asoc_modificarAsociado(listAsoc,lenAsoc,auxId)==0)
                        {
                            printf("\nModificacion Exitosa");
                        }
                        else
                        {
                            printf("\nError");
                        }
                        break;
                    case 3:
                        asoc_printfAsociados(listAsoc,lenAsoc);
                        if(utn_getValidInt("\nIngrese Id: ","\nError.",&auxId,1,99999,2)==0)
                        {
                            if(asoc_buscarAsociadoPorId(listAsoc,lenAsoc,auxId,&auxPosId)==0)
                            {
                                asoc_bajaAsociado(listAsoc,lenAsoc,auxPosId);
                            }
                            else
                            {
                                printf("Id no existe");
                            }
                        }
                        break;
                    case 4:
                        asoc_printfAsociados(listAsoc,lenAsoc);
                        break;
                    case 5:
                        break;
                    default:
                    printf("\nOpcion incorrecta");
                }
             }
        }while(opciones!=5);
    }
    return 0;
}


static int generarIdAsociados(void)
{
    static int idMax=1;
    return idMax++;
}
