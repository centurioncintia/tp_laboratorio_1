
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

int mostrarMenu()
{
   int opcion;


    system("cls");


    printf("************Menu calculadora****************\n\n");
    printf("1-INGRESAR EL 1er OPERANDO (A=X):\n");
    printf("2-INGRESAR EL 2do OPERANDO (B=Y): \n");
    printf("3-Calcular operaciones....\n a-Suma(A+B)\n b-Resta(A-B)\n c-Division(A/B)\n c-Multipicacion(A*B)\n e-Factorial(A!)(B!) \n");
    printf("4-INFORMA RESULTADOS\n");
    printf("5-SALIR \n\n");

    utn_getNumero(&opcion, "DEBE INGRESAR UNA OPCION :", "\nERROR...\nUSTED DEBE INGRESAR UN NUMERO DEL 1 AL 5 1 al 5\n\n", 1, 5,1);


    printf("\n");

    return opcion;
}





void mostrarCalculos(int numero1, int numero2)
{


    printf("**********Menu de Opciones********** \n\n");
    printf("3 Calcular  todas las operaciones \n\n");
    printf("a) Calcular la suma (%d+%d)\n\n", numero1, numero2);
    printf("b) Calcular la resta (%d-%d)\n\n", numero1, numero2);
    printf("c) Calcular la division (%d/%d)\n\n", numero1, numero2);
    printf("d) Calcular la multiplicacion (%d*%d)\n\n", numero1, numero2);
    printf("e) Calcular el factorial de (%d!) y el factorial de (%d!)\n\n",numero1, numero2);

}
