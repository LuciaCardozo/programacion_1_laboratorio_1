#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Empleado.h"
#include <string.h>
#include "utn.h"
#define CANTIDAD 5

void altaEmpleado(EEmpleado pEmpleado);
int main()
{
    EEmpleado miListaDeEmpleado[CANTIDAD];
    EEmpleado_initArray(miListaDeEmpleado,CANTIDAD);

    miListaDeEmpleado[0].isEmpty=1;
    miListaDeEmpleado[1].isEmpty=1;
    miListaDeEmpleado[2].isEmpty=1;
    for(int i=0;i<CANTIDAD;i++)
    {
        int lugarLibre=EEmpleado_lugarLibreArray(miListaDeEmpleado,CANTIDAD);
        printf("\n %d \n",lugarLibre);
        if(lugarLibre != -1)
        {
            altaEmpleado(miListaDeEmpleado[lugarLibre]);
        }
        else
        {
            printf("no hay lugar gil");
        }
    }
    return 0;
}

void altaEmpleado(EEmpleado pEmpleado)
{
    char name[50];
    char lastName[50];
    if(utn_getValidName(name)==0)
    {
        if(utn_getValidLastName(lastName)==0)
        {
            strncpy(pEmpleado.name,name,50);
            strncpy(pEmpleado.lastName,lastName,50);
            pEmpleado.isEmpty=1;
            printf("%d", pEmpleado.isEmpty);
        }
    }

}
    /*EEmpleado miListaDeEmpleados[CANTIDAD];
    EEmpleado_initArray(miListaDeEmpleados,CANTIDAD);
    int i;

    for(i=0;i<CANTIDAD;i++)
    {
        char name[50];
        char lastName[50];
        int id;
        if(utn_getValidName(name)==0)
        {
            if(utn_getValidLastName(lastName)==0)
            {
                if(utn_getValidInt("Ingrese su ID:","ERROR, no es un ID",&id,0,INT_MAX,3)==0)
                {
                    strcpy(miListaDeEmpleados[i].name,name);
                    strcpy(miListaDeEmpleados[i].lastName,lastName);
                    miListaDeEmpleados[i].idEmpleado=id;
                }
            }
        }
    }
    //EEmpleado_initArray(miListaDeEmpleados, CANTIDAD);

    strcpy(miListaDeEmpleados[0].name,"Jonathan");
    strcpy(miListaDeEmpleados[0].lastName,"Haedo");
    miListaDeEmpleados[0].idEmpleado=1;
    miListaDeEmpleados[0].isEmpty=0;

    strcpy(miListaDeEmpleados[1].name,"Lucia");
    strcpy(miListaDeEmpleados[1].lastName,"Cardozo");
    miListaDeEmpleados[1].idEmpleado=2;
    miListaDeEmpleados[1].isEmpty=0;

    printf("ingrese el nombre: ");
    gets(miListaDeEmpleados[2].name);

     printf("ingrese el apellido: ");
    gets(miListaDeEmpleados[2].lastName);

    printf("ingrese el id: ");
    scanf("%d",&miListaDeEmpleados[2].idEmpleado);

    miListaDeEmpleados[2].isEmpty=0;
*/
   // EEmpleado_printDebugArray(miListaDeEmpleados,CANTIDAD);

   // for(int i=0;i<)*/
   /*char palabra[50]="hola";
   char palabra1[50]="hola Mundo";
   char palabra2[50]="hola me fui a comer";
   printf("%d\n",strlen(palabra));
   printf("%d\n",strlen(palabra1));
   printf("%d\n",strlen(palabra2));*/
