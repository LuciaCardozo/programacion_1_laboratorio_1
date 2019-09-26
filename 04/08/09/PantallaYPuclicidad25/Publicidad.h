#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

typedef struct
{
    int idPub;
    int isEmpty;
    int idPan;
    int cantidadDeDia;
    char cuit[20];
    char nombreArch[50];

}Publicidad;

int pub_initPublicidad(Publicidad *listPub,int lenPub);
int pub_buscarLugarLibre(Publicidad *listPub,int lenPub);
int pub_addPublicidad(Publicidad *listPub, int lenPub, int idPub,int idPantalla,int cantDeDia,char *cuit,char *nombre);
int pub_altaPublicidad(Publicidad *listPub,int lenPub,Pantalla *listPan,int lenPan);
int pub_printfPublicidad(Publicidad *listPub,int lenPub,Pantalla *listPan,int lenPan);
int pub_buscarPublicidadPorId(Publicidad *listPub,int lenPub,int id,int *posicion);
int pub_bajaPublicidad(Publicidad *listPub,int lenPub,int id);
int pub_modificarPublicacion(Publicidad *listPub, int lenPub,int id);
int pub_buscarPublicidadPorIdPan(Publicidad *listPub,int lenPub,int idPan,int *posicion);
int pub_buscarPublicidadPorCuit(Publicidad *listPub,int lenPub,char *cuit,int *posicion);
int pub_printfPublicidadPorCuit(Publicidad *listPub,int lenPub,char *cuit);
int pub_bajaPublicidadPorCuit(Publicidad *listPub,int lenPub,int idPan);


#endif // PUBLICIDAD_H_INCLUDED
