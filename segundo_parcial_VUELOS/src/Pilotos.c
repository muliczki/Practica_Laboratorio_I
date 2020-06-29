
#include "Pilotos.h"


ePiloto* piloto_new()
{
	ePiloto* pAux;
	pAux = (ePiloto*) malloc(sizeof(ePiloto));
	return pAux; //no valido aca que sea NULL porque seria igualmente pasar NULL, cada vez que se llama a esta funcion se verifica el NULL
}


ePiloto* piloto_newParametros(int id_piloto, char* nombre_piloto)
{
	ePiloto* pAux=NULL;

	if(nombre_piloto!=NULL)
	{
		pAux=piloto_new();

		if(pAux!=NULL)
		{
			//no valido aca, lo hago cuando pido datos.
			//Considero que los datos ya fueron validados antes de ser guardados

			piloto_setId(pAux, id_piloto);
			piloto_setNombre(pAux, nombre_piloto);


			/*
			vuelo_setId_avion(pAux, atoi(id_avionStr));
			vuelo_setId_piloto(pAux, atoi(id_pilotoStr));
			vuelo_setId_vuelo(pAux, atoi(id_vueloStr));
			vuelo_setDestino(pAux, destinoStr);
			vuelo_setFecha(pAux, fechaStr);
			vuelo_setHora_despegue(pAux, atoi(hora_despegue));
			vuelo_setHora_llegada(pAux, atoi(hora_llegada));
			vuelo_setPasajeros(pAux, atoi(pasajeros));

			pAux->id_servicio = atoi(idStr);
			pAux->gravedad_error = atoi(gravedadStr);
			strcpy(pAux->hora_error, horaStr);
			strcpy(pAux->fecha_error, fechaStr);
			strcpy(pAux->mensaje_error, mensajeStr);


			if(pruebaId_post==-1 || pruebaId_usuario==-1 || pruebaLikes==-1 || pruebaMensaje==-1)
			{
				pAux=NULL;
			}
			*/

		}
	}
	return pAux;
}



int piloto_setId(ePiloto* this,int id)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->id_piloto = id;
        ret = 0;
    }


    return ret;

}


int piloto_getId(ePiloto* this,int* id)
{
    int ret = -1;
    if(this!=NULL && id!=NULL)
    {

    	(*id)= this->id_piloto;
        ret = 0;
    }


    return ret;
}







int piloto_setNombre(ePiloto* this,char* nombre)
{
    int ret = -1;
    if(this!=NULL && nombre!=NULL)
    {

        strcpy(this->nombre_piloto , nombre);
        ret = 0;
    }


    return ret;

}


int piloto_getNombre(ePiloto* this,char* nombre)
{

    int ret = -1;
    if(this!=NULL && nombre!=NULL)
    {

        strcpy(nombre,this->nombre_piloto);
        ret = 0;
    }


    return ret;
}


int piloto_mostrarUnPiloto (void* auxiliar)
{
	int ret=-1;
	char  nombre[500];
	int id_piloto;

	if(auxiliar!=NULL)
	{

	ePiloto* pAux = (ePiloto*) auxiliar;

	/*
	gravedad = aux->gravedad_error;
	strcpy(hora ,aux->hora_error);
	strcpy(fecha, aux->fecha_error);
	vuelo_getId_avion(pAux, &id_avion);
	vuelo_getId_piloto(pAux, &id_piloto);
	vuelo_getId_vuelo(pAux, &id_vuelo);
	vuelo_getDestino(pAux, destino);
	vuelo_getFecha(pAux, fecha);
	vuelo_getHora_despegue(pAux, &hora_despegue);
	vuelo_getHora_llegada(pAux, &hora_llegada);
	vuelo_getPasajeros(pAux, &pasajeros);
	*/

	piloto_getId(pAux, &id_piloto);
	piloto_getNombre(pAux, nombre);

	printf("%10d - %20s\n",id_piloto, nombre);

	ret=0;

	}

	return ret;
}

/*

int user_setFollowers(eUser* this,int followers)
{
    int ret = -1;
    if(this!=NULL)
    {
    	this->followers_user = followers;
        ret = 0;
    }


    return ret;
}



int user_getFollowers(eUser* this,int* followers)
{
    int ret = -1;
    if(this!=NULL && followers!=NULL)
    {

    	(*followers)= this->followers_user;
        ret = 0;
    }


    return ret;

}




*/


