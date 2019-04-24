#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#ifndef __EEmpleados
#define __EEmpleados
typedef struct
{
    int isEmpty;
    int idEmpleado;
    char name[50];
    char lastName[50];
}EEmpleado;

int EEmpleado_initArray(EEmpleado *pEmpleado, int limite);
int EEmpleado_printDebugArray(EEmpleado *pEmpleado, int limite);
int EEmpleado_lugarLibreArray(EEmpleado *pEmpleado, int limite);
int EEmpleado_alta(EEmpleado *pEmpleado, int limite);
int EEmpleado_baja(EEmpleado *pEmpleado, int limite);
int EEmpleado_modificar(EEmpleado *pEmpleado, int limite);
int EEmpleado_ordenarNombre(EEmpleado *pEmpleado, int limite);
#endif // __EEmpleados



#endif // EMPLEADO_H_INCLUDED
