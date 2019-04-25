#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
}Pantalla;

int pan_initArray(Pantalla *list, int limite);
int pan_buscarLugarLibre(Pantalla *list, int limite);
//int pan_idAutoIncremental(int limite);
int pan_alta(Pantalla *list, int limite);




#endif // PANTALLA_H_INCLUDED
