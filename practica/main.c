#include <stdio.h>
#include <stdlib.h>
#include "funcionesDePracticas.h"

int main()
{
    float numberOne,numberTwo,resultadoSuma,resultadoResta,resultadoDivision,resultadoMultiplicacion;
    //int resultadoFactorialA,resultadoFactorialB;
    int opcionElegidaPorElUsuario;
    char respuestaSubMenuCalcular;
    char respuestaSubMenuInformar;
    do
    {
        opcionElegidaPorElUsuario=opcionesMenu();
        fflush(stdin);
        if (opcionElegidaPorElUsuario==-1)
        {
            printf("Error, no es una opcion.\n");
        }
        else if ((opcionElegidaPorElUsuario!=1 && opcionElegidaPorElUsuario==2 )|| opcionElegidaPorElUsuario==3 || opcionElegidaPorElUsuario==4)
        {
            printf("Error, necesitas minimo 2 numeros.\n");
        }
        else
        {
            switch(opcionElegidaPorElUsuario)
            {
                case 1:
                printf("Ingrese un numero: \n");
                fflush(stdin);
                scanf("%f",&numberOne);
                case 2:
                printf("Ingrese otro numero: \n");
                fflush(stdin);
                scanf("%f",&numberTwo);
                case 3:
                respuestaSubMenuCalcular=subMenucalcularOperaciones();
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
                        numberOne=sacarFactorialDosNumeros(numberOne);
                        numberTwo=sacarFactorialDosNumeros(numberTwo);
                        break;
                    }
                }
            }
        }

    }
    while(opcionElegidaPorElUsuario!=5);



    return 0;
}
