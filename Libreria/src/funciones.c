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
		//cadena = fgets(arrayParametro, cantidad, stdin);

		//return cadena[];
		}

*/

void InicializarArray (int arrayParametro[], int cantidad, int numeroIndice)
{
	int i;
	for (i=0; i<cantidad;i++)
	{
		arrayParametro[i] = numeroIndice;
	}
}

int SumarArray (int arrayParametro[], int cantidad, int numeroIndice)

{
	int i;
	int suma =0;
		for (i=0; i<cantidad;i++)
		{
			if(arrayParametro[i]!=numeroIndice)
			{
			suma+=arrayParametro[i];

			}
		}
	return suma;
}

int ContarCargados (int arrayParametro[], int cantidad, int numeroIndice)

{
	int i;
	int contarCargados =0;
		for (i=0; i<cantidad;i++)
		{
			if(arrayParametro[i]!=numeroIndice)
			{
				contarCargados++;
			}
		}
	return contarCargados;
}

int ContarNoCargados  (int arrayParametro[], int cantidad, int numeroIndice)

{
	int i;
	int contarNoCargados =0;
		for (i=0; i<cantidad;i++)
		{

			if(arrayParametro[i]==numeroIndice)
			{
				contarNoCargados++;
			}
		}
	return contarNoCargados;
}

int ContarSuperioresParametro  (int arrayParametro[], int cantidad, int numeroIndice, int numeroDeCorte)

{
	int i;
	int contarSuperiores =0;
		for (i=0; i<cantidad;i++)
		{
			if(arrayParametro[i]!=numeroIndice)
			{
				if(arrayParametro[i]>=numeroDeCorte)
				{
				contarSuperiores++;
				}
			}
		}
	return contarSuperiores;
}

int ContarInferioresParametro  (int arrayParametro[], int cantidad,int numeroIndice, int numeroDeCorte)

{
	int i;
	int contarInferiores =0;
		for (i=0; i<cantidad;i++)
		{
			if(arrayParametro[i]!=numeroIndice)
			{
				if(arrayParametro[i]<numeroDeCorte)
				{
					contarInferiores++;
				}
			}
		}
	return contarInferiores;
}


int MostrarMaximo  (int arrayParametro[], int cantidad,int numeroIndice)

{
	int i;
	int maximo =0;
	int flag=0;
		for (i=0; i<cantidad;i++)
		{
			if(arrayParametro[i]!=numeroIndice)
			{
				if(flag==0 || arrayParametro[i]>maximo)
				{
					maximo = arrayParametro[i];
					flag=1;
				}
			}
		}
	return maximo;
}


int MostrarMinimo  (int arrayParametro[], int cantidad,int numeroIndice)

{
	int i;
	int minimo =0;
	int flag=0;
		for (i=0; i<cantidad;i++)
		{
			if(arrayParametro[i]!=numeroIndice)
			{
				if(flag==0 || arrayParametro[i]<minimo)
				{
					minimo = arrayParametro[i];
					flag=1;
				}
			}
		}
	return minimo;
}

float PromedioArray (int arrayParametro[], int cantidad, int numeroIndice)
{

 return (float)SumarArray(arrayParametro, cantidad, numeroIndice)/ ContarCargados(arrayParametro, cantidad, numeroIndice) ;


}


int MostrarPares  (int arrayParametro[], int cantidad,int numeroIndice)

{
	int i;
	int contarPares =0;
		for (i=0; i<cantidad;i++)
		{
			if(arrayParametro[i]!=numeroIndice)
			{
				if(arrayParametro[i]%2==0)
				{
					contarPares++;
				}
			}
		}
	return contarPares;
}

void MostrarArrayTodos  (int arrayParametro[], int cantidad)

{
	int i;
		for (i=0; i<cantidad;i++)
		{
			printf("\nLa posicion %d vale: %d", i+1, arrayParametro[i]);
		}
}

void MostrarVaciosParaUsuario  (int arrayParametro[], int cantidad, int numeroIndice)

{
	int i;
		for (i=0; i<cantidad;i++)
		{
			if(arrayParametro[i]==numeroIndice)
				{
					printf("\nLa posicion %d esta vacia", i+1);
				}
		}
}

void MostrarCargadosParaUsuario  (int arrayParametro[], int cantidad, int numeroIndice)

{
	int i;
		for (i=0; i<cantidad;i++)
		{
			if(arrayParametro[i]!=numeroIndice)
				{
					printf("\nLa posicion %d esta ocupada. Vale: %d", i+1, arrayParametro[i]);
				}
		}
}

