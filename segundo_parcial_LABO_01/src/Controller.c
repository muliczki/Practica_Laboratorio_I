
#include "Controller.h"




int controller_loadFromText(char* path , LinkedList* this, int pFunc (FILE* , LinkedList*))
{
	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	FILE* miArchivo;

	if(this!=NULL && path!=NULL && pFunc!=NULL)
	{
	miArchivo = fopen(path,"r");

		if(miArchivo!=NULL)
		{
			ret = pFunc(miArchivo,this); // si devuelve 0 ok, si -1 error
			fclose(miArchivo);
		}

	}
	return ret;
}


int controller_List(LinkedList* this, void* pElemento, int pFunc (void*))
{
	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	int i;

	if(this!=NULL)
	{
		for(i=0; i<ll_len(this) ;i++)
		{
			pElemento = ll_get(this,i);

			if(pElemento!=NULL)
			{
				ret= pFunc(pElemento);
			}


		}
	}

    return ret;
}



int controller_ListFinal(LinkedList* this1, LinkedList* this2)
{
	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	int i, j;
	int auxidUser_post, auxidUser_user, followersAux, auxidPost, likesAux;
	char nickAux[100], mensajeAux[2000];
	eUser* auxUser=NULL;
	ePost* auxPost=NULL;

	if(this1!=NULL && this2!=NULL)
	{
	printf("\n%10s - %10s - %10s - %15s - %10s - %20s\n", "ID POST", "LIKES", "ID USER", "NICK" , "FOLLOWERS","POSTEO" );

		for(i=0; i<ll_len(this2) ;i++)
		{
			auxPost = ll_get(this2,i);
			post_getId_usuario(auxPost, &auxidUser_post);
			post_getId_post(auxPost, &auxidPost);
			post_getLikes_post(auxPost, &likesAux);
			post_getMensaje(auxPost, mensajeAux);

			for(j=0; j<ll_len(this1) ;j++)
			{
				auxUser = ll_get(this1, j);
				user_getId(auxUser, &auxidUser_user);

				if(auxidUser_post== auxidUser_user)
				{
					user_getFollowers(auxUser, &followersAux);
					user_getNick(auxUser, nickAux);
					break;
				}
			}

	     printf("%10d - %10d - %10d - %15s - %10d - %20s\n", auxidPost, likesAux, auxidUser_user, nickAux, followersAux, mensajeAux);


		}
		ret=0;
	}

    return ret;
}

int controller_getFeed(LinkedList* this1, LinkedList* this2, LinkedList* this3)
{
	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	int i, j;
	int auxidUser_post, auxidUser_user, auxidPost, followersAux, likesAux ;
	eUser* auxUser=NULL;
	ePost* auxPost=NULL;
	eFeed* auxFeed=NULL;

	if(this1!=NULL && this2!=NULL && this3!=NULL)
	{

		for(i=0; i<ll_len(this2) ;i++)
		{
			auxPost = ll_get(this2,i);
			post_getId_usuario(auxPost, &auxidUser_post);
			post_getId_post(auxPost, &auxidPost);
			post_getLikes_post(auxPost, &likesAux);

			for(j=0; j<ll_len(this1) ;j++)
			{
				auxUser = ll_get(this1, j);
				user_getId(auxUser, &auxidUser_user);
				user_getFollowers(auxUser, &followersAux);

				if(auxidUser_post== auxidUser_user)
				{
					auxFeed= feed_newParametros(auxidUser_user, auxidPost, followersAux, likesAux);
					ll_add(this3, auxFeed);
					break;
				}
			}



		}
		ret=0;
	}

    return ret;
}


