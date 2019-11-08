#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



/*int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};
int main()
{
	printf("%d %d %d",course,lets,find);
	return 0;
}*/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        menu(&option);
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nSe abrio: %d Archivos\n",controller_loadFromText("data.csv",listaEmpleados));
                    controller_lastIdEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nError, no se puedo cargar los datos\n");
                }
                break;
            case 2:
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("\nSe abrio: %d Archivos\n",controller_loadFromText("data.bin",listaEmpleados));
                }
                else
                {
                    printf("\nError, no se puedo cargar los datos\n");
                }
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                break;
            case 8:
                printf("\nSe cargo: %d Archivos\n",controller_saveAsText("data.csv",listaEmpleados));
                break;
            case 9:
                break;
            case 10:
                break;
            default:
            	printf("\nError, opcion incorrecta");
            	break;
        }
    }while(option != 10);
    return 0;
}
