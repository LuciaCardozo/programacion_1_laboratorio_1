#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Estructura.h"
#define CANT 50
#define CANT_LEN 100

int main()
{

    /*int numero;
    Persona list[CANT];

    if(utn_getValidInt("Ingrese numero:","ERROR.",&numero,-99999,99999,2)==0)
    {
        printf("Numero Ingresado: %d",numero);
    }
    Persona listPersonas[CANT];
    char auxName[CANT];
    char auxLastName[CANT];
    int auxEdad;
    char auxDni[CANT];
    per_altaPersona(listPersonas,CANT_LEN);
    per_ordenarPorEdad(listPersonas,CANT_LEN);
    printf("\nLista ordena por nombre\n");
    per_printfPersonas(listPersonas,CANT_LEN,auxName,auxLastName,&auxEdad,auxDni);*/
    Persona listPersonas[CANT];
    menu(listPersonas,CANT_LEN);

    return 0;

}
