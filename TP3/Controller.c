#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "centurion.h"
#include <string.h>
#include <ctype.h>

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* f = fopen(path, "r");

    if(f == NULL)//debo validar siempre
    {
        printf("No se  pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    else if (parser_EmployeeFromText(f, pArrayListEmployee))
    {

        todoOk = 1;
    }


    fclose(f);

    return todoOk;

}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* f = fopen(path, "rb");

    if(f == NULL)//debo validar siempre
    {
        printf("No se  pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    else if (parser_EmployeeFromBinary(f, pArrayListEmployee))
    {
        todoOk = 1;
    }


    fclose(f);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado = (Employee*) employee_new();

    int todoOk =0;




    system("cls");
    printf("-------------------Alta Empleado------------\n");
    printf("---------------------------- ----------------\n");

    utn_getNumero(&nuevoEmpleado->id, "\nIngrese Id: ", "Error debe ingresar un numero valido entre a partir de 1000\n", 1001, 100000,2);
    get_String("Ingrese un Nombre: ", "Error ingrese un nombre valido: ", 30, nuevoEmpleado->nombre);
    utn_getNumero(&nuevoEmpleado->horasTrabajadas, "\nIngrese cantidad de horas: ", "Error, Ingrese cantidad de horas\n", 1,150,2);
    utn_getNumero(&nuevoEmpleado->sueldo, "\nSueldo: ", "Error, Ingrese sueldo entre 30.000 y 100.000\n", 30000,100000,2);

    if (ll_add(pArrayListEmployee, nuevoEmpleado) == 0)
    {
        todoOk = 1;
        printf("ALTA EXITOSA\n");


    }

    if (!todoOk)
    {
        employee_delete(nuevoEmpleado);
    }

    return todoOk;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int todoOk = 0;
    char nombre[20];
    //int indice;

    Employee* empl = (Employee*) employee_new();
   // empl = ll_get(pArrayListEmployee, indice);

    if (empl != NULL)
    {
        printf("Ingrese nuevo nombre: ");
         fflush(stdin);
         gets(nombre);

        printf("Se modifico el nombre %s por %s\n", empl->nombre, nombre);
        strcpy(empl->nombre, nombre);
        todoOk = 1;

    }
    else
    {

        printf("No se pudo modificar el nombre");

    }


    return todoOk;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    int indice;
    int flag = 0;
    char respuesta;
    Employee* nuevoEmpleado = (Employee*) employee_new();

    if (pArrayListEmployee != NULL)
    {
        system("cls");
        printf("**** Baja Empleado ****\n");

        do
        {
            printf("Seleccione Id para dar baja: ");
            scanf("%d", &id );
            for (int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = ll_get(pArrayListEmployee, i);
                if (nuevoEmpleado->id == id)
                {
                    indice = i;
                    flag = 1;
                    break;
                }

            }

            if (flag)
            {
                system("cls");
                printf("El empleado a eliminar es: \n\n\n");

                printf("  ID        Nombre        Horas     Sueldo\n");
                printf("----------------------------------------------\n");
                mostrarEmpleado(pArrayListEmployee, indice);
                printf("\n\nConfirma la baja del empleado (s/n)? ");
                fflush(stdin);
                respuesta = getchar();
                respuesta = tolower(respuesta);

                if (respuesta == 's' && ll_remove(pArrayListEmployee, indice)==0)
                {
                    printf("Baja de empleado Exitosa\n");

                }
                else
                {
                    printf("Se cancelo la baja\n");
                }

            }

        }
        while (flag == 0);



    }


    return todoOk;

}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    mostrarEmpleados(pArrayListEmployee);

    return 1;
}





/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOK =0;
    int opcion;
    int orden;



   do
   {
    system("cls");
    printf("\n\n************* Ordenar Empleados *********\n\n");
    printf("1.id\n");
    printf("2.Nombre\n");
    printf("3.Horas Trabajadas\n");
    printf("4.Sueldo\n");
    printf("5.Salir\n");
    utn_getNumero(&opcion, "\nIngrese un numero del submenu: ", "Error debe ingresar un numero valido\n", 1, 5,2);

    if(opcion < 5){
     printf("Ingrese  0 Desc o 1 Asc: ");
     scanf("%d",&orden);
    }



    switch(opcion)
    {

    case 1:
    ll_sort(pArrayListEmployee, ordenaPorId,orden);
    printf("Espere realizando ordenamiento....!!");
        break;

    case 2:

       ll_sort(pArrayListEmployee, ordenaPorNombre,orden);
        printf("Espere realizando ordenamiento....!!");

        break;

    case 3:

     ll_sort(pArrayListEmployee, ordenaPorHoras, orden);
      printf("Espere realizando ordenamiento....!!");
        break;

    case 4:
     ll_sort(pArrayListEmployee, ordenaPorSueldo, orden);
     printf("Espere realizando ordenamiento....!!");
        break;

        }


    }while(opcion != 5);


return todoOK;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* f = fopen(path,"w");
    Employee* empl = (Employee*) employee_new();

    if (f == NULL )
    {
        printf("Error no se puede guardar Archivo\n");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        empl = ll_get(pArrayListEmployee, i);

        fprintf(f, "%d,%s,%d,%d\n", empl->id, empl->nombre, empl->horasTrabajadas, empl->sueldo );


    }
    printf("Archivo guardado con exito!!\n");


    return todoOk;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* empl = (Employee*) employee_new();
    FILE* f = fopen(path, "wb");

    if (f == NULL)
    {
        printf("Error no se puede guardar Archivo\n");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        empl = ll_get(pArrayListEmployee, i);
        fwrite(empl, sizeof(Employee), 1, f );
    }

    printf("Archivo modo bin guardado con exito!!\n\n");
    fclose(f);


    return todoOk;
}








