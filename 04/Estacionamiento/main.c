#include "labibliopa.h"

int main()
{
    int i;
    sPersona unaPersona[A];
    sVehiculo unAutito[A];
    hardcodePersonas(unaPersona, A);
    mostrarPersonas(unaPersona, A);
    hardcodeoAutos(unAutito, A);
    mostrarAutitos(unAutito, A);
    i = buscarPorPatente(unAutito,A);
    if(i!=-1)
    {
        mostrarUnaPersona(unaPersona[i]);
    }
    else
    {
        printf("\nNO CAPO NADA QUE VER LA PATENTE\n");
    }
    return 0;
}



