/*

 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define SIZE 6
#define LIBRE 0
#define OCUPADO 1


int main()
{
	setbuf(stdout,NULL);
	int legajo[SIZE] = {100,101,102};
	int nota_uno[SIZE] = {2,3,7};
	int nota_dos[SIZE] = {4,6,8};
	char nombre[SIZE][30] = {"Camila","Lucas","Matias"};
	float promedio[SIZE];
	int estado[SIZE];
	int i;

	InicializarAlumnos(estado,SIZE,LIBRE);

	estado[0]=OCUPADO;
	estado[1]=OCUPADO;
	estado[2]=OCUPADO;

	for(i=0; i<2; i++)
		{
		CargarAlumno(legajo[], estado[], SIZE, LIBRE);
		}

	for (i=0; i<SIZE; i++)
	{
	printf("%10d  - %10s  -  %10d\n",legajo[i],nombre[i],estado[i]);
	}


	/*
	printf("\nLa suma es: %d", suma);
	printf("\nLa resta es: %d", resta);
	printf("\nEl producto es: %d", producto);
	printf("\nEl promedio es: %.2f", promedio);
	*/

	return 0;

}