int controller_ListFeed(LinkedList* this1, LinkedList* this2, LinkedList* this3)
{
	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	int i, j, z;
	int auxidUser_user, followersAux, auxidPost, likesAux, auxidPostFEED, auxidUserFEED;
	char nickAux[100], mensajeAux[2000];
	eUser* auxUser=NULL;
	ePost* auxPost=NULL;
	eFeed* auxFeed=NULL;

	if(this1!=NULL && this2!=NULL && this3!=NULL)
	{

		for(i=0; i<ll_len(this3) ;i++)
		{
			auxFeed = ll_get(this3,i);
			auxidPostFEED = auxFeed->id_post;
			auxidUserFEED= auxFeed->id_user;

			/*
			post_getId_usuario(auxPost, &auxidUser_post);
			post_getId_post(auxPost, &auxidPost);
			post_getLikes_post(auxPost, &likesAux);
			post_getMensaje(auxPost, mensajeAux);
			*/

			for(j=0; j<ll_len(this1) ;j++)
			{
				auxUser = ll_get(this1, j);
				user_getId(auxUser, &auxidUser_user);

				if(auxidUserFEED== auxidUser_user)
				{
					user_getFollowers(auxUser, &followersAux);
					user_getNick(auxUser, nickAux);

					for(z=0; z<ll_len(this2) ;z++)
					{
						auxPost = ll_get(this2,z);
						post_getId_post(auxPost, &auxidPost);

						if(auxidPost == auxidPostFEED)
						{
							post_getLikes_post(auxPost, &likesAux);
							post_getMensaje(auxPost, mensajeAux);
							break;
						}
					}
					break;
				}
			}

	     printf("%10d - %10d - %10d - %15s - %10d - %20s\n", auxidPost, likesAux, auxidUser_user, nickAux, followersAux, mensajeAux);


		}
		ret=0;
	}

    return ret;
}
/*

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	FILE* miArchivo;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		miArchivo = fopen(path,"rb");

		if(miArchivo!=NULL)
		{
			ret= parser_EmployeeFromBinary(miArchivo, pArrayListEmployee); // si devuelve 0 ok, si -1 error
			fclose(miArchivo);
		}
	}
    return ret;
}



int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
	Employee* pAuxEmployee;
	int pruebaId;
	int pruebaNombre;
	int pruebaSueldo;
	int pruebaHoras;
	char nombreAux[128];
	int horasAux;
	int sueldoAux;
	int ret=-1; //error

	if(pArrayListEmployee!=NULL)
	{
		pAuxEmployee = employee_new();

		if(pAuxEmployee!=NULL)
		{
			getString(nombreAux,"Ingrese un nombre: ","Error, ingrese un nombre: ");
			pruebaNombre=employee_setNombre(pAuxEmployee, nombreAux);

			getInt(&horasAux, "Ingrese las horas trabajadas: ", 0, 500, "Error, ingrese las horas trabajadas: ");
			pruebaHoras=employee_setHorasTrabajadas(pAuxEmployee, horasAux);

			getInt(&sueldoAux, "Ingrese el sueldo: ", 10000, 100000, "Error, ingrese el sueldo: ");
			pruebaSueldo=employee_setSueldo(pAuxEmployee, sueldoAux);

			pruebaId=employee_setId(pAuxEmployee, id);

			if(pruebaId==0 && pruebaNombre==0 && pruebaSueldo==0 && pruebaHoras==0)
			{
				ret= ll_add(pArrayListEmployee, pAuxEmployee);
			}

		}
	}


    return ret;
}




int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int busquedaIndice;
	int campo;
	int idAux;
	char nombreAux[128];
	char nombreNuevo[128];
	int horasAux;
	int horasNuevo;
	int sueldoAux;
	int sueldoNuevo;
	char rta;
	int ret = -1;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
	busquedaIndice = buscarIndice(pArrayListEmployee);


	aux = ll_get(pArrayListEmployee, busquedaIndice);

	if(aux!=NULL)
	{
		printf("\n%5s - %20s - %15s - %10s\n","ID", "NOMBRE", "HS TRABAJADAS", "SUELDO");
		ret= mostrarUnEmpleado(aux, &idAux, nombreAux, &sueldoAux, &horasAux);

		printf("\nElija que campo desea modificar:\n1. Nombre.\n2. Horas trabajadas.\n3. Sueldo.\n4. Volver a la pantalla principal.\n");
		getInt(&campo, "Ingrese su opcion: ", 1, 4, "Ingrese una opcion valida: ");

		switch(campo)
		{
			case 1:
				getString(nombreNuevo,"Ingrese el nuevo nombre: ", "Error, ingrese el nuevo nombre: ");
				printf("Esta por reemplazar el nombre -%s- por -%s-.", nombreAux, nombreNuevo);
				rta = getChar("\nDesea continuar? s/n: ", 's', 'n', "Error. Desea continuar? s/n: ");
				if(rta=='s'){
					ret= employee_setNombre(aux, nombreNuevo);
				}else{
					ret =2; //anular modificacion
				}
				break;

			case 2:
				getInt(&horasNuevo, "Ingrese las horas trabajadas: ", 0, 500, "Error, ingrese las horas trabajadas: ");
				printf("Esta por reemplazar las horas trabajadas de -%d- a -%d-.", horasAux, horasNuevo);
				rta = getChar("\nDesea continuar? s/n: ", 's', 'n', "Error. Desea continuar? s/n: ");
				if(rta=='s'){
					ret=employee_setHorasTrabajadas(aux, horasNuevo);
				}else{
					ret =2; //anular modificacion
				}
				break;

			case 3:
				getInt(&sueldoNuevo, "Ingrese el sueldo: ", 10000, 100000, "Error, ingrese el sueldo: ");
				printf("Esta por reemplazar el sueldo de -%d- a -%d-.", sueldoAux, sueldoNuevo);
				rta = getChar("\nDesea continuar? s/n: ", 's', 'n', "Error. Desea continuar? s/n: ");
				if(rta=='s'){
					ret=employee_setSueldo(aux, sueldoNuevo);
				}else{
					ret =2; //anular modificacion
				}
				break;

			case 4:
				ret =2;//anular modificacion
				break;


		}

		if(ret==0)
		{

			ret= ll_set(pArrayListEmployee, busquedaIndice, aux);
		}



	}
	}


    return ret;
}








int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int busquedaIndice;
	int idAux;
	char nombreAux[128];
	int sueldoAux;
	int horasAux;
	char rta;
	int ret = -1;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
		busquedaIndice = buscarIndice(pArrayListEmployee);

		//aux= ll_pop(pArrayListEmployee, busquedaIndice);  //no lo uso para poder mostrar antes de eliminar y realizar comprobacion

		aux = ll_get(pArrayListEmployee, busquedaIndice);

		if(aux!=NULL)
		{
			printf("%5s - %20s - %15s - %10s\n","ID", "NOMBRE", "HS TRABAJADAS", "SUELDO");
			ret= mostrarUnEmpleado(aux, &idAux, nombreAux, &sueldoAux, &horasAux);

			rta = getChar("Desea eliminar el ID? s/n: ", 's', 'n', "Error, desea eliminar el ID? s/n: ");

			if(rta=='s')
			{
				ret = ll_remove(pArrayListEmployee, busquedaIndice);
			}else
			{
				ret=2; //opcion anular en "analizar situacion" del main
			}

		}
	}
    return ret;
}





int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret =-1; //ERROR
	int campo;
	int orden;

	printf("\nElija un campo de ordenamiento:\n1. Id.\n2. Nombre.\n3. Horas trabajadas.\n4. Sueldo.\n5. Volver a la pantalla principal.\n");
	getInt(&campo, "Ingrese su opcion: ", 1, 5, "Ingrese una opcion valida: ");

	if(campo!=5)
	{
		printf("\nElija un criterio de ordenamiento:\n1. Ascendente.\n0. Descendente.\n");
		getInt(&orden, "Ingrese su opcion: ", 0, 1, "Ingrese una opcion valida: ");

		printf("\nORDENANDO...\n\n");
	}

	switch(campo)
	{
		case 1: //orden por ID
			ret=ll_sort(pArrayListEmployee, employee_CompareById, orden); //1 ascendente 0 descendente
			break;

		case 2: //orden por NOMBRE
			ret= ll_sort(pArrayListEmployee, employee_CompareByName, orden); //1 ascendente 0 descendente
			break;

		case 3: //orden por HORAS TRABAJADAS
			ret= ll_sort(pArrayListEmployee, employee_CompareByHours, orden); //1 ascendente 0 descendente
			break;

		case 4: //orden por SUELDO
			ret= ll_sort(pArrayListEmployee, employee_CompareBySalary, orden); //1 ascendente 0 descendente
			break;

		case 5: //anular ordenamiento
			ret=2; //opcion ANULAR "analizar situacion" en el main
			break;

	}


    return ret;
}
*/

