/*
Ingresar números hasta que el usuario lo decida.
Los números tienen que estar comprendidos entre -100 y 100.
Determinar:
a. Cantidad de números positivos.
b. Cantidad de números negativos.
c. Promedio de números.
d. De los positivos el máximo.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero, max, suma=0, contador=0, contadorpos=0, contadorneg=0;
	float promedio;
	char respuesta;

	do{
	do{
	printf("Ingrese un numero entre -100 y 100: ");
	scanf("%d",&numero);
	} while(numero<-100 || numero>100);

	if(numero>=0)
	{
		contadorpos++;
		if(contadorpos==1 || max<numero)
		{
			max=numero;
		}
	}
	else
	{
		contadorneg++;
	}

	suma+=numero;
	contador++;


	do{
	printf("Desea ingresar otro numero? s/n: ");
	fflush(stdin);
	scanf("%c",&respuesta);
	} while(respuesta!='s' && respuesta!='n');

	} while(respuesta=='s');

	promedio = (float)suma/contador;

	printf("\na) La cantidad de numeros positivos o ceros es: %d", contadorpos);
	printf("\nb) La cantidad de numeros negativos es: %d", contadorneg);
	printf("\nc) El promedio de los numeros es: %.2f", promedio);

	if(contadorpos==0)
	{
		printf("\nd) No ingresaste numeros positivos");
	}else{
	printf("\nd) El maximo de los positivos es: %d", max);
	}

	return 0;
}
