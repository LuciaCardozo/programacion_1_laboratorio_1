#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define LEN_LIST 5

int main()
{
    Employee listaDeEmpleado[LEN_LIST];
    emp_initEmployees(listaDeEmpleado,LEN_LIST);
    int opciones;
    do
    {
        opciones=utn_menuDeOpciones();
        switch(opciones)
        {
            case 1:
            emp_addEployees(listaDeEmpleado,LEN_LIST);
            break;
            case 2:
            emp_printEmployees(listaDeEmpleado,LEN_LIST);
            break;
        }
    }while(opciones!=5);

    return 0;
}


