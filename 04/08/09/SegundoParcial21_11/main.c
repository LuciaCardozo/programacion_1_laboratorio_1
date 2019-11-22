#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "parser.h"
#include "cachorros.h"
#include "utn.h"
int generarArchivo(char* fileName,LinkedList* listaEmpleados);

int main()
{
    LinkedList* listaCachorro;
    listaCachorro = ll_newLinkedList();

    int opcion;
    char archivo[50];
    do
    {
        if(utn_getValidInt("\n1.Cargar archivo\n2.Imprimir lista\n3.Filtrar menores de 45 dias\n4.Filtrar machos\n5.Generar listado de callejeros\nSalir\nIngrese Opcion: "
            ,"\nError",&opcion,1,6,2) == 0)
            {
                switch(opcion)
                {
                        case 1:
                        printf("Ingrese nombre del archivo: ");
                        scanf("%s",archivo);
                        parser_parseEmpleados(archivo,listaCachorro);
                    break;
                        case 2:
                        controller_ListCachorro(listaCachorro);
                    break;
                        case 3:
                        if(generarArchivo("archivoGenerado.csv",ll_filter(listaCachorro,em_filtrarMenoresDe45Dias))==1)
                        {
                            printf("\nSe creo el archivo");
                        }
                    break;
                        case 4:
                        if(generarArchivo("archivoGeneradoDos.csv",ll_filter(listaCachorro,em_filtrarMachos))==1)
                        {
                            printf("\nSe creo el archivo");
                        }
                    break;
                        case 5:
                        controller_ListCachorroCallejero(listaCachorro);
                    break;
                        case 6:
                    break;
                }
            }
    }while(opcion!=6);
    return 0;
}

int generarArchivo(char* fileName,LinkedList* listaCachorro)
{
    int ret = 0;
    Cachorro* pCach;
    FILE* pFile;
    int auxId;
    char auxNombre[50];
    int auxDia;
    char auxRaza[50];
    char auxReservado[3];
    char auxGenero[3];
    int i;
    if(fileName != NULL && listaCachorro != NULL)
    {
        pFile=fopen(fileName,"w");
        fprintf(pFile,"Id,Nombre,Dia,Raza,Reservado,Genero\n");
        for(i=0 ; i<ll_len(listaCachorro) ; i++)
        {
            pCach=ll_get(listaCachorro,i);
            cachorro_getId(pCach,&auxId);
            cachorro_getNombre(pCach,auxNombre);
            cachorro_getDia(pCach,&auxDia);
            cachorro_getRaza(pCach,auxRaza);
            cachorro_getReservado(pCach,auxReservado);
            cachorro_getGenero(pCach,auxGenero);
            fprintf(pFile,"%d,%s,%d,%s,%s,%s\n",auxId,auxNombre,auxDia,auxRaza,auxReservado,auxGenero);
        }
        fclose(pFile);
        ret = 1;
    }
    return ret;
}