/*

int employee_CompareById(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int numero1;
	int numero2;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		valor= employee_getId(dato1, &numero1);
		valor = employee_getId(dato2, &numero2);

		if(numero1 > numero2)
		{
			valor=1; //el 1 es MAYOR que el 2
		}
		else if (numero1 < numero2)
		{
			valor =-1; //el 1 es MENOR que el 2
        }
        else
        {
            valor=0; //el 1 y 2 son IGUALES
        }
    }

    return valor;
}


int employee_CompareByName(void* e1, void* e2)
{
	int valor=-10;
	char nombre1[128];
	char nombre2[128];

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		valor = employee_getNombre(dato1,nombre1);
		valor = employee_getNombre(dato2,nombre2);

		valor = strcmp(nombre1, nombre2);

	}

    return valor;
}



int employee_CompareByHours(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int horas1;
	int horas2;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		valor= employee_getHorasTrabajadas(dato1, &horas1);
		valor =employee_getHorasTrabajadas(dato2, &horas2);

		if(horas1 > horas2)
		{
			valor=1; //el 1 es MAYOR que el 2
		}
		else if (horas1 < horas2)
		{
			valor =-1; //el 1 es MENOR que el 2
        }
        else
        {
            valor=0; //el 1 y 2 son IGUALES
        }
    }

    return valor;
}



int employee_CompareBySalary(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int sueldo1;
	int sueldo2;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		valor= employee_getSueldo(dato1, &sueldo1);
		valor= employee_getSueldo(dato2, &sueldo2);

		if(sueldo1 > sueldo2)
		{
			valor=1; //el 1 es MAYOR que el 2
		}
		else if (sueldo1 < sueldo2)
		{
			valor =-1; //el 1 es MENOR que el 2
        }
        else
        {
            valor=0; //el 1 y 2 son IGUALES
        }
    }

    return valor;
}


*/
/*
int feed_CompareByLikes(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int numero1;
	int numero2;

	if(e1!=NULL && e2!=NULL)
	{
		eFeed* dato1 = (eFeed*)e1;
		eFeed* dato2 = (eFeed*)e2;

		numero1 = dato1->likes;
		numero2 = dato2->likes;

		valor= user_getFollowers(dato1, &numero1);
		valor =user_getFollowers(dato2, &numero2);
		if(numero1 > numero2)
		{
			valor=1; //el 1 es MAYOR que el 2
		}
		else if (numero1 < numero2)
		{
			valor =-1; //el 1 es MENOR que el 2
        }
        else
        {
            valor=0; //el 1 y 2 son IGUALES
        }
    }

    return valor;
}

int feed_CompareByFollowers(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int numero1;
	int numero2;

	if(e1!=NULL && e2!=NULL)
	{
		eFeed* dato1 = (eFeed*)e1;
		eFeed* dato2 = (eFeed*)e2;

		numero1 = dato1->followers;
		numero2 = dato2->followers;

		valor= user_getFollowers(dato1, &numero1);
		valor =user_getFollowers(dato2, &numero2);
		if(numero1 > numero2)
		{
			valor=1; //el 1 es MAYOR que el 2
		}
		else if (numero1 < numero2)
		{
			valor =-1; //el 1 es MENOR que el 2
        }
        else
        {
            valor=0; //el 1 y 2 son IGUALES
        }
    }

    return valor;
}

int feed_mostrarUnFeed (void* auxiliar)
{
	int ret=-1;
	int idPost, idUser, followers, likes;

	if(auxiliar!=NULL)
	{

	eFeed* aux = (eFeed*) auxiliar;

	idPost = aux->id_post;
	idUser = aux->id_user;
	followers = aux->followers;
	likes = aux->likes;


	printf("%10d - %15d - %10d - %15d\n", idPost,likes, idUser, followers);
	ret=0;
	pruebaId= user_getId(aux, &idAux);
	pruebaNick= user_getNick(aux, nickAux);
	pruebaFollowers= user_getFollowers(aux, &followersAux);

	if(pruebaId==0 && pruebaNick==0 && pruebaFollowers==0)
		{
		}
	}

	return ret;
}

		*/
