/*
Ingreso 5 productos, hay dos tipos "a" y tipo "b" ,
necesito saber el precio más caro y el promedio de precios *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	char tipo;
	float precio;
	float max;
	float suma;
	float promedio;
	int i;

	for (i=0; i<5; i++)
	{
	do{
	printf("Ingrese un tipo de producto: ");
	fflush(stdin);
	scanf("%c",&tipo);} while(tipo!='a' && tipo!='b');

	printf("Ingrese el precio: ");
	scanf("%f",&precio);

	if(i==0 || max<precio )
	{
		max = precio;
	}

	suma +=precio;
	}

	promedio = suma/i;

	printf("\nEl precio más caro es: %.2f", max);
	printf("\nEl promedio es: %.2f", promedio);

	return 0;
}
