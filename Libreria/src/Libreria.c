/*
 ============================================================================
 Name        : hola.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define STRING 30


int main(void) {
	setbuf(stdout,NULL);

	char nombre[STRING];


	char sexo;
	int edad;
	float altura;

	printf("Ingrese su nombre: ");
	fgets(nombre,STRING,stdin);

	sexo = getChar("Ingrese su sexo f/m: ", "Error, ingrese su sexo f/m: ", 'f', 'm');
	edad = getInt("Ingrese su edad: ", "Error, reingrese su edad: ", 0, 130);
	altura = getFloat("Ingrese su altura en cms: ", "Error, reingrese su altura en cms: ", 30, 250);


	printf("\nSu nombre es: %s",nombre);
	printf("Su sexo es: %c",sexo);
	printf("\nSu edad es: %d",edad);
	printf("\nSu altura es: %.2f",altura);




	return EXIT_SUCCESS;
}
