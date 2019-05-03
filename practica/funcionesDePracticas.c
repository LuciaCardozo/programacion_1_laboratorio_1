#include <stdio.h>

float sumaDosNumeros(float numeroUno, float numeroDos, float* pResultado)
{
    *pResultado = numeroUno+numeroDos;
    return 0;
}
float restaDosNumeros(float numeroUno, float numeroDos, float* pResultado)
{
    *pResultado = numeroUno-numeroDos;
    return 0;
}
float divideDosNumeros(float numeroUno, float numeroDos, float* pResultado)
{
    int retorno;
    if(numeroDos!=0)
    {
        *pResultado = numeroUno/numeroDos;
        retorno=0;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}
float multiplicoDosNumeros(float numeroUno, float numeroDos, float* pResultado)
{
    *pResultado = numeroUno*numeroDos;
    return 0;
}
//que numero buscar factorial? numeroIngesadpo
int sacarFactorial(int numeroIngresado)
{
    int i;
    int resultado=1;
    if(numeroIngresado==0)
    {
        resultado=1;
    }
    else if(numeroIngresado<0 || numeroIngresado>14)
    {
        printf("Error, el minimo es 0 y el maximo 13");
    }
    for(i=1;i<=numeroIngresado;i++)
    {
        resultado=resultado*i;
    }
    printf("%d\n",resultado);
    return resultado;
}
int opcionesMenu()
{
    int retorno;
    int respuesta;
    printf("1) Ingresar 1er operando: \n");
    printf("2) Ingresar 2do operando: \n");
    printf("3) Calcular todas las operaciones: \n");
    printf("4) Informar resultados: \n");
    printf("5) Salir.\n");
    fflush(stdin);
    scanf("%d",&respuesta);
    if(respuesta>0 && respuesta<6)
    {
        retorno=respuesta;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}
char subMenucalcularOperaciones()
{
    char retorno;
    char respuesta;
    printf("a) Calcular la suma (A+B): \n");
    printf("b) Calcular la resta (A-B): \n");
    printf("c) Calcular la division(A/B): \n");
    printf("d) Calcular la multiplicacion (A*B): \n");
    printf("e) Calcular el factorial(A!): \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    if(respuesta>='a' && respuesta<='e')
    {
        retorno=respuesta;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}
char subMenuInformarResultados()
{
    char retorno;
    char respuesta;
    printf("a) El resultado de A+B es: \n");
    printf("b) El resultado de A-B es: \n");
    printf("c) El resultado de A/B es: \n");
    printf("d) El resultado de A*B es: \n");
    printf("e) El resultado de A es:\n El resultado de B es: \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    if(respuesta>='a' && respuesta<='e')
    {
        retorno=respuesta;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}
