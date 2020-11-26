#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "centurion.h"
#include <string.h>
#include <ctype.h>



static int obtenerId()
{

    static int id = 1000;

    id++;

    return id;
}


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

    if (f == NULL)
    {
        printf("No se  pudo abrir el archivo de texto\n");
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
    int todoOk =0;
    Employee* nuevoEmpleado = (Employee*) employee_new();


    char auxNombre[20];
    int auxSueldo;
    int auxHoras;



    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("-------------------Alta Empleado--------------------------\n");
        printf("-----------------------------------------------------------\n");


        get_String("Ingrese un Nombre: ", "Error ingrese un nombre valido: ", 30, auxNombre);
        utn_getNumero(&auxHoras, "\nIngrese cantidad de horas: ", "Error, Ingrese cantidad de horas\n", 1,150,100);
        utn_getNumero(&auxSueldo, "\nSueldo: ", "Error, Ingrese sueldo entre 30.000 y 100.000\n", 30000,100000,100);


        employee_setNombre(nuevoEmpleado, auxNombre);
        employee_setHorasTrabajadas(nuevoEmpleado, auxHoras);
        employee_setSueldo(nuevoEmpleado, auxSueldo);
        employee_setId(nuevoEmpleado, obtenerId());


        if (ll_add(pArrayListEmployee, nuevoEmpleado) == 0)
        {
            todoOk = 1;
        }

    }
    else
    {
        employee_delete(nuevoEmpleado); //libero memoria
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
    int todoOk =0;
    int id;
    int indice;
    int flag;
    int opcion;

    Employee* nuevoEmpleado = (Employee*) employee_new();
    mostrarEmpleados(pArrayListEmployee);

    if (pArrayListEmployee != NULL)
    {

        printf("\n\n************************ Modificar Empleado *****************************\n\n");



        printf("Seleccione Id para modificar Empleado: ");
        scanf("%d", &id );

        printf("\n\n");
        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {

            nuevoEmpleado = ll_get(pArrayListEmployee, i);
            if (nuevoEmpleado->id == id)
            {
                indice = i;
                flag = 1;
            }
        }
        if (flag)
        {
            todoOk =1;
            system("cls");
            printf("El empleado a modificar es: \n\n");

            printf("  ID        Nombre        Horas     Sueldo\n");
            printf("----------------------------------------------\n\n\n");
            mostrarEmpleado(pArrayListEmployee, indice);
            printf("\n\n");
            system("Pause");

            do
            {
                system("cls");
                printf("**** MODIDIFICAR EMPLEADO ****\n\n");
                printf("1. Modificar Nombre.\n");
                printf("2. Modificar Horas trabajadas.\n");
                printf("3. Modificar Sueldo.\n");
                printf("4. Salir\n");

                utn_getNumero(&opcion, "\nIngrese un numero del submenu: ", "Error debe ingresar un numero valido\n", 1, 4,1);

                system("cls");
                switch(opcion)
                {
                case 1:

                    if(modificaNombre(pArrayListEmployee, indice) == 1)
                    {
                        printf("\n\n");
                        printf("Nombre modificado con exito.\n\n");
                        printf(" ID          NOMBRE       HORAS     SUELDO\n\n");
                        mostrarEmpleado(pArrayListEmployee, indice);
                        printf("\n\n");
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    break;
                case 2:

                    if(modificaHoras(pArrayListEmployee, indice) == 1)
                    {
                        printf("\n\n");
                        printf("Horas trabajadas actualizadas con exito.\n\n");
                        printf(" ID          NOMBRE       HORAS     SUELDO\n\n");
                        mostrarEmpleado(pArrayListEmployee, indice);
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    break;
                case 3:

                    if(modificaSueldo(pArrayListEmployee, indice) == 1)
                    {
                        printf("\n\n");
                        printf("Sueldo modificado con exito.\n\n");
                        printf(" ID          NOMBRE       HORAS     SUELDO\n\n");
                        mostrarEmpleado(pArrayListEmployee, indice);
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    break;
                }
                system ("pause");
            }
            while(opcion !=4);
        }
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

    mostrarEmpleados(pArrayListEmployee);


    Employee* nuevoEmpleado = (Employee*) employee_new();



    if (pArrayListEmployee != NULL)
    {

        printf("\n\n************************ Baja Empleado ***************************\n");
        printf("*******************************************************************\n");


        do
        {
            printf("Seleccione Id para dar baja a Empleado: ");
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
                todoOk=1;
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
                    system("cls");
                    printf("  Se cancelo baja de empleado\n\n");

                }

            }
            else{
                system("cls");

                printf("No corresponde a un empleado activo\n\n");

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
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if(employee_sort(pArrayListEmployee) == 0)
        {
            printf("Empleados ordenados exitosamente.\n");
        }
    }
    else
    {
        printf("Error\n");
    }

    return retorno;
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
    Employee* empl = (Employee*) employee_new();
    FILE* f = fopen(path, "w");

    if (f == NULL)
    {
        printf("Error no se puede guardar Archivo\n");

    }
    else
    {
        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");

        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empl = ll_get(pArrayListEmployee, i);
            fprintf(f, "%d,%s,%d,%d\n", empl->id, empl->nombre, empl->horasTrabajadas, empl->sueldo );
        }
    }
    printf("Archivo modo Text guardado con exito!!\n\n");
    todoOk = 1;

    fclose(f);

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

    }

    for (int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        empl = ll_get(pArrayListEmployee, i);
        fwrite(empl, sizeof(Employee), 1, f );
    }

    printf("Archivo modo bin guardado con exito!!\n\n");
    todoOk =1;
    fclose(f);



    return todoOk;
}

