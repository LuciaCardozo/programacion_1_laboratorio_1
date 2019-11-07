#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char aux[4][51];
	int ret=-1;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			Employee* anEmployee;
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(aux),*(aux+1),*(aux+2),*(aux+3));
			anEmployee=employee_newParametros(*(aux),*(aux+1),*(aux+2),*(aux+3));
			if(anEmployee)
			{
				printf("\n%s----%s----%s----%s",*(aux),*(aux+1),*(aux+2),*(aux+3));
				ll_add(pArrayListEmployee,anEmployee);
				ret=0;
			}
			else
			{
				printf("\nError, no se cargaron los datos");
			}
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
