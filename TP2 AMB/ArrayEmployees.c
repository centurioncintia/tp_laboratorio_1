
#include <stdio.h>
#include <stdlib.h>
#include"ArrayEmployees.h"
#include"dataWarehouse.h"
#include <string.h>
#include "sector.h"
#include "centurion.h"
#include <ctype.h>



void mostrarEmpleado(Employee x, eSector sectores[], int tamSec)
{
    char nombreSector[51];
    cargarDescripcionSector(nombreSector, x.sector,sectores, tamSec);

    printf("%d  %10s     %10s       %6.2f   %10s\n", x.id, x.name, x.lastName,x.salary,nombreSector);
}


int printEmployees(Employee vec[], int tam, eSector sectores[], int tamSec)
{

    int flag =0;

    system("cls");
    printf("************** Lista de empleados ****************\n\n");

    printf("  Id      Nombre       Apellido         Sueldo       Sector\n\n");



    for (int i =0; i < tam; i ++)
    {

        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec [i], sectores, tamSec);
            flag = 1;
        }
    }
    if (flag ==0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
    return 0;
}






int buscarLibre(Employee vec [], int tam)
{
    int indice = -1; //ESTA LLENO NO HAY LUGAR.

    for(int i = 0; i < tam; i ++ )
    {
        if( vec[i].isEmpty == 1 ) //Entro al If, la estructura está  vacia es = 1.
        {
            indice = i;
            break;
        }

    }

    return indice;
}

int findEmloyeeById(int id, Employee vec[], int tam) //Pasar proximo Id.
{

    int index = -1;



    for ( int i =0; i < tam ; i ++)
    {

        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            index = i;

            break;
        }
    }


    return index;
}


int addEmployees(int idx, Employee vec[], int tam, eSector sectores[], int tamSec)
{

    int todoOk = 0;
    int indice = buscarLibre(vec, tam);
    Employee auxEmpleado;

    int flag1=0;




    system("cls");
    printf("************** Alta empleado ****************\n\n");

    if ( indice == -1)//if hay lugar?
    {
        printf ("Sistema completo!!!....\n\n");
    }
    else
    {
        auxEmpleado.id =idx; // Renombro valor para menu incremental idX



           do
            {

            if(getStringLetras("Nombre: ", auxEmpleado.name))
            {
              printf("Nombre cargado con exito!!\n");
               flag1=1;
            }
            else
            {
               printf("Error, debe ingresar un nombre\n");
            }




            if(flag1==1){
            if(getStringLetras("Apellido: ", auxEmpleado.lastName))
            {

                printf("Apellido cargado con exito!!\n");


            }
            else
            {
               printf("Error, debe ingresar un Apellido\n");
            }
            }



            }while(flag1==0);


    }
       printf("Ingrese sueldo: ");
       scanf("%f", &auxEmpleado.salary);





    mostrarSectores(sectores, tamSec);

    utn_getNumero(&auxEmpleado.sector, "\nIngrese ID numero del Sector: ", "Error debe ingresar un numero valido\n", 1, 5,2);

    auxEmpleado.isEmpty = 0;


    vec[indice] = auxEmpleado;  // Copio al vector el empleado nuevo
    todoOk = 1;// devuelve el id incremental

    printf("\nAlta exitosa!!!...\n\n");

    mostrarEmpleado(vec[indice], sectores, tamSec);



    return todoOk;

}

int removeEmployee(Employee vec[], int tam, eSector sectores [], int tamSec )
{
    int error =0;
    int id;
    int indice;
    char confirma;

    printEmployees( vec,  tam,  sectores,  tamSec);

    printf("\n\n");
    printf("************** Baja de empleados ****************\n\n");
    printf("Ingrese id: ");
    scanf("%d",&id);

    indice = findEmloyeeById(id,vec, tam);

    if ( indice == -1)
    {
        printf("No hay registro de un empleado con el id : %d\n", id);
    }
    else
    {

        mostrarEmpleado(vec[indice], sectores, tamSec);

        printf("confirma Baja s/n: ");
        fflush(stdin);
        scanf("%c", &confirma);

        verifica();

        if ( confirma == 's')
        {

            vec [indice].isEmpty =1;
            printf("Se ha realizado la baja con exito\n\n");

        }
        else
        {

            printf("Se ha cancelado la operacion\n\n");

        }
    }
    return error = -1;
}

