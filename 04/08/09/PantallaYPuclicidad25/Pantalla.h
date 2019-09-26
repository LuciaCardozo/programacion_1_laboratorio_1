#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct
{
    int idPan;
    int isEmpty;
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
}Pantalla;

int pan_initPantalla(Pantalla *list,int len);
int pan_buscarLugarLibre(Pantalla *list,int len);
int pan_addPantalla(Pantalla *list, int len, int idPan, char *name,char *adress,float precio,int tipo);
int pan_altaPantalla(Pantalla *list,int len);
int pan_printfPantalla(Pantalla *list,int len);
int pan_buscarPantallaPorId(Pantalla *list,int len,int id,int *posicion);
int pan_bajaPantalla(Pantalla *list,int len,int id);
int pan_modificarPantalla(Pantalla *list, int len,int id);
int menu(Pantalla *list,int len);

#endif /* PANTALLA_H_INCLUDED */
