#include "parser.h"
#include <stdlib.h>


int parser_PostFromText(FILE* pFile , LinkedList* pArrayListPost)
{
	int ret=-1; //error
	ePost* aux;
	char idpost[500], iduser[500], likes[500], mensaje[2000];
	int datos;

	if(pFile!=NULL && pArrayListPost!=NULL)
	{

		datos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idpost, iduser, likes, mensaje); // leo la primera linea para no guardar los titulos

		 while(!feof(pFile)) //ejecuto mientras no sea el final del archivo
		 {

			 datos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idpost, iduser, likes, mensaje); // leo cada linea de datos, asigno variables TEXTO


			if(datos==4) // para chequear que haya leido X cantidad de datos
				 {
					 aux = post_newParametros(idpost, iduser,likes, mensaje); //guardo nuevo empleado en puntero auxiliar

					 if(aux!=NULL)
					 {
						 ret= ll_add(pArrayListPost, aux); //si encuentro espacio, lo agrego a la LL. si lo agrego DEVUELVE 0>>> ok
					 }

				 }

		}
	}


    return ret;
}

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
*/
