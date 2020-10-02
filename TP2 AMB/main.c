#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "sector.h"
#include"centurion.h"

#define TAM 1000
#define TAMSEC 5
#define CANTHARDCODE 6


int menu();


int main()
{
    char seguir = 's';
    char confirma;
    int proximoId =1000;

     int flag1 = 0;





    Employee list [TAM];
    eSector sectores [TAMSEC] = {{1, "Administracion"}, {2, "Manufactura"},{3, "Marketing"},{4,"Publicidad"},{5,"Tesoreria"}};


    //Inicializo para poder dar el alta.
    initEmployees(list, TAM);





    harcodearEmpleados(list,CANTHARDCODE);
    proximoId += CANTHARDCODE;

    do
    {



        switch(menu())
        {
        case 1:
            if(addEmployees(proximoId, list,TAM, sectores, TAMSEC))
            {
                proximoId++;
                flag1=1;
            }
            break;
        case 2:
            if(flag1){
             modifyEmployees(list, TAM, sectores, TAMSEC);
            }else{
             printf("DEBE INGRESAR PRIMERO A OPCION 1\n\n");

            }

            break;

        case 3:
            if(flag1){
            removeEmployee(list,TAM, sectores, TAMSEC);
            }else{
              printf("DEBE INGRESAR PRIMERO A OPCION 1\n\n");
            }
            break;
        case 4:
               if(flag1){
            system("cls");
              informar(list, TAM,sectores, TAMSEC);
               }else{
                printf("DEBE INGRESAR PRIMERO A OPCION 1\n\n");
               }
            break;

        case 5:

            printf("Confirmar Salida s/n: ");
            fflush(stdin);
            confirma = tolower(getchar());
            if (confirma == 's')
            {
                seguir = 'n';
            }
            break;

        }

        system ("pause");
    }
    while ( seguir =='s');



    return 0;
}

int menu()
{
    int opcion;


    system("cls");
    printf("************** ABM EMPLEADOS TP2 CENTURION CINTIA ********\n\n");
    printf("1. Alta Empleado\n");
    printf("2. Modificar Empleado\n");
    printf("3. Baja Empleado\n");
    printf("4. Informar\n");
    printf("5. Salir\n\n");

    utn_getNumero(&opcion, "Ingrese un numero: ", "ERROR!! Opcion invalida debe ingresar un numero del 1 al 5\n", 1, 5,2);


    return opcion;
}
