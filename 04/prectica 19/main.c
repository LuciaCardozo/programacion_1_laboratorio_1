#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("----------Bienvenido a la fabrica de vectores!----------\n");
    size_t largo;
    printf("\nIngrese el largo de su vector: ");
    fflush(stdin);
    scanf("%d",&largo);
    printf("El largo de su vector es: %d\n",largo);

    int i;
    int vector1[largo];
    for(i=0;i<largo;i++)
    {
        printf("Ingrese el valor de la posicion %d: ",i);
        fflush(stdin);
        scanf("%d",&vector1[i]);
    }
    printf("\nOk, ahora vamos a imprimir su vector.\n");
    for(i=0;i<largo;i++)
    {
        printf("El vector %d es %d\n",i,vector1[i]);
    }
    return 0;
}
