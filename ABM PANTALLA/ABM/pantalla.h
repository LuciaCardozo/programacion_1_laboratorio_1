#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    int isEmpty;
    int idPantalla;
    char nombre[51];
    char direccion[51];
    float precio;
    int tipo;
}Pantalla;
int pan_initArray(Pantalla* list, int limite);
int pan_buscarLugarLibre(Pantalla* list, int limite);
int generadorId(void);
int pan_altaPantalla(Pantalla* list, int limite);
int pan_printPantalla(Pantalla* list,int limite);
int pan_bajaPantalla(Pantalla* list,int limite);
int pan_buscarEmpleadoPorId(Pantalla* list, int limite,int idE);
int pan_obtenerListaFiltrada(Pantalla* list,Pantalla* auxList, int limite, char* nombre);
int pan_modificarPantalla(Pantalla* list, int limite);
int pan_orderID(Pantalla* list, int limite);



#endif // PANTALLA_H_INCLUDED
