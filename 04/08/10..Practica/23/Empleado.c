#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"

int new_Empleado()
{
    Empleado* emp=(Empleado *)mallloc(sizeof(Empleado));
    if(emp!=NULL)
    {
        strncpy(emp->nombre,"",51);
        emp->edad = 0;
        strncpy(emp->cuit,"",21);
        strncpy(emp->direccion,"",51);
        strncpy(emp->localidad,"",51);
        emp->idEmpleado = 0;
        emp->isEmpty = 0;
    }

    return emp;
}

int new_EmpleadoParam(char *nombre,int edad,char *direccion,char *localidad,int id)
{
    Empleado* emp=(Empleado *)mallloc(sizeof(Empleado));
    if(emp!=NULL)
    {
        strncpy(emp->nombre,nombre,51);
        emp->edad = edad;
        strncpy(emp->cuit,cuit,21);
        strncpy(emp->direccion,direccion,51);
        strncpy(emp->localidad,localidad,51);
        emp->idEmpleado = id;
        emp->isEmpty = 1;
    }

    return emp;
}

int emp_registerAnEmpleado()
{
    Empleado* nuevoEmpleado = new_Empleado();
    int ret = -1;
    char auxNombre[51];
    int auxEdad;
    char auxCuit[21];
    char auxDireccion[51];
    char auxLocalidad[51];
    int auxId;
    if(nuevoEmpleado!=NULL)
    {
        if(utn_getValidName(auxNombre)==0 &&
            utn_getValidInt("Ingrese edad: ","Error",&auxEdad,0,120,2) &&
            utn_getValidStringNumerico("\nIngrese Cuit: ","\nError","\nError, excediste el maximo de caracteres",auxCuit,20,2)==0 &&
            utn_getValidString("\nIngrese direccion: ","\nError","\nError, excediste el maximo de caracteres",auxDireccion,51,2)==0 &&
            utn_getValidString("\nIngrese localidad: ","\nError","\nError, excediste el maximo de caracteres",auxLocalidad,51,2)==0)
            {
                auxId=generarIdEmpleado();
                nuevoEmpleado=newEmpleadoParam(auxNombre,auxEdad,auxCuit,auxDireccion,auxLocalidad,auxId);
                printf("\n---------------------------\n");
                /*printf("\nID de cliente: %d\nNombre: %s\nEdad: %d\nCuit: %s\nDireccion: %s\nLocalidad: %s\n",
                auxId,auxNombre,auxCuit,auxEdad,auxDireccion,auxLocalidad);*/
                ret=0;
            }
    }
    return ret;
}

int cli_modifyAnCliente(Cliente *listCliente,int lenCliente)
{
    int ret=-1;
    char auxDireccion[51];
    char auxLocalidad[51];
    int auxId;
    int auxPos;
    int opciones;
    if(listCliente!=NULL && lenCliente>0)
    {
        if(utn_getValidInt("\nIngrese el id: ","\nError, repuesta incorrecta.",&auxId,1,99999,2)==0)
        {

            if(cli_findClienteById(listCliente,lenCliente,auxId,&auxPos)==-1)
            {
                printf("\nError, no se encontro Id");
            }
            else
            {
                do
                {
                    if(utn_getValidInt("\n\nQue desea modificar?\n1-Direccion\n2-Localidad\n3-Salir\n\nIngrese opcion: ",
                                        "\nError",&opciones,1,3,2)==0)
                    {

                        switch(opciones)
                        {
                            case 1:
                                utn_getValidString("\nIngrese nuevo nombre: ","\nError","\nError, excediste el maximo de caracteres.",auxDireccion,51,3);
                                strncpy(listCliente[auxPos].direccion,auxDireccion,51);
                                printf("\nNombre nuevo: %s",auxDireccion);
                                break;
                            case 2:
                                utn_getValidString("\nIngrese nuevo apellido: ","\nError","\nError, excediste el maximo de caracteres.",auxLocalidad,51,3);
                                strncpy(listCliente[auxPos].localidad,auxLocalidad,51);
                                printf("\nNombre: %s",auxLocalidad);
                                break;
                            case 3:
                                break;
                            default:
                                printf("\nError, No es una opcion");
                                break;
                        }
                        ret=0;
                    }
                }while(opciones!=3);
            }
        }
    }
    return ret;
}

int cli_removeCliente(Cliente* listCliente, int lenCliente,int id)
{
    int retorno=-1;
    int i;
    if(listCliente!=NULL && lenCliente>0 && id>0)
    {
        for(i=0; i<lenCliente; i++)
        {
            if(listCliente[i].idCliente==id)
            {
                listCliente[i].isEmpty=LIBRE;
                retorno=0;
            }
        }
    }
    return retorno;
}

int cli_printCliente(Cliente *listCliente,int lenCliente)
{
    int i;
    int ret = -1;
    if(listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenCliente; i++)
        {
            if(listCliente[i].isEmpty==OCUPADO)
            {
                printf("\n---------------------------\n");
                printf("\nId del cliente: %d\nNombre: %s\nCuit: %s\nDireccion: %s\nLocalidad: %s\n",
                       listCliente[i].idCliente,listCliente[i].nombre,listCliente[i].cuit,listCliente[i].direccion,listCliente[i].localidad);
                ret = 0;
            }
        }
    }
    return ret;
}

int cli_printClienteById(Cliente *listCliente,int lenCliente,int id)
{
    int i;
    int ret = -1;
    if(listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenCliente; i++)
        {
            if(listCliente[i].isEmpty==OCUPADO)
            {
                if(listCliente[i].idCliente==id)
                {
                    printf("\n---------------------------\n");
                    printf("\nId del cliente: %d\nNombre: %s\nCuit: %s\nDireccion: %s\nLocalidad: %s\n",
                       listCliente[i].idCliente,listCliente[i].nombre,listCliente[i].cuit,listCliente[i].direccion,listCliente[i].localidad);
                           ret = 0;
                }
            }
        }
    }
    return ret;
}

int generarIdEmpleado(void)
{
    static int idMax=1;
    return idMax++;
}
