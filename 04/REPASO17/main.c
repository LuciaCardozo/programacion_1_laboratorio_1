#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 3
typedef struct{
    char nombre[50];
    char apellido[50];
    int legajo;
}EAlumno;
int main()
{
    EAlumno alumno;


    strncpy(alumno.apellido,"perez",5);
    strncpy(alumno.nombre,"Juan",5);
    alumno.legajo=1000;

    printf("nombre: %s\nApellido: %s\nLegajo: %d",alumno.nombre,alumno.apellido,alumno.legajo);



    /*char nombre[CANTIDAD][50];
    char apellido[CANTIDAD][50];
    int legajo[CANTIDAD];

    for(int i=0; i<CANTIDAD;i++){
        printf("dame nombre");
        scanf("%s",nombre[i]);

        printf("dame apellido");
        scanf("%s",apellido[i]);
    }
     for(int i=0; i<CANTIDAD;i++){
        printf("%s\n",nombre[i]);
        printf("%s\n",apellido[i]);
     }

*/


   /* int minimo=999999999;
    int maximo=0;

    int numero[CANTIDAD];

    for(int i=0;i<CANTIDAD;i++){

        printf("dame un numero");
        scanf("%d",&numero[i]);

        if(numero[i]<minimo){
            minimo=numero[i];
        }
        if(numero[i]>maximo){
            maximo=numero[i];
        }
    }
    printf("%d \n %d",maximo,minimo);*/
    return 0;






}
