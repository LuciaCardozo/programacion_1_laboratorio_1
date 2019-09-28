#ifndef ASOCIADOS_H_INCLUDED
#define ASOCIADOS_H_INCLUDED

typedef struct
{
    int idAsociado;
    int isEmpty;
    char dni[20];
    char nombre[50];
    char apellido[50];
    int edad;
}Asociados;
int asoc_initAsociados(Asociados *listAsoc,int lenAsoc);
int asoc_buscarLugarLibre(Asociados *listAsoc,int lenAsoc);
int asoc_addAsociados(Asociados *listAsoc, int lenAsoc, int id, char *nombre,char *apellido,char *dni,int edad);
int asoc_altaAsociados(Asociados *listAsoc,int lenAsoc);
int asoc_printfAsociados(Asociados *listAsoc,int lenAsoc);
int asoc_printfAsociadosPorId(Asociados *listAsoc,int lenAsoc,int id);
int asoc_buscarAsociadoPorId(Asociados *listAsoc,int lenAsoc,int id,int *posicion);
int asoc_bajaAsociado(Asociados *listAsoc,int lenAsoc,int id);
int asoc_modificarAsociado(Asociados *listAsoc, int lenAsoc,int id);

#endif /*ASOCIADOS_H_INCLUDED*/
