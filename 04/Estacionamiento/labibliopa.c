#include "labibliopa.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void hardcodePersonas(sPersona listaPersonas[],int cant)
{
    char nombre[][51]= {"Maria","Ezequiel","German","Yanina"};
    int anio[]= {1990,1980,2000,1995};
    int mes[]= {3,4,12,11};
    int dia[]= {33,22,25,11};
    int i;

    for(i=0; i<cant; i++)
    {
        listaPersonas[i].id = i+1;
        listaPersonas[i].fechaNac.anio = anio[i];
        listaPersonas[i].fechaNac.mes = mes[i];
        listaPersonas[i].fechaNac.dia = dia[i];
        strcpy(listaPersonas[i].nombre, nombre[i]);
    }
}

void mostrarPersonas(sPersona listaPersonas[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("ID : %d \n", listaPersonas[i].id);
        printf("Nombre : %s \n", listaPersonas[i].nombre);
        printf("Fecha de nacimiento : %d/%d/%d \n\n", listaPersonas[i].fechaNac.dia, listaPersonas[i].fechaNac.mes, listaPersonas[i].fechaNac.anio);
    }
}

void hardcodeoAutos(sVehiculo listaAutitos[], int cant)
{
    int i;
    char patente[][8]= {"AAA111", "BBB222", "AA111BB", "OJ222BB"};
    int dia = {26};
    int mes = {9};
    int anio = {2019};
    int horaIngreso[] = {10,9,8,11};
    int horaSalida[] = {11,11,11,12};

    for(i=0; i<cant; i++)
    {
        strcpy(listaAutitos[i].patente,patente[i]);
        listaAutitos[i].fechaIngreso.dia = dia;
        listaAutitos[i].fechaIngreso.mes = mes;
        listaAutitos[i].fechaIngreso.anio = anio;
        listaAutitos[i].horaIngreso = horaIngreso[i];
        listaAutitos[i].horaSalida = horaSalida[i];
        listaAutitos[i].idDuenio = i+1;
    }

}

void mostrarAutitos(sVehiculo listaAutitos[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        mostrarUnAutito(listaAutitos[i]);
    }
}

int buscarPorPatente(sVehiculo listaAutitos[],int cant)
{
    int i;
    char patente[51];
    printf("\nIngresa la patente master : ");
    fgets(patente,sizeof(patente),stdin);
    for(i=0; i<cant; i++)
    {
        if(strcmp(listaAutitos[i].patente, patente) == 0)
        {
            return i;
        }
    }
    return -1;
}

void mostrarUnAutito(sVehiculo unAutito)
{
    printf("Nombre : ");
    printf("Patente : %s \n", unAutito.patente);
    printf("Hora de ingreso : %d \n", unAutito.horaIngreso);
    printf("Hora de salida : %d \n",unAutito.horaSalida);
    printf("Fecha de ingreso : %d/%d/%d \n\n", unAutito.fechaIngreso.dia, unAutito.fechaIngreso.mes, unAutito.fechaIngreso.anio);
}

void mostrarUnaPersona(sPersona unaPersona)
{
    printf("ID : %d \n", unaPersona.id);
    printf("Nombre : %s \n", unaPersona.nombre);
    printf("Fecha de nacimiento : %d/%d/%d \n\n", unaPersona.fechaNac.dia, unaPersona.fechaNac.mes, unaPersona.fechaNac.anio);
}

int buscarIndicePersona(sPersona unaPersona[],int cant, int id)
{
    int i;
    scanf("%d",&id);
    for(i=0;i<cant;i++)
    {
        if(id == unaPersona[i].id)
        {
            return i;
        }
    }
    return -1;
}

/*ORDENAR POR PATENTES*/
/*ORDENAR POR NOMBRE DEL DUEÑO*/
/*MOSTRAR VEHICULOS FIJATE DE HACERLO CON NOMBRE, TE ACORDAS PIBE.*/



