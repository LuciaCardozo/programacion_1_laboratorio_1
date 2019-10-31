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
    	if(utn_getValidInt("\n1-Cargar datos(texto)\n2-Cargar datos(Binario)\n3-Salir\nIngrese: ","\nError",&option,1,3,2)==0)
    	{
			switch(option)
			{
				case 1:
					controller_loadFromText("data.csv",listaEmpleados);
					break;
				case 2:
					controller_loadFromBinary("data.csv",listaEmpleados);
					break;
				case 3:
					break;
			}
		}
       }while(option != 3);
    return 0;
}
