#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	if(path != NULL && pArrayListEmployee!=NULL)
	{
		FILE *pFile=NULL;
		pFile = fopen(path,"r");
		if(pFile!=NULL)
		{
			printf("\nAbri el archivo");

			if(parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
			{
				printf("\nTodo ok");
				ret=0;
			}
		}
		else
		{
				printf("\nEl archivo no existe");
		}
		if((fclose(pFile))==-1)
		{
			printf("\nEl archivo no se cerro");
		}
		else
		{
			printf("\nEl archivo fue cerrado exitosamente");
		}
	}
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret;
	if(path != NULL && pArrayListEmployee!=NULL)
	{
		FILE *pFile=NULL;
		pFile = fopen(path,"rb");
		if(pFile!=NULL)
		{
			printf("\nAbri el archivo");
			ret=0;
		}
		else
		{
				printf("\nEl archivo no existe");
				ret = -1;
		}
		if((fclose(pFile))==-1)
		{
			printf("\nEl archivo no se cerro");
		}
		else
		{
			printf("\nEl archivo fue cerrado exitosamente");
		}
	}
    return ret;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* nuevoEmpleado;
	int ret = -1;
    char auxNombre[51];
    char auxHoras[5];
    char auxSueldo[10];
    int auxId;
    if(pArrayListEmployee!=NULL)
    {
    	if(utn_getValidName(auxNombre)==0 &&
    			utn_getValidStringNumerico("Ingrese horas trabajadas: ","\nError","\nError, excediste el maximo de caracteres",auxHoras,5,2)==0 &&
				utn_getValidStringNumerico("Ingrese sueldo: ","\nError","\nError, excediste el maximo de caracteres",auxSueldo,10,2)==0)
	            {
	                nuevoEmpleado=employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
	                printf("\n---------------------------\n");
	                /*printf("\nID de cliente: %d\nNombre: %s\nEdad: %d\nCuit: %s\nDireccion: %s\nLocalidad: %s\n",
	                auxId,auxNombre,auxCuit,auxEdad,auxDireccion,auxLocalidad);*/
	                ret=0;
	            }
	    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* emp;
	int i;
	if(pArrayListEmployee!=NULL && emp!=NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			emp=ll_get(pArrayListEmployee,i);
			fwrite(emp,sizeof(Employee),ll_len(pArrayListEmployee),pFile);
		}
	}

    return 1;
}

int generarIdEmpleado(void)
{
    static int idMax=1;
    return idMax++;
}

