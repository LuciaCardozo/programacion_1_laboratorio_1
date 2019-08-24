#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float dinero;
    char tipo;
    int i;
    int numMax;
    float promedioPos;
    int cantidadPos=0;
    float numeroPos;
    for(i=0;i<4;i++)
    {
        printf("Ingrese Importe: ");
        fflush(stdin);
        scanf("%f",&dinero);
        printf("Ingrese Moneda (B,L,D,P): ");
        fflush(stdin);
        scanf("%s",&tipo);
        if(tipo!='d' && tipo!='l' && tipo!='b' && tipo!='p' && tipo!='D' && tipo!='L' && tipo!='B' && tipo!='P')
        {
            printf("Error, Ingrese Moneda (B,L,D,P): ");
            fflush(stdin);
            scanf("%s",&tipo);
        }
        if((numMax>dinero && tipo=='D') || tipo=='d')
        {
            numMax=dinero;
        }
        else if(dinero>0)
        {
            numeroPos=numeroPos+dinero;
            cantidadPos++;
        }
    }
    promedioPos=numeroPos/cantidadPos;
    printf("Mayor Importe en dolar: %d",numMax);

    printf("\nPromedio de numero positivos: %.2f",promedioPos);
    return 0;
}
