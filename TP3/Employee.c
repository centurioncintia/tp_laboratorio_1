#include "Employee.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include <ctype.h>
#include "centurion.h"
#include "controller.h"


Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* nuevoEmp = employee_new();

    if (nuevoEmp != NULL) // Si consegui espacio de memoria llamo a todos los setters, si Todo esta OK setter asigna los campos a un nuevo empleado.
    {
        employee_setId(nuevoEmp, atoi(idStr));
        employee_setNombre(nuevoEmp, nombreStr);
        employee_setHorasTrabajadas(nuevoEmp, atoi(horasTrabajadasStr));
        employee_setSueldo(nuevoEmp, atoi(sueldoStr));
    }
    else
    {
        employee_delete(nuevoEmp); //Si No pude cargar los empleados tengo que liberar memoria.
        nuevoEmp = NULL;          //Nuevo empleado debe apuntar a NULL.
    }

    return nuevoEmp;
}


void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)//CAPA DE VALIDACION
{
    int todoOk = 0;

    if(this!= NULL && id >=0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;

}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if(this!= NULL && horasTrabajadas >0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{

    int todoOk = 0;

    if(this!= NULL && sueldo >0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;

}

int employee_getId(Employee* this,int* id)//OBTENER CAMPO ID de la persona
{
                                        //Se encarga de leer el id y copiarlo
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id; // Si esta ok se lo cargo en la estructura
        todoOk = 1;
    }

    return todoOk;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);

        todoOk = 1;
    }
    return todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int todoOk = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this-> horasTrabajadas;

        todoOk = 1;
    }
    return todoOk;

}

int employee_getSueldo(Employee* this,int* sueldo)
{

    int todoOk = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this-> sueldo;

        todoOk = 1;
    }
    return todoOk;

}


void mostrarEmpleados(LinkedList* listaEmp)
{
    printf("\n\n");
    printf("  Id        Nombre    Horas trabajadas     Sueldo \n");
    printf("------------------------------------------------------------\n\n");
    for (int i=0; i<ll_len(listaEmp); i++)
    {
        mostrarEmpleado(listaEmp, i);
    }

}

void mostrarEmpleado(LinkedList* listaEmp, int indice)
{

    int auxId;
    char auxNombre[20];
    int auxHoras;
    int auxSueldo;

    Employee* emp;

    if (listaEmp != NULL && indice >=0)
        {
        emp = ll_get(listaEmp, indice);
        employee_getId(emp, &auxId);
        employee_getNombre(emp, auxNombre);
        employee_getHorasTrabajadas(emp, &auxHoras);
        employee_getSueldo(emp, &auxSueldo);
        }

printf("%4d     %10s       %4d      %4d \n", auxId, auxNombre, auxHoras, auxSueldo);

}

int employee_sort(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int orden;
    int opcion;

    if(pArrayListEmployee != NULL)
    {

        system("cls");
        printf("\n\n******************************* Ordenar Empleados ****************************************");
        printf("\n-----------------------------------------------------------------------------------------\n\n");
        printf("1.Ordenar Id\n");
        printf("2.Ordenar Nombre\n");
        printf("3.Ordenar Horas Trabajadas\n");
        printf("4.Ordenar Sueldo\n");
        printf("5.Salir\n");
        utn_getNumero(&opcion, "\nIngrese un numero del submenu: ", "Error debe ingresar un numero valido\n", 1, 5,2);


        switch(opcion)
        {
        case 1:

            printf("Ingrese 0 para ordenar DESC o 1 ASC: ");
            scanf("%d", &orden);
            printf("Ordenando por ID......!!\n");
            ll_sort(pArrayListEmployee, ordenaPorId, orden);
            controller_ListEmployee(pArrayListEmployee);
            todoOk = 0;
            break;
        case 2:

            printf("Ingrese 0 para ordenar DESC o 1 ASC: ");
            scanf("%d", &orden);
            printf("Ordenando por Nombre......!!\n");
            ll_sort(pArrayListEmployee, ordenaPorNombre, orden);
            controller_ListEmployee(pArrayListEmployee);
            todoOk = 0;
            break;

        case 3:

            printf("Ingrese 0 para ordenar DESC o 1 ASC: ");
            scanf("%d", &orden);
            printf("Ordenando por Horas trabajadas......!!\n");
            ll_sort(pArrayListEmployee,ordenaPorHoras, orden);
            controller_ListEmployee(pArrayListEmployee);
            todoOk = 0;
            break;

        case 4:
            printf("Ingrese 0 para ordenar DESC o 1 ASC: ");
            scanf("%d", &orden);
            printf("Ordenando por Sueldo......!!\n");
            ll_sort(pArrayListEmployee, ordenaPorSueldo, orden);
            controller_ListEmployee(pArrayListEmployee);
            todoOk = 0;
            break;

        case 5:
            break;
        default:
            printf("No es una opcion valida\n");
            break;
        }
    }
    return todoOk;
}



