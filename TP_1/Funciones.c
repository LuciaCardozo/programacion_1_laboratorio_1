#include <stdio.h>

float sumaDosNumeros(float numeroUno, float numeroDos, float* pResultadoSuma)
{
    *pResultadoSuma = numeroUno+numeroDos;
    return 0;
}
float restoDosNumeros(float numeroUno, float numeroDos, float* pResultadoResta)
{
    *pResultadoResta = numeroUno-numeroDos;
    return 0;
}
float divisionDosNumeros(float numeroUno, float numeroDos, float* pResultadoDivision)
{
    *pResultadoDivision=numeroUno/numeroDos;
    return 0;
}
float multiplicoDosNumeros(float numeroUno, float numeroDos, float* pResultadoMultiplicacion)
{
    *pResultadoMultiplicacion = numeroUno*numeroDos;
    return 0;
}
int sacarFactorial(int numeroIngresado)
{
    int resultado;
    if(numeroIngresado==0)
    {
        return 1;
    }

    resultado=numeroIngresado*sacarFactorial(numeroIngresado-1);

    return resultado;
}

int opcionesMenuPrincipal()
{
   int retorno;
   int opcionElegida;
   printf("1)Ingrese 1er operando:\n");
   printf("2)Ingrese 2do operando:\n");
   printf("3)Calcular todas las operaciones:\n");
   printf("4)Informar resultados\n");
   printf("5)Salir\n");
   scanf("%d",&opcionElegida);
   if(opcionElegida>0 && opcionElegida<6)
   {
       retorno=opcionElegida;
   }
   else
    {
        retorno= -1;
    }
    return retorno;
}

char mostrarSubMenu()
{
    char retorno;
    char opcionElegida;
    printf("a)Calcular la suma\n");
    printf("b)Calcular la resta\n");
    printf("c)Cacular la division\n");
    printf("d)Calcular la multiplicacion\n");
    printf("e)Calcular el factorial\n");
    fflush(stdin);
    scanf("%c",&opcionElegida);
    if(opcionElegida>='a' && opcionElegida<='e')
    {
        retorno= opcionElegida;
    }
    else
    {
        retorno= -1;
    }
    return retorno;
}

char mostrarSegundoSubMenu()
{
    char retorno;
    char opcionElegida;
    printf("a)El resultado de (A+B) es:\n");
    printf("b)El resultado de (A-B) es:\n");
    printf("c)El resultado de (A/B) es:\n");
    printf("d)EL resultado de (A*B) es:\n");
    printf("e)El factorial de A es: y el factorial de B es:\n");
    fflush(stdin);
    scanf("%c",&opcionElegida);
    if(opcionElegida>='a' && opcionElegida<='e')
    {
        retorno=opcionElegida;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}
void limpiarMemoria()
{
    fflush(stdin);
    //fpurge(stdin);
}



