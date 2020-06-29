#include "parser.h"
#include <stdlib.h>


int parser_VueloFromText(FILE* pFile , LinkedList* this)
{
	int ret=-1; //error
	eVuelo* aux;
	char id_vuelo[500], id_avion[500], id_piloto[500], fecha[500], hora_despegue[500], hora_llegada[500], destino[500], pasajeros[500];
	int datos;

	if(pFile!=NULL && this!=NULL)
	{

		datos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_vuelo, id_avion, id_piloto, fecha, destino, pasajeros, hora_despegue, hora_llegada); // leo la primera linea para no guardar los titulos

		 while(!feof(pFile)) //ejecuto mientras no sea el final del archivo
		 {

			 datos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_vuelo, id_avion, id_piloto, fecha, destino, pasajeros, hora_despegue, hora_llegada); // leo la primera linea para no guardar los titulos


			if(datos==8) // para chequear que haya leido X cantidad de datos
				 {
					 aux = vuelo_newParametros(id_vuelo, id_avion, id_piloto, fecha, destino, pasajeros, hora_despegue, hora_llegada); //guardo nuevo empleado en puntero auxiliar

					 if(aux!=NULL)
					 {
						 ret= ll_add(this, aux); //si encuentro espacio, lo agrego a la LL. si lo agrego DEVUELVE 0>>> ok
					 }

				 }

		}
	}


    return ret;
}

int parser_PilotoFromText(FILE* pFile , LinkedList* this)
{
	int ret=-1; //error
	ePiloto* aux;
	char id_piloto[500], nombre[500], apellido[500];
	int datos;

	if(pFile!=NULL && this!=NULL)
	{

		datos = fscanf(pFile, "%[^,],%[^,],%[^\n]\n",id_piloto, nombre, apellido); // leo la primera linea para no guardar los titulos

		 while(!feof(pFile)) //ejecuto mientras no sea el final del archivo
		 {
			 datos = fscanf(pFile, "%[^,],%[^,],%[^\n]\n",id_piloto, nombre, apellido);


			if(datos==3) // para chequear que haya leido X cantidad de datos
				 {
					 aux = piloto_newParametros(id_piloto, nombre, apellido); //guardo nuevo empleado en puntero auxiliar

					 if(aux!=NULL)
					 {
						 ret= ll_add(this, aux); //si encuentro espacio, lo agrego a la LL. si lo agrego DEVUELVE 0>>> ok
					 }

				 }

		}
	}


    return ret;
}


/*
int parser_UserFromText(FILE* pFile , LinkedList* pArrayListUser)
{

	int ret=-1; //error
	eUser* aux;
	char id[500], nick[500], followers[500];
	int datos;


		if(pFile!=NULL && pArrayListUser!=NULL)
		{

			 datos = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nick, followers); // leo la primera linea para no guardar los titulos

			 while(!feof(pFile)) //ejecuto mientras no sea el final del archivo
			 {

				 datos = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nick, followers); // leo cada linea de datos, asigno variables TEXTO

				if(datos==3) // para chequear que haya leido X cantidad de datos
					 {

					aux = user_newParametros(id, nick, followers); //guardo nuevo empleado en puntero auxiliar

						 if(aux!=NULL)
						 {
							 ret= ll_add(pArrayListUser, aux); //si encuentro espacio, lo agrego a la LL. si lo agrego DEVUELVE 0>>> ok
						 }

					 }

			}
		}


	    return ret;

}


*/


/*

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int ret=-1; //error
	Employee* aux;
	int dato;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			if(feof(pFile)){
				 break;
			}

			 aux=employee_new(); //pido espacio para LEER un nuevo empleado aux
			 if(aux!=NULL)
			 {
				 dato= fread(aux, sizeof(Employee), 1, pFile); //leo una estructura del archivo y la escribo en el auxiliar

				 if(dato==1) // para chequear que haya leido UNA ESTRUCTURA de datos
				 {
				 ret = ll_add(pArrayListEmployee, aux);  //si lei un dato, lo agrego a la LL. si lo agrego DEVUELVE 0>>> ok
				 }
			 }

		}
	}

    return ret;
}


    FILE* pFile;

    	pFile = fopen("pilotos.csv","w");

    	if(pFile!=NULL)
    	{
    		fprintf(pFile,"id_piloto,nombre_piloto,apellido_piloto\n");


    				fprintf(pFile,"%d,%s,%s\n", 1,"Alex","Gonzalez");
    				fprintf(pFile,"%d,%s,%s\n", 2,"Jose","Garcia");
    				fprintf(pFile,"%d,%s,%s\n", 3,"Martin","Lopez");
    				fprintf(pFile,"%d,%s,%s\n", 4,"Lucas","Vega");
    				fprintf(pFile,"%d,%s,%s\n", 5,"Alex","Sanchez");
    				fprintf(pFile,"%d,%s,%s\n", 6,"Martin","Trotta");
    				fprintf(pFile,"%d,%s,%s\n", 7,"Tomas","Tell");
    				fprintf(pFile,"%d,%s,%s\n", 8,"Patricio","Laurel");
    				fprintf(pFile,"%d,%s,%s\n", 9,"Juan","Rota");
    				fprintf(pFile,"%d,%s,%s\n", 10,"Juan","Pect");
    			}

    	fclose(pFile);
*/

