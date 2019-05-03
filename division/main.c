#include <stdio.h>
#include <stdlib.h>

int divideDosNumeros(float numeroUno, float numeroDos, float* pResultado);
int main()
{
    float numeroUno;
    float numeroDos;
    float pResultado;
    fflush(stdin);
    printf("numeroUno!\n");
    scanf("%f",&numeroUno);
    fflush(stdin);
    printf("numeroUno!\n");
    scanf("%f",&numeroDos);

    divideDosNumeros(numeroUno,numeroDos,&pResultado);

    if(divideDosNumeros(numeroUno,numeroDos,&pResultado)==0)
    {
        printf("ESTA TODO OK %f\n",pResultado);
    }
    else if(divideDosNumeros(numeroUno,numeroDos,&pResultado)!=0)
    {
        printf("Error\n");
    }
    return 0;
}
int divideDosNumeros(float numeroUno, float numeroDos, float* pResultado)
{
    int retorno=-1;
    if(numeroDos!=0)
    {
        *pResultado = numeroUno/numeroDos;
        retorno=0;
    }
    return retorno;
}
