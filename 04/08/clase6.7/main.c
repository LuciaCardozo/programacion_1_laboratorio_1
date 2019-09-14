#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Estructura.h"
#define CANT 3

int main()
{

    /*int numero;
    Persona list[CANT];

    if(utn_getValidInt("Ingrese numero:","ERROR.",&numero,-99999,99999,2)==0)
    {
        printf("Numero Ingresado: %d",numero);
    }*/
    Persona listPersonas[50];
    char auxName[50];
    int auxEdad;
    char auxDni[50];
    addPersona(listPersonas,CANT,auxName,&auxEdad,auxDni);
    printfPersonas(listPersonas,CANT,auxName,&auxEdad,auxDni);
    ordenarPorEdad(listPersonas,CANT);
    printfPersonas(listPersonas,CANT,auxName,&auxEdad,auxDni);

    return 0;

}
