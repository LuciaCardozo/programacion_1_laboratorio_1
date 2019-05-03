#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
    int idEmployee;
    int isEmpty;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
}Employee;

int emp_initEmployees(Employee* list, int len);//inicia el array
int emp_addEployees(Employee* list,int len);//añadimos a un empleado
int emp_findEmployeeById(Employee* list, int len, int idE);//encontrar empleado por id
int emp_removeEmployee(Employee* list, int len, int idE);//remover empleado
int emp_sortEmployees(Employee* list, int len, int order);//ordenar empleados
int emp_printEmployees(Employee* list, int len);//mostrar empleados
int emp_buscarLugarLibre(Employee* employees,int limite);//busca un lugar libre (ocupado o disponible)
int proximoId(void);


#endif // ARRAYEMPLOYEES_H_INCLUDED
