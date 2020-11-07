#include "Employee.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include <ctype.h>


Employee* employee_new()
{

    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if (nuevoEmpleado != NULL)
    {

        nuevoEmpleado->id = 0 ;
        strcpy(nuevoEmpleado->nombre," ");
        nuevoEmpleado->sueldo = 0;
        nuevoEmpleado->horasTrabajadas = 0;
    }

    return nuevoEmpleado;

}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* nuevoEmp = employee_new();

    if (nuevoEmp != NULL)//Si conseguí espacio de memoria llamo a todos los setters, Si todo está bien setters se lo asigna a nuevo empleado
    {
        if( !(employee_setId(nuevoEmp,atoi (idStr))//este parentesis va a ser verdadero cuando todos los seters hayan contestado 1, &&  cuando estos den uno el que esta encerraro, osea legajo me da 1
                && employee_setNombre(nuevoEmp, nombreStr)
                &&  employee_setHorasTrabajadas(nuevoEmp, atoi(horasTrabajadasStr))
                && employee_setSueldo(nuevoEmp, atoi(sueldoStr))))
        {
            employee_delete(nuevoEmp);
            nuevoEmp = NULL; // si pude cargar todos los campos no libero, de lo contrario delete libera el espacio nuevamente.
        }
    }
    return nuevoEmp;

}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{

    int todoOk = 0;

    if(this!= NULL && id >0)//Se pone la validacion que necesito segun rango.
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

    if(this!= NULL && horasTrabajadas >0)//se pone la validacion que necesito segun ranfgo por ejmplo de 0 a 500
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

int employee_getId(Employee* this,int* id)
{

    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
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

    printf("  Id        Nombre  Horas trabajadas  \n\n");

    for (int i=0; i<ll_len(listaEmp); i++)
    {

        mostrarEmpleado(listaEmp, i);

    }

}

void mostrarEmpleado(LinkedList* listaEmp, int indice)
{

    Employee* emp = (Employee*) employee_new();

    emp = ll_get(listaEmp, indice);
    printf("%d     %10s       %d      %d \n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);



}

int ordenaPorId(void* empleadoA, void* empleadoB)
{

    int orden;
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


