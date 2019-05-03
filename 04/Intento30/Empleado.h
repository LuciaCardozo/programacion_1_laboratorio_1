#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    int legajo;
    int isEmpty; ///1vacio - 0ocupado
    int idEmpleado; ///clave unica de identidad univoca
}Empleado;

int Empleado_inicializarArray(Empleado* pEmpleado,int limite);
int Empleado_mostrarArray(Empleado* pEmpleado,int limite);

int Empleado_alta(Empleado* pEmpleado,int limite,int pIndex,int idE,char* msgE);
int Empleado_modifyFromLegajo(Empleado* pEmpleado, int limite,char* msgE);
int Empleado_modifyFromID(Empleado* pEmpleado, int limite,char* msgE);
int Empleado_bajaLogica(Empleado* pEmpleado, int limite,char* msgE);


int Empleado_ordenarNameAtoZ(Empleado* pEmpleado, int limite);
int Empleado_ordenarSurnameAtoZ(Empleado* pEmpleado, int limite);
int Empleado_orderByLegajo(Empleado* pEmpleado, int limite);
int Empleado_orderByID(Empleado* pEmpleado, int limite);

int Empleado_findLegajo(Empleado* pEmpleado, int limite, int valor);
int Empleado_findID(Empleado* pEmpleado, int limite, int idE);
int Empleado_posLibre(Empleado* pEmpleado, int limite);



#endif // EMPLEADO_H_INCLUDED