int ordenaPorId(void* empleadoA, void* empleadoB)
{

    int orden =0;
    int idA;
    int idB;

    employee_getId(empleadoA, &idA);
    employee_getId(empleadoB, &idB);


    if (idA > idB)
    {
        orden = 1;
    }
    else if (idA < idB)
    {
        orden = -1;
    }
    return orden;
}


int ordenaPorNombre(void* empleadoA, void* empleadoB)
{

    int orden;
    char nombre1[20];
    char nombre2[20];

    employee_getNombre(empleadoA, nombre1);
    employee_getNombre(empleadoB, nombre2);

    if (strcmp(nombre1, nombre2) > 0)
    {
        orden = 1;
    }
    else if (strcmp(nombre1, nombre2) < 0)
    {
        orden = -1;
    }


    return orden;
}


int ordenaPorHoras(void* empleadoA, void* empleadoB)
{
    int orden;
    int horas1;
    int horas2;

    employee_getHorasTrabajadas(empleadoA,&horas1);
    employee_getHorasTrabajadas(empleadoB,&horas2);

    if (horas1 > horas2)
    {
        orden = 1;
    }
    else if (horas1 < horas2)
    {
        orden = -1;
    }

    return orden;
}


int ordenaPorSueldo(void* empleadoA, void* empleadoB)
{
    int orden;
    int sueldoA;
    int sueldoB;

    employee_getSueldo(empleadoA, &sueldoA);
    employee_getSueldo(empleadoA, &sueldoB);

    if (sueldoA > sueldoB)
    {
        orden = 1;

    }
    else if (sueldoA < sueldoB)
    {
        orden = -1;
    }


    return orden;
}

int menuModificaEmpleado()
{

    int opcion;

    system("cls");
    printf("**** MODIDIFICAR EMPLEADO ****\n\n");
    printf("1. Modificar Nombre.\n");
    printf("2. Modificar Horas trabajadas.\n");
    printf("3. Modificar Sueldo.\n");
    printf("4. Salir\n");

   utn_getNumero(&opcion, "\nIngrese un numero del submenu: ", "Error debe ingresar un numero valido\n", 1, 4,1);

    return opcion;
}


/** \brief Modifica el nombre de un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */
int modificaNombre(LinkedList* lista,int  index)
{

    int todoOk = 0;
    char auxNombre[30];

    Employee* nuevoEmpleado = (Employee*) employee_new();
    nuevoEmpleado = ll_get(lista, index);

    if (nuevoEmpleado != NULL)
    {
        get_String("Ingrese un Nombre: ", "Error ingrese un nombre valido: ", 30, auxNombre);

        employee_setNombre(nuevoEmpleado,auxNombre);

        todoOk = 1;
    }
    else
    {

        printf("No se pudo modificar el nombre");

    }

    return todoOk;
}

/** \brief Modifica las horas trabajadas por un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */
int modificaHoras(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int horas;

    Employee* nuevoEmpleado = (Employee*) employee_new();
    nuevoEmpleado = ll_get(lista, index);

    if (nuevoEmpleado != NULL)
    {
        validaInt("Ingrese nueva cantidad de horas trabajdas: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese nueva cantidad de horas trabajdas: ",0, &horas);

        employee_setHorasTrabajadas(nuevoEmpleado,horas);
        todoOk = 1;

    }
    else
    {
        printf("No se pudo modificar las horas trabajadas");
    }


    return todoOk;
}

/** \brief Modifica el sueldo de un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */
int modificaSueldo(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int sueldo;

    Employee* nuevoEmpleado = (Employee*) employee_new();
    nuevoEmpleado = ll_get(lista, index);

    if (nuevoEmpleado != NULL)
    {
        validaInt("Ingrese nuevo sueldo: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese nuevo sueldo: ",0, &sueldo);

        employee_setSueldo(nuevoEmpleado,sueldo);
        todoOk = 1;
    }
    else
    {
        printf("No se pudo modificar el sueldo");
    }

    return todoOk;
}


