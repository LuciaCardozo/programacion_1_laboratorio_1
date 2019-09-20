#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "Estructura.h"
#define OCUPADO 1
#define LIBRE 0
static int generarId(void);

int per_initPersona(Persona *list,int len)
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

int per_buscarLugarLibre(Persona *list,int len)
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

int per_addPersona(Persona *list, int len, int id, char *name,char *lastName,int edad,char *dni)
{
    int retorno=-1;
    int posLibre;

    posLibre=per_buscarLugarLibre(list,len);
    if(list!=NULL && len>0)
    {
        if(posLibre!=-1)
        {
            strncpy(list[posLibre].nombre,name,50);
            strncpy(list[posLibre].apellido,lastName,50);
            strncpy(list[posLibre].dni,dni,10);
            list[posLibre].edad=edad;
            list[posLibre].isEmpty=OCUPADO;
            list[posLibre].id=id;
        }
        retorno=0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addPersona'\n");
    }
    return retorno;
}

int per_altaPersona(Persona *list,int len)
{
    char auxName[50];
    char auxLastName[50];
    int auxEdad;
    char auxDni[50];
    int auxId;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        if(utn_getValidName(auxName)==0 && utn_getValidLastName(auxLastName)==0 &&
                utn_getValidInt("Ingrese edad: ","\nERROR, no es una edad.",&auxEdad,0,130,2)==0 &&
                utn_getValidStringNumerico("Ingrese Dni: ","\nError.","\nError, superaste el largo de caracteres.\n",auxDni,8,2)==0)
        {
            auxId=generarId();
            per_addPersona(list,len,auxId,auxName,auxLastName,auxEdad,auxDni);
            printf("\n------------------------\n");
            printf("\nID de Persona: %d\nNombre: %s\nApellido: %s\nEdad: %d\nDni: %s\n",
                   auxId,auxName,auxLastName,auxEdad,auxDni);
            ret=0;

        }
    }
    return ret;
}

int per_printfPersonas(Persona *list,int len)
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
                printf("\nNombre: %s",list[i].apellido);
                printf("\nEdad: %d",list[i].edad);
                printf("\nDni: %s",list[i].dni);
                printf("\nId: %d\n",list[i].id);
                printf("\n------------------------\n");
            }
        }
        ret=0;
    }
    return ret;
}

int buscarPersonaPorId(Persona *list,int len,int id)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id)
            {
                ret=i;
            }
        }
    }
    return ret;
}

int bajaPersona(Persona *list,int len,int id)
{
    int i;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id)
            {
                list[i].isEmpty=LIBRE;
            }
        }
        ret=0;
    }
    return ret;
}

int modificarPersona(Persona *list, int len,int id)
{
    int ret = -1;
    char nuevoNombre[50];
    char nuevoApellido[51];
    int nuevaEdad;
    char nuevoDni[10];
    int opciones;
    int auxId;
    int indicePersonaAModificar;
    if(utn_getValidInt("\nIngrese el id: ","\nError, repuesta incorrecta.",&auxId,0,99999,2)==0)
    {
        indicePersonaAModificar=buscarPersonaPorId(list,len,auxId);
        do
        {
            if(utn_getValidInt("\n\nQue desea modificar?\n1-Modificar nombre\n2-Modificar Apellido\n3-Edad\n4-Dni\n5-Cancelar\nEliga la opcion: ",
                               "Error",&opciones,1,5,2)==0)
            {
                switch(opciones)
                {
                case 1:
                    utn_getValidString("\nIngrese nuevo nombre: ","\nError","\nError, excediste el maximo de caracteres.",nuevoNombre,50,2);
                    strncpy(list[indicePersonaAModificar].nombre,nuevoNombre,50);
                    printf("%s-------------------------\n",list[indicePersonaAModificar].nombre);
                    break;
                case 2:
                    utn_getValidString("\nIngrese nuevo Apellido: ","\nError","\nError, excediste el maximo de caracteres.",nuevoApellido,50,2);
                    strncpy(list[indicePersonaAModificar].apellido,nuevoApellido,50);
                    printf("%d-------------------------\n",indicePersonaAModificar);
                    break;
                case 3:
                    utn_getValidInt("\nIngrese edad: ","\nError",&nuevaEdad,1,130,3);
                    list[indicePersonaAModificar].edad=nuevaEdad;
                    break;
                case 4:
                    utn_getValidStringNumerico("Ingrese Dni: ","\nError.","\nError, superaste el largo de caracteres.\n",nuevoDni,8,2);
                    strncpy(list[indicePersonaAModificar].dni,nuevoDni,10);
                    break;
                case 5:
                    break;
                default :
                    printf("No es una opcion");
                    break;
                }
            }
        }
        while(opciones!=5);

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


int menu(Persona *list,int len)
{
    per_initPersona(list,len);
    int opciones;
    int auxId;
    do
    {
        printf("\n------------------------\n");
        if(utn_getValidInt("\n1-Alta\n2-Baja\n3-Modificar\n4-Mostrar\n5-Ordenar\n6-Salir\nIngrese opcion: ","Error",&opciones,1,6,3)==0)
        {
            switch(opciones)
            {
            case 1:
                if(per_altaPersona(list,len)==0)
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
                per_printfPersonas(list,len);
                if(utn_getValidInt("\nIngrese id: ","ERROR",&auxId,0,99999,2)==0)
                {
                    if(buscarPersonaPorId(list,len,auxId)!=-1)
                    {
                        bajaPersona(list,len,auxId);
                        printf("\nBAJA EXITOSA\n");
                    }
                    else
                    {
                        printf("\nNO EXISTE ID.");
                    }
                }
                break;
            case 3:
                modificarPersona(list,len,auxId);
                break;
            case 4:
                per_printfPersonas(list,len);
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                printf("opcion incorrecta.");
                break;
            }

        }
    }
    while(opciones!=6);

    return 0;
}

int per_ordenarPorEdad(Persona *list,int len)
{
    int ret = -1;
    char aux[50];
    int auxInt;
    int i,j;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[i].edad>list[j].edad)
                {
                    auxInt=list[i].edad;
                    list[i].edad=list[j].edad;
                    list[j].edad=auxInt;

                    strncpy(aux,list[i].nombre,50); /*aux=list[i].nombre....nombre,edad,dni*/
                    strncpy(list[i].nombre,list[j].nombre,50);
                    strncpy(list[j].nombre,aux,50);

                    strncpy(aux,list[i].apellido,50); /*aux=list[i].nombre....nombre,edad,dni*/
                    strncpy(list[i].apellido,list[j].apellido,50);
                    strncpy(list[j].apellido,aux,50);

                    strcpy(aux,list[i].dni);
                    strcpy(list[i].dni,list[j].dni);
                    strcpy(list[j].dni,aux);

                    auxInt=list[i].id;
                    list[i].id=list[j].id;
                    list[j].id=auxInt;
                }
            }
        }
        ret = 0;
    }
    return ret;
}

static int generarId(void)
{
    static int idMax=0;
    return idMax++;
}
