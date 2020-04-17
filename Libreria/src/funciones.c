#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* getChar le pide al usuario un char, valida entre 2 opciones
 *
 * char: mensaje para pedir char
 * char: error si la persona escribe algo incorrecto
 * char: opc1. primera opcion
 * char: opc2. segunda opcion
 *
 * return: el char validado
 */
char getChar (char mensaje[], char error[], char opc_1, char opc_2)
{
	char caracter;
	int flagError =0;

	do{
		if(flagError==0)
		{
		printf("%s", mensaje);
		flagError=1;
		}
		else
		{
		printf("%s", error);
		}
		fflush(stdin);				// en windows
		// __fpurge(stdin); 		// en linux
		scanf("%c", &caracter);

	}while(caracter!= opc_1 && caracter!= opc_2);

	return caracter;
}



/* getInt le pide al usuario un entero, valida entre un min y un max
 *
 * char: mensaje para pedir entero
 * char: error si la persona escribe algo incorrecto
 * int min: el entero debe ser mayor al min
 * int max: el entero debe ser menor al max
 *
 * return: el entero validado
 */
int getInt (char mensaje[], char error[], int min, int max)
{
	int entero;
	int flagError =0;

		do{
			if(flagError==0)
			{
			printf("%s", mensaje);
			flagError=1;
			}
			else
			{
			printf("%s", error);
			}
			scanf("%d", &entero);

		}while(entero< min || entero> max);

		return entero;
}



/* getInt le pide al usuario un flotante, valida entre un min y un max
 *
 * char: mensaje para pedir flotante
 * char: error si la persona escribe algo incorrecto
 * float min: el flotante debe ser mayor al min
 * float max: el flotante debe ser menor al max
 *
 * return: el flotante validado
 */
float getFloat (char mensaje[], char error[], float min, float max)
{
	float flotante;
	int flagError =0;

		do{
			if(flagError==0)
			{
			printf("%s", mensaje);
			flagError=1;
			}
			else
			{
			printf("%s", error);
			}
			scanf("%f", &flotante);

		}while(flotante< min || flotante> max);

		return flotante;
}


/*
char[] getString (char mensaje[], char arrayParametro[], int cantidad)
		{
		char cadena[cantidad];

		printf("%s",mensaje);
		cadena = fgets(arrayParametro, cantidad, stdin);

		return cadena[];
		}

*/



