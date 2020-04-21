/*
 ============================================================================
 Name        : hola.c
  * 1-La suma acumulada 19     OK
 * 2-La cantidad de notas cargadas 3 OK
 * 3-La cantidad de aprobados 2   ok
 * 4-La cantidad de desaprobados 1 ok
 * 5-La nota maxima 10  ok
 * 6-La nota minima 2   ok
 * 7-La cantidad de notas pares 2
 * 8-El promedio de las notas 6 ok
 * 9-Inicializar el array     OK
 * a-mostrar todos los elementos
 * b-mostrar los elementos vacios con su indice(para el cliente)
 * c-mostrar solo los elementos cargados
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define SIZE 6
#define INDICE -1


int main(void) {
	setbuf(stdout,NULL);

	int numeros[SIZE];
	int suma;
	int cantidadCargada;
	int cantidadNoCargada;
	int maximo;
	int minimo;
	int pares;
	float promedio;
	int cantidadAprobados; // igual o mas a 6
	int cantidadDesaprobados; // menor a 6

	InicializarArray(numeros,SIZE,INDICE);

	numeros[2]=-1;
	numeros[5]=2;
	numeros[3]=5;
	numeros[0]=7;

	suma = SumarArray(numeros,SIZE,INDICE);
	cantidadCargada = ContarCargados(numeros,SIZE,INDICE);
	cantidadNoCargada = ContarNoCargados(numeros,SIZE,INDICE);
	cantidadAprobados = ContarSuperioresParametro(numeros,SIZE, INDICE, 6);
	cantidadDesaprobados = ContarInferioresParametro(numeros,SIZE, INDICE, 6);
	maximo = MostrarMaximo(numeros,SIZE, INDICE);
	minimo = MostrarMinimo(numeros,SIZE, INDICE);
	pares = MostrarPares(numeros,SIZE, INDICE);
	promedio = PromedioArray(numeros,SIZE, INDICE);

	printf("%d",numeros[0]);
	printf("\nsuma: %d",suma);
	printf("\ncargados: %d",cantidadCargada);
	printf("\nNO cargados: %d",cantidadNoCargada);
	printf("\nAprobados: %d",cantidadAprobados);
	printf("\nDesaprobados: %d",cantidadDesaprobados);
	printf("\nMaximo: %d",maximo);
	printf("\nMinimo: %d",minimo);
	printf("\nPares: %d",pares);
	printf("\nPromedio: %.2f",promedio);

	MostrarArrayTodos(numeros, SIZE);
	MostrarVaciosParaUsuario(numeros, SIZE, INDICE);
	MostrarCargadosParaUsuario(numeros, SIZE, INDICE);

/*
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


*/

	return EXIT_SUCCESS;
}
