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
int get_String (char* mensaje, char* mensajeError, int max, char* auxiliar)
{

    int todoOk = 0;
    char aux[30];
    int numeros;

    printf("%s", mensaje);
    fflush(stdin);
    gets(aux);
    numeros = atoi(aux) ;
    if (strlen(aux)<=max || numeros == 0)
    {
        todoOk = 1;
    }

    while (strlen(aux)>max || numeros != 0 )
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(aux);
        numeros = atoi(aux) ;
        if (strlen(aux)<=max || numeros == 0)
        {
            todoOk = 1;
        }

    }

    strcpy(auxiliar,aux);


    return todoOk;
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


/** \brief Muestra mensaje para pedir un int y lo valida
 *
 * \param char* mensaje para pedir numero
 * \param char* mensaje en caso que se ingrese dato erroneo
 * \param int determina si acepta numeros negativos (1 para si, 0 para no)
 * \param int* puntero a variable a cargar tras validacion
 * \return devuelve 1 si valido OK, 0 si no.
 */
int validaInt (char* mensaje, char* mensajeError, int negativos, int* Pauxiliar)
{

    int todoOK = 0;
    int esNumero;

    printf("%s",mensaje);
    fflush(stdin);
    esNumero = scanf("%d",Pauxiliar);
    //printf("%d", esNumero);

    if (negativos == 0)
    {
        while ((*Pauxiliar) < 0 || !esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%d",Pauxiliar);

        }
        todoOK = 1;

    }
    else if (negativos == 1)
    {
        while (!esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%d",Pauxiliar);

        }
        todoOK = 1;
    }

    return todoOK;
}
