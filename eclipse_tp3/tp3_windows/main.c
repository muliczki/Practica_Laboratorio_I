#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
    int option = 10;
    int len;
    char id[50], nombre[50], horas[50], sueldo[50];
    //int estado;
    Employee* pUnEmpleado;
	Employee* e1;
	Employee* e2;
	Employee* pPrueba;


    LinkedList* listaEmpleados = ll_newLinkedList(); //creo la lista

    len = ll_len(listaEmpleados); //busco el largo de la lista

    printf("%d\n",len);

  //  pUnEmpleado = employee_newParametros(id, nombre, horas, sueldo); //creo lugar para un empleado

    e1= employee_new(); //MAL NO LO TENGO QUE USAR ACA
    e1->id = 5;
    e1->horasTrabajadas = 10;
    strcpy(e1->nombre,"Juan");
    e1->sueldo = 10000;

    e2= employee_new(); //MAL NO LO TENGO QUE USAR ACA
    e2->id = 1;
    e2->horasTrabajadas = 15;
    strcpy(e2->nombre,"Martin");
    e2->sueldo = 15000;

    ll_add(listaEmpleados, e1); // agrego empleado en la lista
    ll_add(listaEmpleados, e2); // agrego empleado en la lista

    len = ll_len(listaEmpleados);

    printf("%d\n",len);

    pPrueba = ll_get(listaEmpleados, 1);

    printf("%s", pPrueba->nombre);


    ll_set(listaEmpleados,0,pPrueba);


    pPrueba = ll_get(listaEmpleados, 0);

    printf("%s", pPrueba->nombre);



    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}
