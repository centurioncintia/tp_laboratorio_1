#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);//falta sueldo
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void mostrarEmpleados(LinkedList* listaEmp);
void mostrarEmpleado(LinkedList* listaEmp, int indice);


int ordenaPorId(void* empleadoA, void* empleadoB);

int ordenaPorSueldo(void* empleadoA, void* empleadoB);
int ordenaPorHoras(void* empleadoA, void* empleadoB);
int ordenaPorNombre(void* empleadoA, void* empleadoB);



int employee_sort(LinkedList* pArrayListEmployee);

int menuModificaEmpleado();
int modificaId(LinkedList* lista,int  index);
int modificaNombre(LinkedList* lista,int  index);
int modificaHoras(LinkedList* lista,int  index);
int modificaSueldo(LinkedList* lista,int  index);



#endif // employee_H_INCLUDED
