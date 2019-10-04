#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#include "Publicidad.h"
#include "SubMenuYMenu.h"

int menu(Pantalla *listPan,int lenPan,Publicidad *listPub,int lenPub)
{
    /*menu(listPersonas,CANT);*/
    pan_initPantalla(listPan,lenPan);
    pub_initPublicidad(listPub,lenPub);
    pan_addPantalla(listPan,lenPan,1,"lg","mitre",45,1);
    pan_addPantalla(listPan,lenPan,2,"sony","corrientes",25,2);
    pan_addPantalla(listPan,lenPan,3,"samsung","santafe",15,2);
    pan_addPantalla(listPan,lenPan,4,"sanyo","belgrano",30,1);
    pub_addPublicidad(listPub,lenPub,1,2,10,"205","lucia");
    pub_addPublicidad(listPub,lenPub,2,1,10,"205","lucia");
    pub_addPublicidad(listPub,lenPub,3,3,5,"200","jona");
    pub_addPublicidad(listPub,lenPub,4,4,10,"203","jona");
    int opciones;
    int auxId;
    int auxPos;
    do
    {
        printf("\n------------------------\n");

        {
            opciones=subMenuPantalla();
            switch(opciones)
            {
            case 1:
                if(pan_altaPantalla(listPan,lenPan)==0)
                {
                    printf("\n------------------------\n");
                    printf("\n\tALTA EXITOSA\n");
                }
                else
                {
                    printf("ERROR,No hay lugar");
                }
                break;
            case 2:
                pan_printfPantalla(listPan,lenPan);
                if(pan_modificarPantalla(listPan,lenPan,auxId)==0)
                {
                    printf("\nModificacion exitosa");
                }
                else
                {
                    printf("\nNO EXISTE ID.");
                }
                break;
            case 3:

                pan_printfPantalla(listPan,lenPan);
                if(utn_getValidInt("\nIngrese id: ","ERROR",&auxId,1,1000,2)==0)
                {
                    if(pan_buscarPantallaPorId(listPan,lenPan,auxId,&auxPos)!=-1)
                    {
                        pan_bajaPantalla(listPan,lenPan,auxId);
                        if(pub_buscarPublicidadPorIdPan(listPub,lenPub,auxId,&auxPos)!=-1)
                        {
                            pub_bajaPublicidad(listPub,lenPub,auxId);
                        }
                        printf("\nBAJA EXITOSA\n");
                    }
                    else
                    {
                        printf("\nNO EXISTE ID.");
                    }
                }
                break;
            case 4:
                pan_printfPantalla(listPan,lenPan);
                if(pub_altaPublicidad(listPub,lenPub,listPan,lenPan)==0)
                {
                    printf("\nAlta exitosa");
                }
                else
                {
                    printf("\nError");
                }
                break;
            case 5:
                if(pub_modificarPublicacion(listPub,lenPub,auxId)==0)
                {
                    printf("\nModificaciones exitosas");
                }
                else
                {
                    printf("\nError, no se pudo modificar los datos");
                }
                break;
            case 6:
                if(pub_bajaPublicidadPorCuit(listPub,lenPub)==0)
                {
                    printf("Baja exitosa");
                }
                else
                {
                    printf("Error, no se pudo dar la baja");
                }
                break;
            case 7:
                if(pub_facturacionPorCuit(listPub,lenPub,listPan,lenPan)==0)
                {
                    printf("\nFACTURACION TOTAL");
                }
                else
                {
                    printf("\nNO HAY FACTURACION");
                }

                break;
            case 8:
                if(pub_printfPublicidad(listPub,lenPub,listPan,lenPan)==0)
                {
                    printf("Alta de Publicidad");
                }
                else
                {
                    printf("No se encontro publicidad");
                }
                break;
            case 9:
                 if(pan_printfPantalla(listPan,lenPan)!=-1)
                {
                    printf("Alta de pantalla");
                }
                else
                {
                    printf("No se encontro pantallas");
                }
                break;
            case 10:
                if(pub_facturacionesDeClientes(listPub,lenPub,listPan,lenPan)==0)
                {
                    printf("\nTodos los clientes ok");
                }
                else
                {
                    printf("\nError.10.");
                }
                break;
            case 11:
                /*clienteConImporteMasAlto(listPub,lenPub,listPan,lenPan);Falta terminar*/
                break;
            case 12:
                break;
            default:
                printf("opcion incorrecta.");
                break;
            }
        }
    }while(opciones!=12);
        return 0;
}

int subMenuPantalla()
{
    int opciones;
    printf("\n1.Alta de pantalla");
    printf("\n2.Modificar datos de pantalla");
    printf("\n3.baja de pantalla");
    printf("\n4.Contratar una publicidad");
    printf("\n5.Modificar condiciones de publicacion");
    printf("\n6.Cancelar contratacion");
    printf("\n7.Consulta facturacion");
    printf("\n8.Listar contrataciones");
    printf("\n9.Listar pantallas");
    printf("\n10.Informar contrataciones");
    printf("\n11.Informar cliente con mayor importe");
    printf("\n12.Salir");
    printf("\nIngrese Opcion: ");
    fflush(stdin);
    scanf("%d",&opciones);
    return opciones;
}