int controller_saveAsText(char* path , LinkedList* this1, LinkedList* this2, LinkedList* this3)
{

	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	int i, j, z;
	int auxidUser_user, followersAux, auxidPost, likesAux, auxidPostFEED, auxidUserFEED;
	char nickAux[100], mensajeAux[2000];
	eUser* auxUser=NULL;
	ePost* auxPost=NULL;
	eFeed* auxFeed=NULL;
	FILE* pFile;

	if(this1!=NULL && this2!=NULL)
	{
	pFile = fopen(path,"w");
	fprintf(pFile,"ID POST,LIKES,ID USER,NICK,FOLLOWERS,POSTEO\n");

	for(i=0; i<ll_len(this3) ;i++)
			{
				auxFeed = ll_get(this3,i);
				auxidPostFEED = auxFeed->id_post;
				auxidUserFEED= auxFeed->id_user;

				/*
				post_getId_usuario(auxPost, &auxidUser_post);
				post_getId_post(auxPost, &auxidPost);
				post_getLikes_post(auxPost, &likesAux);
				post_getMensaje(auxPost, mensajeAux);
				*/

				for(j=0; j<ll_len(this1) ;j++)
				{
					auxUser = ll_get(this1, j);
					user_getId(auxUser, &auxidUser_user);

					if(auxidUserFEED== auxidUser_user)
					{
						user_getFollowers(auxUser, &followersAux);
						user_getNick(auxUser, nickAux);

						for(z=0; z<ll_len(this2) ;z++)
						{
							auxPost = ll_get(this2,z);
							post_getId_post(auxPost, &auxidPost);

							if(auxidPost == auxidPostFEED)
							{
								post_getLikes_post(auxPost, &likesAux);
								post_getMensaje(auxPost, mensajeAux);
								break;
							}
						}
						break;
					}
				}


		 fprintf(pFile, "%d,%d,%d,%s,%d,%s\n", auxidPost, likesAux, auxidUser_user, nickAux, followersAux, mensajeAux);


		}
		ret=0;
	}

	fclose(pFile);
	return ret;

}

