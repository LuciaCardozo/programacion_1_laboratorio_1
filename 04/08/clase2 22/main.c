#include <stdio.h>
#include <stdlib.h>


int sumar(int numeroUno, int numeroDos);
int pideSuma(int *resultado);

int main()
{
    int resultado;
    if(pideSuma(&resultado) == 0)
    {
        printf("\nResultado: %d\n",resultado);
    }
    else
    {
        printf("ERROR");
    }
    /*int numeroUno;
    int numeroDos;
    printf("\nNumero 1: ");
    scanf("%d",&numeroUno);
    printf("\nNumero 2: ");
    scanf("%d",&numeroDos);
    //resultado = numeroUno + numeroDos;
    resultado = sumar(numeroUno,numeroDos);
    printf("\nResultado: %d\n",resultado);*/
    return 0;
}

int pideSuma(int *resultado)
{
    int numeroUno;
    int numeroDos;
    printf("\nNumero 1: ");
    scanf("%d",&numeroUno);
    printf("\nNumero 2: ");
    scanf("%d",&numeroDos);
    *resultado = numeroUno + numeroDos;
    return 0;
}

int sumar(int numeroUno, int numeroDos)
{
    int resultado;
    resultado = numeroUno + numeroDos;
    return resultado;
}
