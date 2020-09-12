#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "calculadora.h"
#include "utn.h"



int main()
{
    char seguir ='s';
    int operando1;
    int operando2;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;


    mostrarMenu();

    do
    {
        switch(mostrarMenu())
        {
        case 1:
            printf("Ingreso un numero: ");
            scanf("%d",&operando1);
            flag1 =1;
            break;

        case 2:
            if(flag1)
            {
                printf("Ingrese otro numero: ");
                scanf("%d",&operando2);
                flag2 =1;
            }
            else
            {
                printf("Antes debe ingresar la opcion 1\n\n");
            }
            break;

        case 3:
            if(flag2)
            {
                mostrarCalculos(operando1,operando2);
                flag3 =1;
            }
            else
            {
                printf("Antes debe ingresar la opcion 1 y opcion 2\n\n");
            }
            break;

        case 4:
            if (flag3)
            {

                printf("El resultado de %d + %d es: %d\n\n\n ",operando1,operando2, suma(operando1,operando2));
                printf("El resultado de %d - %d es: %d\n\n\n ",operando1,operando2, resta(operando1, operando2));
                if(operando2 ==0)
                {
                    printf("ERROR..No se puede dividir por 0...\n\n");
                }
                else
                {
                    printf("El resultado de %d / %d es: %.2f\n\n\n ",operando1,operando2, division(operando1, operando2));
                }
                printf("El resultado de %d * %d es: %d\n\n\n ",operando1,operando2, multiplicacion(operando1, operando2));
                printf("El Factorial de %d es %lld y el factorial de %d es %lld \n\n",operando1,factorial(operando1),operando2, factorial(operando2) );
            }
            else
            {
                printf("Para obtener los resultados es necesario haber ingresado las opciones 1,2 y 3 del menu...\n\n");
            }
            break;

        case 5:
            seguir ='n';
            break;


        default:
            printf("Debe ingresar una opcion valida\n\n");
            printf("\n\n\n");

        }
        system("pause");
    }
    while(seguir=='s');

    return 0;
}
