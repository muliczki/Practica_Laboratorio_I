#include "datos.h"


int mostrarMenu(void)
{
    int respuesta;

	printf("VUELOS");
	printf("\n********");
	printf("\nMENU:");
	printf("\n1.  Cargar archivo.");
	printf("\n2.  Imprimir vuelos.");
	printf("\n3.  Cantidad pasajeros.");
	printf("\n4.  Cantidad pasajeros a Irlanda.");
	printf("\n5.  Filtrar vuelos cortos.");
	printf("\n6.  Listar vuelos Portugal.");
	printf("\n7.  Filtrar a Alex Lefeson.");
	printf("\n8.  Filtrar la lista de pilotos por nombre.");
	printf("\n9.  Salir.\n");
	getInt(&respuesta, "Ingrese su opcion: ", 1, 9, "Ingrese una opcion valida: ");

	return respuesta;
}

// - 1 ES ERROR
void analizarSituacion (int situacion, char texto[])
{

	if(situacion==-1)
	{
		printf("\nERROR!! REINTENTAR.\n\n");    //error
	}
	else if(situacion==2)
	{
		printf("\nOPCION ANULADA.\n\n");    //anulado
	}
	else
	{
		printf("\n%s.\n\n", texto);     //CORRECTO
	}

}


char getChar (char* texto, char opcion1, char opcion2, char* error)
{
	char caracter=' ';
	int flag=0;


	if(texto!=NULL && error!=NULL)
	{
		do
		{
			if(flag==0)
			{
				printf("%s", texto);
				flag=1;
			}else
			{
				printf("%s", error);
			}

			fflush(stdin);
			scanf("%c",&caracter);


		}while(caracter!=opcion1 && caracter!=opcion2);
	}

	return caracter;
}


void getString (char* string ,char* texto, char* error)
{
	int largoString;
	int i;
	int ret=0;
	int flag=0;

	if(texto!=NULL && error!=NULL && string!=NULL)
	{
		do
		{
			if(flag==0)
			{
				printf("%s", texto);
				flag=1;
			}else
			{
				printf("%s", error);
			}

			fflush(stdin);
			gets(string);

			 //POR SI LO TENGO QUE EJECUTAR EN GDB
			/*
			fgets(string,51,stdin);

			largoString= strlen(string);
			string[largoString-1]='\0';
			largoString= strlen(string);
			*/


			largoString= strlen(string);       // busco el largo del string

			for(i=0; i<largoString && string[i]!= '\0'; i++ )
			{
				if((string[i]>64 && string[i]<91) || (string[i]>96 && string[i]<123) || string[i]==' ')
				{
					ret = 0;
					continue;
				}else
				{
					ret = -1;
					break;
				}
			}
		}
		while(ret==-1);

		formatearString(string); //mayus y minus para poder ordenar despues
	}

}

void formatearString(char* string)
{
	int i;
	int largoString;

	if(string!=NULL)
	{
		largoString= strlen(string);
		strlwr(string);

		string[0]= toupper(string[0]);

		for(i=0; i<largoString; i++)
		{
			if(string[i]==' ')
			{
				string[i+1]= toupper(string[i+1]);
			}
		}

	}
}

void getInt (int* entero ,char* texto, int minimo, int maximo, char* error)
{
	int flag=0;

	if(texto!=NULL && error!=NULL && entero!=NULL)
	{
		do
		{
			if(flag==0)
			{
				printf("%s", texto);
				flag=1;
			}else
			{
				printf("%s", error);
			}

			scanf("%d",entero);


		}while(*entero<minimo || *entero>maximo);
	}

}

