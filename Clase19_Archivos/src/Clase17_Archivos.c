/*
 ============================================================================
1era etapa:
Poder guardar los datos a medida que los usuarios se quieran registrar ( usuario y clave)

2da etapa:
Poder mostrar todos los usuarios registrados en tu sistema

3era etapa:
Poder logearse al sistema si su usuario y clave son correctos
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char usuario[51];
    char clave[51];
    int estado;
} eUsuario;


int main(void) {

	setbuf(stdout,NULL);

	 FILE* pArchivo;
	 eUsuario* pAuxEscribir[10];
	 eUsuario* pAuxLeer[10];
	 eUsuario uno;
	 int indice=0, i, contador=0, rta, flag;
	 char nombreAux[500], claveAux[500], estadoAux[500];


	 do{

	 printf("\n1. ALTA USUARIO\n");
	 printf("2. MOSTRAR USUARIOS\n");
	 printf("3. LOGEAR\n");
	 printf("5. SALIR\n");

	 printf("\nIngrese su opcion: ");
	 fflush(stdin);
	 scanf("%d", &rta);



	 switch(rta)
	 {
	 	 case 1:
	 		 pAuxEscribir[indice]=(eUsuario*) malloc(sizeof(eUsuario));

	 		 if(pAuxEscribir[indice]!=NULL)
	 		 {
	 			printf("\nCREAR NUEVO USUARIO");
	 			printf("\nIngrese un usuario: ");
	 			fflush(stdin);
	 			scanf("%s", (*(pAuxEscribir+indice))->usuario);

	 			printf("Ingrese la clave: ");
	 			fflush(stdin);
	 			scanf("%s", (*(pAuxEscribir+indice))->clave);

	 			(*(pAuxEscribir+indice))->estado=1;
	 		 }


			 indice++;

			 pArchivo = fopen("prueba.csv","w");

			 if(pArchivo!=NULL)
			 {
				 fprintf(pArchivo,"Usuario,Clave,Estado\n");

				 for(i=0; i<indice; i++)
				        {
				            fprintf(pArchivo,"%s,%s,%d\n", (*(pAuxEscribir+i))->usuario, (*(pAuxEscribir+i))->clave, (*(pAuxEscribir+i))->estado);
				        }

			 fclose(pArchivo);
			 printf("\nUsuario guardado!\n\n");
			 }

		 break;

	 	 case 2:
			 pArchivo = fopen("prueba.csv","r");
			 if(pArchivo!=NULL)
			 {
			 fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", nombreAux, claveAux,estadoAux);

				 while(!feof(pArchivo))
				     {
				         if(feof(pArchivo))
				             break;

				         fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", nombreAux, claveAux, estadoAux);

				         if(strcmp(estadoAux,"1")==0)
				         {
				        	 strcpy(uno.usuario,nombreAux);
				        	 strcpy(uno.clave,claveAux);
				        	 uno.estado= atoi(estadoAux);
				         }

				         pAuxLeer[contador]=(eUsuario*) malloc(sizeof(eUsuario));

				         if(pAuxLeer[contador]!=NULL)
				         {
				        	 *(pAuxLeer[contador])=uno;
				         }
				         contador++;
				     }


			 fclose(pArchivo);
			 printf("\nEstoy leyendo!\n\n");
			 }

	 		printf("\nUSUARIO REGISTRADOS\n");

			 for(i=0; i<contador; i++)
			 {
				 if((*(pAuxLeer+i))->estado==1)
				 {
				 printf("- %s\n", (*(pAuxLeer+i))->usuario);
				 }
			 }
			 printf("\n");
			 break;



	 	 case 3:
	 		flag=0;
	 		printf("Ingrese su usuario: ");
	 		fflush(stdin);
	 		scanf("%s", nombreAux);

	 		printf("Ingrese su clave: ");
	 		fflush(stdin);
	 		scanf("%s", claveAux);

	 		for(i=0; i<contador; i++)
	 		{
	 			if((*(pAuxLeer+i))->estado==1 && strcmp((*(pAuxLeer+i))->usuario, nombreAux)==0 && strcmp((*(pAuxLeer+i))->clave, claveAux)==0)
	 			{
	 				printf("\nBienvenidx: %s !!\n\n", nombreAux);
	 				flag=1;

	 			}
	 		}

	 		if(flag==0)
	 		{
	 			printf("\nUsuario y/o clave incorrecto\n\n");

	 		}

	 		break;


	 }
	 } while (rta!=5);

	return EXIT_SUCCESS;
}


/* CON ARCHIVO CSV PERO SIN MEMORIA DINAMICA
setbuf(stdout,NULL);

 FILE* miArchivo;
 eUsuario miUsuario[10];
 eUsuario aux[10];
 eUsuario uno;
 int indice=0;
 int i;
 int contador=0;
 int rta;
 char nombreAux[51];
 char claveAux[51];
 char nombre[500], clave[500], estado[500];
 int flag;


 do{

 printf("\n1. ALTA USUARIO\n");
 printf("2. MOSTRAR USUARIOS\n");
 printf("3. LOGEAR\n");
 printf("5. SALIR\n");

 printf("\nIngrese su opcion: ");
 fflush(stdin);
 scanf("%d", &rta);



 switch(rta)
 {
 	 case 1:
		 printf("Ingrese un usuario: ");
		 fflush(stdin);
		 scanf("%s", miUsuario[indice].usuario);

		 printf("Ingrese la clave: ");
		 fflush(stdin);
		 scanf("%s", miUsuario[indice].clave);
		 miUsuario[indice].estado=1;
		 indice++;

		 miArchivo = fopen("prueba.csv","w");

		 if(miArchivo!=NULL)
		 {
			 fprintf(miArchivo,"Usuario,Clave,Estado\n");

			 for(i=0; i<indice; i++)
			        {
			            fprintf(miArchivo,"%s,%s,%d\n", miUsuario[i].usuario, miUsuario[i].clave, miUsuario[i].estado);
			        }

		 fclose(miArchivo);
		 printf("Usuario guardado!\n\n");
		 }

	 break;


 	 case 2:
		 miArchivo = fopen("prueba.csv","r");
		 if(miArchivo!=NULL)
		 {
		 fscanf(miArchivo, "%[^,],%[^,],%[^\n]\n", nombre, clave,estado);

			 while(!feof(miArchivo))
			     {
			         if(feof(miArchivo))
			             break;

			         fscanf(miArchivo, "%[^,],%[^,],%[^\n]\n", nombre, clave, estado);

			         if(strcmp(estado,"1")==0)
			         {
			        	 strcpy(uno.usuario,nombre);
			        	 strcpy(uno.clave,clave);
			        	 uno.estado= atoi(estado);
			         }

			         aux[contador]=uno;
			         contador++;
			     }


		 fclose(miArchivo);
		 printf("Estoy leyendo!\n\n");
		 }

		 for(i=0; i<contador; i++)
		 {
			 if(aux[i].estado==1)
			 {
			 printf("%s\n", aux[i].usuario);
			 }
		 }
		 printf("\n");
		 break;


 	 case 3:
 		 flag=0;
 		printf("Ingrese su usuario: ");
 		fflush(stdin);
 		scanf("%s", nombreAux);

 		printf("Ingrese su clave: ");
 		fflush(stdin);
 		scanf("%s", claveAux);

 		for(i=0; i<10; i++)
 		{
 			if(aux[i].estado==1 && strcmp(aux[i].usuario, nombreAux)==0 && strcmp(aux[i].clave, claveAux)==0)
 			{
 				printf("\nSe encontro el usuario!!\n\n");
 				flag=1;

 			}
 		}

 		if(flag==0)
 		{
 			printf("\nUsuario incorrecto\n\n");

 		}

 		break;

 }

 } while (rta!=5);

return EXIT_SUCCESS;
*/



