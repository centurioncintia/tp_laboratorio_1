#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "centurion.h"

int main()
{

      int option=0;
      int flag=0;

     LinkedList* listaEmpleados = ll_newLinkedList();

     do{
     system("cls");
     printf("************************** Menu Empleados LinkedList ****************************\n");
     printf("*********************************************************************************\n\n");
     printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
     printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
     printf("3. Alta de empleado\n");
     printf("4. Modificar datos de empleado\n");
     printf("5. Baja de empleado\n");
     printf("6. Listar empleados\n");
     printf("7. Ordenar empleados\n");
     printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
     printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
     printf("10. Salir\n");

     utn_getNumero(&option, "\nIngrese una Opcion para entrar al menu: ", "Error debe ingresar un numero valido \n", 1, 10,2);


         switch(option)
        {

            case 1:

                if(controller_loadFromText("data.csv",listaEmpleados)==1)
                {
                flag =1;
                system("cls");
                printf("\nEl archivo de TEXTO se abrio correctamente!!! \n\n");
                }
                break;

                case 2:
                if(flag ==1){
                if(controller_loadFromBinary("data.bin",listaEmpleados)==1)
                {
                 printf("\nEl archivo Binario abrio correctamente!!! \n\n");
                }
                }else
                {   system("cls");
                    printf("ANTES DEBE INGRESAR LA OPCION 1 Y CARGAR EL LISTADO DE EMPLEADOS...\n\n");
                }
                break;

                case 3:

                if(flag ==1){
                if(controller_addEmployee(listaEmpleados)==1)
                {
                    printf("ALTA DE EMPLEADOS EXITOSA!\n\n");
                }
                else
                {
                    printf("NO SE PUDO REALIZAR EL ALTA!\n\n");
                }
                }
                else
                {
                    system("cls");
                    printf("ANTES DEBE INGRESAR LA OPCION 1 Y CARGAR EL LISTADO DE EMPLEADOS...\n\n");
                }
                break;

                case 4:
                if(flag ==1){
                controller_editEmployee(listaEmpleados);
                }
                else
                {
                 system("cls");
                  printf("ANTES DEBE INGRESAR LA OPCION 1 Y CARGAR EL LISTADO DE EMPLEADOS...\n\n");
                }
                break;

                case 5:
                 if(flag ==1){
                controller_removeEmployee(listaEmpleados);
                 }
                 else{
                  system("cls");
                  printf("ANTES DEBE INGRESAR LA OPCION 1 Y CARGAR EL LISTADO DE EMPLEADOS...\n\n");
                 }
                break;

                case 6:
                 if(flag ==1){
                controller_ListEmployee(listaEmpleados);
                }
                else
                {
                   system("cls");
                  printf("ANTES DEBE INGRESAR LA OPCION 1 Y CARGAR EL LISTADO DE EMPLEADOS...\n\n");
                }
                break;

                case 7:
                if (flag ==1)
                {
               if(controller_sortEmployee(listaEmpleados)==0)
               {
                   printf("Ordenamiento Exitoso!!\n\n");
               }
                }else{

                  system("cls");
                  printf("ANTES DEBE INGRESAR LA OPCION 1 Y CARGAR EL LISTADO DE EMPLEADOS...\n\n");

                }
                break;

                case 8:
                if (flag ==1)
                {
                 controller_saveAsText("data.csv", listaEmpleados);
                }else
                {
                  system("cls");
                  printf("ANTES DEBE INGRESAR LA OPCION 1 Y CARGAR EL LISTADO DE EMPLEADOS...\n\n");
                }

                break;

                case 9:
                if (flag ==1)
                {
               controller_saveAsBinary("data.bin" , listaEmpleados);
                }
                else
                {
                  system("cls");
                  printf("ANTES DEBE INGRESAR LA OPCION 1 Y CARGAR EL LISTADO DE EMPLEADOS...\n\n");
                }

                break;

        }
           system ("pause");
    }while(option != 10);

    return 0;
}
