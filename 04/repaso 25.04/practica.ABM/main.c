#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#define CANTIDAD 5

int main()
{
    ECliente listaCliente[CANTIDAD];
    cliente_initArray(listaCliente,CANTIDAD);
    /*char auxNombre[50];
    char auxApellido[50];
    char auxDni[10];
    utn_getValidName(auxNombre);
    utn_getValidLastName(auxApellido);
    utn_getValidStringNumerico("Ingrese su dni: ","Error, no es uj dni valido","Error, accediste el maximo de caracteres",auxDni,10,3);*/
   for(int i=0;i<CANTIDAD;i++){

    cliente_alta(listaCliente,CANTIDAD);
   }
    return 0;
}
