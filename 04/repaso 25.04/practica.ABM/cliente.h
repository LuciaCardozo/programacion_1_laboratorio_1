#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    int isEmpty;
    int idCliente;
    char nombre[50];
    char apellido[50];
    char dni[10];
}ECliente;
int cliente_initArray(ECliente* list,int limite);
int buscarLugarLibre(ECliente* list, int limite);
int cliente_alta(ECliente* list, int limite);

#endif // CLIENTE_H_INCLUDED
