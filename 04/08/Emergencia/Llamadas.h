#ifndef LLAMADAS_H_INCLUDED
#define LLAMADAS_H_INCLUDED
#include "Asociados.h"

typedef struct
{
    int idLlamada;
    int isEmpty;
    int idAsociado;
    int motivo;
    int estado;
    int idAmbulancia;
    float tiempo;
}Llamada;

int llam_iniLlamada(Llamada *listLlamada,int lenLlamada);
int llam_buscarLugarLibre(Llamada *listLlamada,int lenLlamada);
int llam_asignarAmbulancia(Llamada *listLlamada,int lenLlamada,Asociados *listAsoc,int lenAsoc);
int llam_buscarLlamadaPorId(Llamada *listLlamada,int lenLlamada,int id,int *posicion);
int llam_altaNuevaLlamada(Llamada *listLlamada,int lenLlamada,Asociados *listAsoc,int lenAsoc,int *posicion);
int llam_asignarAmbulancia(Llamada *listLlamada,int lenLlamada,Asociados *listAsoc,int lenAsoc);
int menu(Asociados *listAsoc,int lenAsoc,Llamada *listLlamada,int lenLlamada);
int llam_printfLlamadaPorId(Llamada *listLlamada,int lenLlamada,int id);
int llam_addLlamada(Llamada *listLlamada, int lenLlamada, int id,int idAsociado,int motivo,int estado);
int llam_printfLlamada(Llamada *listLlamada,int lenLlamada);

#endif /* LLAMADAS_H_INCLUDED*/
