/*
Ingreso 5 productos, hay dos tipos "a" y tipo "b" ,
necesito saber el promedio de precios de los productos tipo "a" *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	char tipo;
	float precio;
	float sumaa;
	float promedioa;
	int contadora=0;
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

	}

	if(contadora==0)
	{
		printf("\nNo elegiste productos A");
	}
	else
	{
	promedioa = sumaa/contadora;
	printf("\nEl promedio de los productos A es: %.2f", promedioa);
	}
	return 0;
}
