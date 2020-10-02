#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];


} eSector;


#endif // SECTOR_H_INCLUDED

void mostrarSectores(eSector sectores[], int tam);
