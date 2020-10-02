#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"
#include <ctype.h>

void mostrarSectores(eSector sectores[], int tam)
{

    printf("************** Sectores ****************\n\n");
    printf("Id     Descripcion \n\n");

    for (int i =0; i < tam; i ++)
    {
        printf("%d     %10s     \n", sectores[i].id, sectores[i].descripcion);
    }


}
