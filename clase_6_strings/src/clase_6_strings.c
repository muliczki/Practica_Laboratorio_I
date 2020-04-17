/*
 ============================================================================
 Name        : clase_6_ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char palabra[20];
	char laCopia[20]="baai amigo";
	int largo;
	int compare;

	//char * fgets (char *s, int count, FILE *stream)
	fgets(palabra,20,stdin);  //>> para pedir string

	// gets(palabra);  >> para pedir string    no se cual es la dif entre los dos saludos.
//	gets(palabra); // OPA ACA NO LE TENGO QUE BORRAR EL ULTIMO CHAR OJO OJO OJO


// int strlen(const char*) >> para saber el largo de la palabra
// ojo porque me suma el ultimo que es el \n > CON EL FGETS, EL GETS NO!!!!!
	largo = strlen(palabra);
	palabra[largo-1]='\0';   //HACER ESTO PARA CORREGIRLO. el \0 es el caracter de cierre del string
	largo = strlen(palabra);


//  int strcmp(const char*, const char*);
//	Me compara el string 1 con el 2do str. OJO QUE VARIA ENTRE MAY Y MIN
//	Si da -1 significa que el 2do string esta antes en la tablas ASCII
//	Si da 1 significa que el 1er string esta antes en la tablas ASCII
//  Si da 0 los string son iguales

	compare = strcmp(palabra,"holu");


// char* strcpy(char*, const char*);  COPIA LO QUE TIENE EL SEGUNDO ARGUMENTO("PALABRA") AL PRIMERO (LA COPIA)
	strcpy(laCopia,palabra);


//char * strcat (char *restrict to, const char *restrict from)
	strcat(laCopia,"EL CAT");  // COPIA LO QUE TIENE EL 2 ARGUMENTO AL 1ER PERO EMPIEZA A ESCRIBIR EL EL \N DEL 2DO.
							//NO BORRA LO QUE TENIA, OJO CON EL TAMANO


// char *strupr (char *);  PONE TODO EL STING EN MAYUSCULA
	strupr(palabra);


//  char *strlwr (char *); PONE TODO EL STING EN MAYUSCULA
	strlwr(laCopia);


	puts(palabra);  // puts = PUT String > SOLO PARA STRING (LLOREMOS)
	puts(laCopia);
	printf("%d\n",largo);
	printf("%d",compare);
	return EXIT_SUCCESS;
}



