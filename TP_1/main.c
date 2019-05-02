#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

int main()
{
    float numberOne,numberTwo,resultadoSuma,resultadoResta,resultadoDivision,resultadoMultiplicacion;
    int opcionElegidaPorElUsuario;
    char respuestaSubMenuCalcular;
    char respuestaSubMenuInformar;
    int factorialUno;
    int factorialDos;
    do
    {
        opcionElegidaPorElUsuario=opcionesMenuPrincipal();
        void limpiarMemoria();
        if (opcionElegidaPorElUsuario==-1)
        {
            printf("Error, no es una opcion.\n");
        }
        else if (opcionElegidaPorElUsuario!=1 && opcionElegidaPorElUsuario==2 )
        {
            printf("Error, necesitas el 1er operando.\n");
        }
        else if((opcionElegidaPorElUsuario!=1 && opcionElegidaPorElUsuario==3)|| opcionElegidaPorElUsuario==4)
        {
            printf("Error, necesitados dos numeros para entrar a esta opcion.\n");
        }
        else
        {
            switch(opcionElegidaPorElUsuario)
            {
                case 1:
                printf("Ingrese un numero: \n");
                void limpiarMemoria();
                scanf("%f",&numberOne);
                case 2:
                printf("Ingrese otro numero: \n");
                void limpiarMemoria();
                scanf("%f",&numberTwo);
                case 3:
                respuestaSubMenuCalcular=subMenucalcularOperaciones();
                void limpiarMemoria();
                if (respuestaSubMenuCalcular==-1)
                {
                    printf("Error, no es una opcion.\n");
                }
                else
                {
                    switch(respuestaSubMenuCalcular)
                    {
                        case 'a':
                        sumaDosNumeros(numberOne,numberTwo,&resultadoSuma);
                        break;
                        case 'b':
                        restaDosNumeros(numberOne,numberTwo,&resultadoResta);
                        break;
                        case 'c':
                        divideDosNumeros(numberOne,numberTwo,&resultadoDivision);
                        break;
                        case 'd':
                        multiplicoDosNumeros(numberOne,numberTwo,&resultadoMultiplicacion);
                        break;
                        case 'e':
                        factorialUno=sacarFactorial(numberOne);
                        factorialDos=sacarFactorial(numberTwo);
                    }
                }
                case 4:
                respuestaSubMenuInformar=subMenuInformarResultados();
                if(respuestaSubMenuCalcular==-1)
                {
                    printf("Error, no es una opcion.\n");
                }
                else
                {
                    switch(respuestaSubMenuInformar)
                    {
                        case 'a':
                        printf("El resultado de A+B(%.2f & %.2f) es: %.2f\n",numberOne,numberTwo,resultadoSuma);
                        break;
                        case 'b':
                        printf("El resultado de A-B(%.2f & %.2f) es: %.2f\n",numberOne,numberTwo,resultadoResta);
                        break;
                        case 'c':
                        printf("El resultado de A/B(%.2f & %.2f) es: %.2f\n",numberOne,numberTwo,resultadoDivision);
                        break;
                        case 'd':
                        printf("El resultado de A*B(%.2f & %.2f) es: %.2f\n",numberOne,numberTwo,resultadoMultiplicacion);
                        break;
                        case 'e':
                        if(factorialUno==-1)
                        {
                            printf("Error en el 1er operando. No se saca el factorial de un numero negativo. El numero maximo para sacar factorial es 13.\n");
                        }
                        else
                        {
                            printf("El factorial de A(%.2f) es: %d\n",numberOne,factorialUno);
                        }
                        if(factorialDos==-1)
                        {
                            printf("Error en el 2do operando. No se saca el factorial de un numero negativo. El numero maximo para sacar factorial es 13.\n");
                        }
                        else
                        {
                            printf("El factorial de B(%.2f) es: %d\n",numberTwo,factorialDos);
                        }
                        break;
                    }
                }
            }
        }
    }
    while(opcionElegidaPorElUsuario!=5);
    return 0;
}