/*
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1; //ERROR
	int largo;
	int i;
	Employee* aux;
	FILE* pFile;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
	pFile = fopen(path,"wb");
	largo = ll_len(pArrayListEmployee);

	//printf("%d\n", largo);

	if(pFile!=NULL)
	{

		for(i=0; i<largo; i++)
		{
			aux= ll_get(pArrayListEmployee, i);
			if(aux!=NULL)
			{
				fwrite(aux, sizeof(Employee),1,pFile);
			}
		}

	ret =0; //opcion CORRECTO "analizar situacion" en el main
	fclose(pFile);
	}

	}

    return ret;
}


int buscarIdSinUso (LinkedList* pArrayListEmployee)
{
	int idNuevo=-1; //ERROR
	int largo;
	int i;
	Employee* aux;
	int idAux;
	int maximo;

	if(pArrayListEmployee!=NULL)
	{
		largo = ll_len(pArrayListEmployee);

		for(i=0; i<largo ;i++)
		{
			aux = ll_get(pArrayListEmployee,i);
			if(aux!=NULL)
			{
				employee_getId(aux, &idAux);

				if(i==0 || idAux > maximo)
				{
					maximo=idAux;
				}
			}
		}

		idNuevo=maximo+1;

	}

	return idNuevo;
}



int buscarId(LinkedList* pArrayListEmployee, int idIngresadoPorUsuario)
{
	int indice=-1; //ERROR
    int i;
    int largo;
    int idAux;
    Employee* aux;

    if(pArrayListEmployee!=NULL)
    {
    	largo=ll_len(pArrayListEmployee);


    for(i=0; i<largo; i++)
	    {
    		aux= ll_get(pArrayListEmployee, i);
    		if(aux!=NULL)
    		{
    		employee_getId(aux, &idAux);

	            if(idIngresadoPorUsuario==idAux)
	              {
	                 indice= ll_indexOf(pArrayListEmployee, aux); //se encontro el id
	                 break;
	             }
	        }
	    }

    }
	return indice;
}




int buscarIndice (LinkedList* pArrayListEmployee)
{

	int idIngresado;
	int busquedaIndice;

	controller_ListEmployee(pArrayListEmployee);

	do
	 {
		printf("\nSeleccione un ID de la lista: ");
		scanf("%d", &idIngresado);

		busquedaIndice =buscarId(pArrayListEmployee,idIngresado);

		 switch(busquedaIndice)
			{
			        case -1: //id inexistente
			        printf("\nError. ID inexistente. Ingrese uno valido.\n");
			        break;

			        default: //se encontro el ID
			        break;

			 }

	 }while(busquedaIndice==-1);


	return busquedaIndice;
}
*/
