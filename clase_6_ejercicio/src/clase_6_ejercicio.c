/*
 ============================================================================
 Name        : clase_6_ejercicio.c
 Author      : Uliczki Micaela

Mostrar por pantalla el apellido y nombre de una persona, respetando el siguiente formato:
"Scarafilo, Germán Ezequiel". Tener en cuenta: apellido y nombre se ingresan en dos
variables distintas que no pueden ser modificadas.
El ingreso de datos no tiene ningún formato en particular, es decir no se tiene
en cuenta mayusculas o minusculas, por lo que su programa deberá
hacerlo para respetar el formato solicitado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 30

int main(void) {
	setbuf(stdout, NULL);

	char apellido[SIZE];
	char nombre[SIZE];
	char apellidoCopia[SIZE];
	char nombreCopia[SIZE];
	char apellidoYnombre[60];
	int i;
	int largoApellido;
	int largoNombre;

// Pido apellido y nombre
	printf("Ingresa tu apellido: ");
	fgets(apellido,SIZE,stdin);
	printf("Ingresa tu nombre: ");
	fgets(nombre,SIZE,stdin);

// Hago dos copias para no tocar las variables originales
	strcpy(apellidoCopia, apellido);
	strcpy(nombreCopia, nombre);

// Paso las copias a minuscula
	strlwr(apellidoCopia);
	strlwr(nombreCopia);

// Pongo las iniciales en mayusculas
	apellidoCopia[0]=toupper(apellidoCopia[0]);
	nombreCopia[0]=toupper(nombreCopia[0]);

// Verifico si existe algun doble apellido o segundo nombre para inicializar en mayusculas
	for (i=0; i<SIZE; i++)
		{
		if(apellidoCopia[i]==' ')
		{
			apellidoCopia[i+1]=toupper(apellidoCopia[i+1]);
		}
		if(nombreCopia[i]==' ')
		{
			nombreCopia[i+1]=toupper(nombreCopia[i+1]);
		}
	}

// Debo eliminar los saltos de linea para poder concatenar
	largoApellido = strlen(apellidoCopia);
	apellidoCopia[largoApellido-1]='\0',
	largoApellido = strlen(apellidoCopia);

	largoNombre = strlen(nombreCopia);
	nombreCopia[largoNombre-1]='\0',
	largoNombre = strlen(nombreCopia);


// Concateno con los signos
	strcat(apellidoCopia, ", ");
	strcat(nombreCopia, ".");

// copio la variable apellido en apellido&nombre y luego la concateno con el nombre
	strcpy(apellidoYnombre, apellidoCopia);
	strcat(apellidoYnombre, nombreCopia);

// muestro en pantalla la variable apellido&nombre
	printf("\nBienvenidx!! %s",apellidoYnombre);

	return EXIT_SUCCESS;
}



