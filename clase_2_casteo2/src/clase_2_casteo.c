/*
Pedirle al usuario que ingrese 2 números enteros y que muestre:
La suma de los dos números.
Disminuir del segundo, el primero.
El producto de ambos números.
Promedio de ambos número
 */



#include <stdio.h>
#include <stdlib.h>


int main()
{
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int suma;
	int resta;
	int producto;
	float promedio;

	printf("Ingrese un numero: ");
	scanf("%d", &numero1);

	printf("Ingrese otro numero: ");
	scanf("%d", &numero2);

	suma = numero1+numero2;
	resta = numero2-numero1;
	producto = numero1*numero2;
	promedio = (float)suma/2;

	printf("\nLa suma es: %d", suma);
	printf("\nLa resta es: %d", resta);
	printf("\nEl producto es: %d", producto);
	printf("\nEl promedio es: %.2f", promedio);

	return 0;

}
