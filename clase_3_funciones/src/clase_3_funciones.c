/*
Pedirle al usuario que ingrese legajo, altura y sexo y mostrar los datos.
(Utilizar 3 funciones distintas para tal cometido)
 */

#include <stdio.h>
#include <stdlib.h>

int getInt (char[], int, int);
float getFloat (char[], float, float);
char getChar (char[], char, char);

int main(void) {
	setbuf(stdout,NULL);
	char sexo;
	int legajo;
	float altura;

	legajo = getInt("Ingrese su legajo: ",0,1000);
	altura = getFloat("Ingrese su altura en cms: ",30,250);
	sexo = getChar("Ingrese su sexo m/f: ",'m','f');



	printf("\na) Su legajo es: %d", legajo);
	printf("\na) Su altura es: %.2f", altura);
	printf("\na) Su sexo es: %c", sexo);

	return 0;
}

char getChar (char mensaje[], char opc1, char opc2)
{
	char caracter;

	do
	{
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c", &caracter);

	} while (caracter!=opc1 && caracter!= opc2 );

	return caracter;
}

int getInt (char mensaje[], int min, int max)
{
	int valor;
	do
	{
	printf("%s",mensaje);
	scanf("%d", &valor);
	}while(valor<min || valor>max);

	return valor;
}

float getFloat (char mensaje[], float min, float max)
{
	float valor;
	do
	{
	printf("%s",mensaje);
	scanf("%f", &valor);
	}while(valor<min || valor>max);

	return valor;

}
