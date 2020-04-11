/*
Ingreso 5 productos, hay dos tipos "a" y tipo "b" ,
necesito saber si el promedio de precios de los de tipo "a" es mayor o menor o
igual al de promedio de precios de tipo "b"
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	char tipo;
	float precio;
	float sumaa;
	float sumab;
	float promedioa;
	float promediob;
	int contadora=0;
	int contadorb=0;
	int i;

	for (i=0; i<5; i++)
	{
	do{
	printf("Ingrese un tipo de producto: ");
	fflush(stdin);
	scanf("%c",&tipo);} while(tipo!='a' && tipo!='b');

	printf("Ingrese el precio: ");
	scanf("%f",&precio);

	if(tipo=='a')
	{
		contadora++;
		sumaa +=precio;
	}
	else
	{
		contadorb++;
		sumab+= precio;
	}
	}

	if(contadora==0 || contadorb==0)
	{
		printf("\nElegiste solo una clase de productos");
	}
	else
	{
	promedioa = sumaa/contadora;
	promediob = sumab/contadorb;
	if (promedioa>promediob)
	{
	printf("\nEl promedio de los productos A es: %.2f", promedioa);
	printf("\nEl promedio de los productos B es: %.2f", promediob);
	printf("\nEl promedio de los productos A es mayor al de B");
	}
	else if (promedioa<promediob)
	{
	printf("\nEl promedio de los productos A es: %.2f", promedioa);
	printf("\nEl promedio de los productos B es: %.2f", promediob);
	printf("\nEl promedio de los productos A es menor al de B");
	}
	else
	{
	printf("\nEl promedio de los productos A es: %.2f", promedioa);
	printf("\nEl promedio de los productos B es: %.2f", promediob);
	printf("\nEl promedio de los productos A es igual al de B");
	}
	}
	return 0;
}
