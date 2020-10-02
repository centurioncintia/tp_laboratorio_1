#include "sector.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct
{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;


} Employee;


#endif // EMPLEADO_H_INCLUDED

//EMPLEADOS



/** \brief Muestra todos los empleados vector empleados
 *
 * \param Tamaño del vector empleados
 * \param vector sectores
 * \param tamaño del vector sector
 * \return
 *
 */

int printEmployees(Employee vec[], int tam, eSector sectores [], int tamSec);



/** \brief Muestra vector de un Empleado
 *
 * \param recibe un empleado
 * \param vector sector
 * \param tañamo del vector sectores
 * \return
 *
 */

void mostrarEmpleado(Employee x, eSector sectores [], int tamSec);





/** \brief Recorre el array y pone el campo isEmpty en 1 si hay lugar en el array.
 *
 * \param puntero a array Employee
 * \param tamaño del array
 * \return -1 si hay error, 0 si esta todo OK.
 *
 */

int initEmployees(Employee* list, int len);









/** \brief busca un empleado recibiendo como parametro de búsqueda su id
 *
 * \param recibe ID
 * \param vector empleado
 * \param tamaño del vector
 * \return -1 id no encontrado
 *
 */
int findEmloyeeById(int id,Employee vec[], int tam);




/** \brief Elimina un empleado, mostrara un  mensaje de error si no se encuentra id
 *
 * \param recibe vector empleado
 * \param recibe tamaño del vector
 * \param recibe vector sector
 * \param recibe tamaño del vector
 * \return -1 error  0 todoOk,
 *
 */
int removeEmployee(Employee vec[], int tam,eSector sectores [], int tamSec);



/** \brief Agrega en un array de empleados existente los valores recibidos como párametro en la primer posición.
 *
 * \param recibe id incremental
 * \param vector employee
 * \param tamaño del vector
 * \return 0 si está todo OK, -1 error
 *
 */
int addEmployees(int idx, Employee vec[], int tam, eSector sectores[], int tamSec);




/** \brief Modifica campos. Se accede a través de un submenu al campo a modificar.
 *
 * \param vector de empleados
 * \param tamaño del vector
 * \param vector sectores
 * \param  tamaño del vector sectores
 * \return 0 todoOk
 *
 */
int modifyEmployees(Employee vec[], int tam,eSector sectores [], int tamSec);

/** \brief Recorre el array y pone el campo isEmpty en 1 si hay lugar en el array.
 *
 * \param puntero a array Employee
 * \param tamaño del array
 * \return -1 si hay error, 0 si esta todo OK.
 *
 */
int buscarLibre(Employee vec [], int tam);



void harcodearEmpleados(Employee vec[], int cant);


int cargarDescripcionSector(char descripcion[],int id, eSector sectores [], int tam);



/** \brief ordena los empledos por el criterio solicitado (Alfabeticamente y Sector)
 *
 * \param vector de empleados
 * \param tamaño del vector
 * \param vector sectores
 * \param tañaño de vector sectores
 * \return
 *
 */
int shortEmployees(Employee vec[], int tam, eSector[], int tamSec);



/** \brief menu de opciones Informes.
 *
 * \param
 * \param
 * \return
 *
 */

int menuInformes();



/** \brief mostrara los informes solicitados de los empleados
 *
 * \param vector empleado
 * \param tamaño vector empleado
  *\param  vector sectores
  *\param  tamaño sector
 * \return
 *
 */
void informar(Employee vec[], int tam,eSector sectores [], int tamSec);


/** \brief Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 *
 * \param vector empleados
 * \param tamaño del vector
 * \return
 *
 */

void informarTotalSueldos(Employee vec[], int tam);