/* CON ARCHIVO BINARIO
setbuf(stdout,NULL);

 FILE* miArchivo;
 eUsuario miUsuario[10];
 eUsuario aux[10];
 int indice=0;
 int i;
 int rta;
 char nombreAux[51];
 char claveAux[51];



 do{

 printf("\n1. ALTA USUARIO\n");
 printf("2. MOSTRAR USUARIOS\n");
 printf("3. LOGEAR\n");
 printf("5. SALIR\n");

 printf("\nIngrese su opcion: ");
 fflush(stdin);
 scanf("%d", &rta);



 switch(rta)
 {
 	 case 1:
		 printf("Ingrese un usuario: ");
		 fflush(stdin);
		 scanf("%s", miUsuario[indice].usuario);

		 printf("Ingrese la clave: ");
		 fflush(stdin);
		 scanf("%s", miUsuario[indice].clave);
		 miUsuario[indice].estado=1;
		 indice++;

		 miArchivo = fopen("prueba.usu","wb");

		 if(miArchivo!=NULL)
		 {
		 fwrite(miUsuario,sizeof(eUsuario),indice,miArchivo);
		 fclose(miArchivo);
		 printf("Usuario guardado!\n\n");
		 }

	 break;


 	 case 2:
		 miArchivo = fopen("prueba.usu","rb");
		 if(miArchivo!=NULL)
		 {
		 fread(&aux, sizeof(eUsuario), indice, miArchivo);
		 fclose(miArchivo);
		 printf("Estoy leyendo!\n\n");
		 }

		 for(i=0; i<indice+1; i++)
		 {
			 if(aux[i].estado==1)
			 {
			 printf("%s\n", aux[i].usuario);
			 }
		 }
		 printf("\n");
		 break;


 	 case 3:
 		printf("Ingrese su usuario: ");
 		fflush(stdin);
 		scanf("%s", nombreAux);

 		printf("Ingrese su clave: ");
 		fflush(stdin);
 		scanf("%s", claveAux);

 		for(i=0; i<10; i++)
 		{
 			if(aux[i].estado==1 && strcmp(aux[i].usuario, nombreAux)==0 && strcmp(aux[i].clave, claveAux)==0)
 			{
 				printf("Se encontro el usuario!!\n\n");

 			}
 		}
 		break;

 }

 } while (rta!=5);

return EXIT_SUCCESS;
*/