int modifyEmployees(Employee vec[], int tam,eSector sectores [], int tamSec)
{
    int todoOK =0;
    int id;
    int opcion;
    float nuevoSueldo;
    int nuevoSector;
    char letra;


    system("cls");
    printf("************** Modificar campo de empleado ****************\n\n");

    printEmployees( vec,  tam,  sectores,  tamSec);

    printf("\nIngrese id para modificar empleado: ");
    scanf("%d",&id);
    printf("\n");
    int index = findEmloyeeById(id,vec, tam);

    if ( index == -1)
    {

        printf("No hay registro de un empleado con el id : %d\n", id);
    }
    else
    {
        printf("\n\nEl empleado a modificar es :\n\n");
        mostrarEmpleado(vec[index], sectores, tamSec);

        do
        {

            printf("\n\n************* MODIFICAR CAMPO *********\n\n");
            printf("1.Nombre\n");
            printf("2.Apellido\n");
            printf("3.Sueldo\n");
            printf("4.Sector\n");



            utn_getNumero(&opcion, "\nIngrese un numero del submenu: ", "Error debe ingresar un numero valido\n", 1, 5,2);

            switch(opcion)
            {


            case 1:


                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(vec[index].name);
                printf("Se ha actualizado el nombre con exito\n\n");

                break;


            case 2:

                printf("Ingrese nuevo Apellido : ");
                fflush(stdin);
                gets(vec[index].lastName);
                printf("Se ha actualizado el Apellido con exito\n\n");

                break;


            case 3:

                printf("Ingrese nuevo Sueldo: ");
                scanf("%f",&nuevoSueldo);

                vec [index].salary = nuevoSueldo;
                printf("Se ha actualizado el Sueldo con exito\n\n");

                break;



            case 4:

                printf("\nIngrese nuevo Sector: \n* 1- Administracion \n* 2- RRHH \n* 3- Marketing \n* 4- Publicidad \n* 5- Tesoreria\n\n");
                scanf("%d",&nuevoSector);
                vec [index].sector = nuevoSector;

                printf("Se ha actualizado Sector con exito\n\n");


                break;

            }


            printf("Sigue modificando s/n?: ");

            fflush(stdin);
            scanf("%c",&letra);

        }
        while(letra =='s');


        mostrarEmpleado(vec[index], sectores, tamSec);

    }
    return todoOK;
}

void harcodearEmpleados(Employee vec[], int cant)
{

    for(int i =0; i < cant; i ++)
    {

        vec[i].id =ids[i];
        strcpy(vec[i].name,nombres[i]);
        strcpy(vec[i].lastName,apellidos[i]);
        vec[i].salary = sueldos[i];
        vec[i].sector = idsSector[i];
        vec[i].isEmpty = 0;
    }

}

int cargarDescripcionSector(char descripcion[],int id, eSector sectores [], int tam)
{

    int todoOk = 0;

    for(int i =0; i < tam; i++)
    {

        if(sectores[i].id == id)
        {
            strcpy(descripcion,sectores [i].descripcion);
            todoOk = 1;
        }

    }

    return todoOk;
}

int initEmployees(Employee* list, int len)
{
    int error = -1;

    for (int i = 0; i < len; i++)
    {
        list[i].isEmpty = 1;
    }

    return error = 0;
}





int menuInformes()
{

    int opcion;

    system("cls");
    printf("\n\n************** Informe Empleados ********\n\n");
    printf("1. Listado de empleados ORDEN: Alfabetico y Sector.\n\n");
    printf("2. Informar SALARIOS: Total - Promedios - Empleados mas renumerados.\n\n");
    printf("3. Salir.\n\n");

   utn_getNumero(&opcion, "Ingrese un numero: ", "ERROR!! Opcion invalida debe ingresar un numero del 1 al 3\n", 1, 3,2);

    return opcion;
}



int shortEmployees(Employee vec[], int tam,eSector sectores[], int tamSec)

{
    Employee auxEmpleado;


    for (int i =0; i < tam -1; i++)
    {


        for(int j= i+1; j < tam; j++)
        {


            if(vec[i].sector > vec[j].sector) //Swapeo por sector
            {

                auxEmpleado = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;
            }

            else if(vec[i].sector == vec[j].sector && strcmp(vec[i].name,vec [j].lastName )>0) //swap por Apellido orden alfabetico
            {
                auxEmpleado = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;

            }

        }

    }

    printEmployees(vec,tam,sectores,tamSec);
    return 0;
}


void informar(Employee vec[], int tam,eSector sectores[], int tamSec)
{
    int menuInformes();


    char seguir ='s';
    char confirma;

    system("cls");
    printf("\n********************** Informes Empleados *********************************\n\n");

    do
    {

        switch(menuInformes())
        {
        case 1:
            shortEmployees(vec,tam, sectores, tamSec);
            break;
        case 2:
            informarTotalSueldos(vec,tam);

            break;
        case 3:

            printf("Confirmar Salida s/n: ");
            fflush(stdin);
            confirma = tolower(getchar());
            if (confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
        system("pause");

    }
    while ( seguir =='s');

}


void informarTotalSueldos(Employee vec[], int tam)
{

    float total = 0;
    float cant =0;
    float promedio;
    int sueldosMax =0;

    for (int i =0; i < tam; i ++)
    {

        if(vec[i].isEmpty ==0)
        {
            total += vec[i].salary;
            cant ++;

        }
        promedio = total / cant;

    }

    for (int i =0; i < tam; i ++)
    {

        if(vec[i].isEmpty ==0 && vec[i].salary > promedio)
        {

            sueldosMax ++;

        }

    }

    system("cls");
    printf("\n**********************Informes Salarios*********************************\n\n");
    printf("------Cantidad de sueldos que superan el promedio: %d\n\n", sueldosMax);
    printf("------Total Sueldos a pagar $ %.2f\n\n",total);
    printf("------Promedio de Sueldos $ %.2f\n\n", promedio);

}

