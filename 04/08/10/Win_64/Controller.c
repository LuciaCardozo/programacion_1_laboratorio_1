#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
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
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_buscarEmployeePorId(LinkedList* pArrayListEmployee,int id,int* posicion)
{
    Employee* emp;
    int auxId;
    int ret = -1;
    int i;
    int len;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            emp=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(emp,&auxId);
            if(auxId==id)
            {
                *posicion=i;
                ret = 0;
            }
        }
    }
    return ret;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    nuevoEmpleado=employee_new();
    int ret = -1;
    char auxNombre[51];
    char auxHoras[5];
    char auxSueldo[10];
    int auxId;
    char auxIdStr[20];
    if(pArrayListEmployee!=NULL)
    {
        if(utn_getValidName(auxNombre)==0 &&
                utn_getValidStringNumerico("Ingrese horas trabajadas: ","\nError","\nError, excediste el maximo de caracteres",auxHoras,5,2)==0 &&
                utn_getValidStringNumerico("Ingrese sueldo: ","\nError","\nError, excediste el maximo de caracteres",auxSueldo,10,2)==0)
        {
            auxId=ll_len(pArrayListEmployee);
            employe_idInit(auxId);
            itoa(auxId,auxIdStr,10);
            nuevoEmpleado=employee_newParametros(auxIdStr,auxNombre,auxHoras,auxSueldo);

            ll_add(pArrayListEmployee,nuevoEmpleado);
            printf("\n---------------------------\n");
            printf("\nID de cliente: %s\nNombre: %s\nHoras: %s\nSueldo: %s\n",
                   auxIdStr,auxNombre,auxHoras,auxSueldo);
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
    Employee* emp;
    emp=employee_new();
    int ret = -1;
    char auxNombre[51];
    int auxHoras;
    int auxSueldo;
    int auxId;
    int auxPos;
    int opciones;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getValidInt("\nIngrese id: ","\nError, no es un id valido",&auxId,0,999999,2)==0)
        {
            if(controller_buscarEmployeePorId(pArrayListEmployee,auxId,&auxPos)==-1)
            {
                printf("\nError, no es un id valido");
            }
            else
            {
                emp=(Employee*)ll_get(pArrayListEmployee,auxPos);
                controller_mostrarEmployeePorId(pArrayListEmployee,auxPos);
                if(utn_getValidInt("\n\tQue desea modificar?\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Cancelar\nIngrese opcion: ",
                                   "\nError, no es una opcion",&opciones,0,4,2)==0)
                {
                    do
                    {
                        switch(opciones)
                        {
                        case 1:
                            if(utn_getValidName(auxNombre)==0)
                            {
                                employee_setNombre(emp,auxNombre);
                            }
                            else
                            {
                                printf("\nError en la carga de nombre");
                            }
                            break;
                        case 2:
                            if(utn_getValidInt("\nIngrese horas trabajadas: ","\nError",&auxHoras,0,99999,2)==0)
                            {
                                employee_setHorasTrabajadas(emp,auxHoras);
                            }
                            else
                            {
                                printf("\nError en la carga de horas trabajadas");
                            }
                            break;
                        case 3:
                            if(utn_getValidInt("\nIngrese sueldo: ","\nError",&auxSueldo,0,99999,2)==0)
                            {
                                employee_setSueldo(emp,auxSueldo);
                            }
                            else
                            {
                                printf("\nError en la carga de sueldo");
                            }
                            break;
                        case 4:
                            break;
                        }
                        utn_getValidInt("\n\tDesea modificar otro dato?\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Cancelar\nIngrese opcion: ",
                                        "\nError, no es una opcion",&opciones,0,4,2);
                    }
                    while(opciones!=4);
                    ret=0;
                }
            }
        }
    }
    return ret;
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
    Employee* emp;
    emp=employee_new();
    int ret = -1;
    int auxId;
    int auxPos;
    int opciones;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getValidInt("\nIngrese id: ","\nError, no es un id valido",&auxId,0,999999,2)==0)
        {
            if(controller_buscarEmployeePorId(pArrayListEmployee,auxId,&auxPos)==-1)
            {
                printf("\nError, no es un id valido");
            }
            else
            {
                emp=(Employee*)ll_get(pArrayListEmployee,auxPos);
                controller_mostrarEmployeePorId(pArrayListEmployee,auxPos);
                if(utn_getValidInt("\nDesea eliminar los siguientes datos?\n1.Si\n2.No\n","\nError, opcion invalida",&opciones,1,2,2)==0)
                {
                    switch(opciones)
                    {
                        case 1:
                            employee_delete(emp);
                            ll_remove(pArrayListEmployee,auxPos);
                            printf("\nBaja Exitosa");
                            break;
                        case 2:
                            printf("\nCancelacion Exitosa");
                            break;
                    }
                    ret=0;
                }
            }
        }
    }
    return ret;
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
    int i;
    int ret=0;
    int len;
    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            len=ll_len(pArrayListEmployee);
            for(i=0; i<len; i++)
            {
                controller_mostrarEmployeePorIdTipoExcel(pArrayListEmployee,i);
            }
            ret=0;
        }
        else
        {
            printf("No existen registros cargados.");
        }
    }
    return ret;
}

int controller_mostrarEmployeePorIdTipoExcel(LinkedList* pArrayListEmployee, int index)
{
    Employee* emp;
    int auxId;
    char auxNombre[4096];
    int auxHorasTrabajadas;
    int auxSueldo;
    int ret=0;
    if(pArrayListEmployee!=NULL && index>=0 && index<ll_len(pArrayListEmployee))
    {
        emp=(Employee*)ll_get(pArrayListEmployee,index);
        employee_getId(emp,&auxId);
        employee_getNombre(emp,auxNombre);
        employee_getHorasTrabajadas(emp,&auxHorasTrabajadas);
        employee_getSueldo(emp,&auxSueldo);
        printf("%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        ret=0;
    }
    return ret;
}

int controller_mostrarEmployeePorId(LinkedList* pArrayListEmployee, int index)
{
    Employee* emp;
    int auxId;
    char auxNombre[4096];
    int auxHorasTrabajadas;
    int auxSueldo;
    int ret=0;
    if(pArrayListEmployee!=NULL && index>=0 && index<ll_len(pArrayListEmployee))
    {
        emp=(Employee*)ll_get(pArrayListEmployee,index);
        employee_getId(emp,&auxId);
        employee_getNombre(emp,auxNombre);
        employee_getHorasTrabajadas(emp,&auxHorasTrabajadas);
        employee_getSueldo(emp,&auxSueldo);
        printf("\nId: %d\nNombre: %s\nHoras trabajadas: %d\nSueldo: %d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        ret=0;
    }
    return ret;
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
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
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
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}
