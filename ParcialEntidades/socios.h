#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idSocio;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    char sexo;

}Socios;


#endif // SOCIOS_H_INCLUDED

int socios_Inicializar(Socios array[], int size);                                    //cambiar socios
int socios_buscarEmpty(Socios array[], int size, int* posicion);                    //cambiar socios
int socios_buscarID(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socios
int socios_buscarInt(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socios
int socios_buscarString(Socios array[], int size, char* valorBuscado, int* indice);                    //cambiar socios
int socios_alta(Socios array[], int size, int* contadorID);                          //cambiar socios
int socios_baja(Socios array[], int sizeArray);                                      //cambiar socios
int socios_bajaValorRepetidoInt(Socios array[], int sizeArray, int valorBuscado);
int socios_modificar(Socios array[], int sizeArray);                                //cambiar socios
int socios_ordenarPorString(Socios array[],int size);                              //cambiar socios
int socios_listar(Socios array[], int size);                      //cambiar socios
int generadorId(void);


