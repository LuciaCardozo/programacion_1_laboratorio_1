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

int pan_initPantalla(Pantalla *listPan,int lenPan);
int pan_buscarLugarLibre(Pantalla *listPan,int lenPan);
int pan_addPantalla(Pantalla *listPan, int lenPan, int idPan, char *name,char *adress,float precio,int tipo);
int pan_altaPantalla(Pantalla *listPan,int lenPan);
int pan_printfPantalla(Pantalla *listPan,int lenPan);
int pan_buscarPantallaPorId(Pantalla *listPan,int lenPan,int id,int *posicion);
int pan_bajaPantalla(Pantalla *listPan,int lenPan,int id);
int pan_modificarPantalla(Pantalla *listPan, int lenPan,int id);
int pan_printfPantallaPorId(Pantalla *listPan,int lenPan,int id);
int generarId(void);

#endif /* PANTALLA_H_INCLUDED */
