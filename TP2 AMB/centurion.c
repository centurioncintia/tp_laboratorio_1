#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include "centurion.h"





int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

    int retorno = -1;
    int buffer;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
    {
        do
        {
            printf("%s", mensaje);

            if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }

            reintentos --;
            printf("%s", mensajeError);



        }
        while (reintentos >= 0);

    }


    return retorno;

}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{

    int retorno = -1;
    char bufferChar;


    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &bufferChar);
            bufferChar= toupper(bufferChar);
            if(bufferChar >= minimo && bufferChar <= maximo)
            {
                *pResultado =  tolower(bufferChar);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos --; // esto es decrementar porque reintentos viene cargado en 0,
            }

        }
        while (reintentos >= 0);
    }


    return retorno;

}

int getInt(int* pResultado)
{
    int retorno =-1;
    char buffer [4000];



    if (myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
    {
        retorno = 0;
        *pResultado = atoi(buffer);
    }


    return retorno;
}


int myGets(char* cadena, int longitud)
{

    fflush(stdin);
    fgets(cadena, longitud, stdin);
    cadena[strlen(cadena)-1] = '\0';

    return 0;
}



int esNumerica(char* cadena)
{
    int retorno =1;
    int i = 0;

    if(cadena[0] == '-')
    {
        i = 1;
    }
    for(  ; cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9'|| cadena [i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int verifica(void)
{
    char letra;
    printf("\nIngrese opcion...S/N?");
    letra=toupper(getchar());
    if(!((letra=='S')||(letra=='N')))
    {
        printf("\nERROR, Ingrese una letra valida para continuar s/n... ");
        letra=toupper(getchar());
    }
    return letra;
}


void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
