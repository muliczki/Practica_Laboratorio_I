
#include "Feed.h"

eFeed* feed_new()
{
	eFeed* pAux;
	pAux = (eFeed*) malloc(sizeof(eFeed));
	return pAux; //no valido aca que sea NULL porque seria igualmente pasar NULL, cada vez que se llama a esta funcion se verifica el NULL
}




eFeed* feed_newParametros(int id_user, int id_post,int followers, int likes)
{
	eFeed* pAux=NULL;

	pAux=feed_new();

	if(pAux!=NULL)
	{
		//no valido aca, lo hago cuando pido datos.
		//Considero que los datos ya fueron validados antes de ser guardados


		pAux->id_user = id_user;
		pAux->id_post = id_post;
		pAux->followers = followers;
		pAux->likes = likes;

		/*
		pruebaId = user_setId(pAux, atoi(idStr));
		pruebaNick= user_setNick(pAux, nickStr);
		pruebaFollowers= user_setFollowers(pAux, atoi(followersStr));

		if(pruebaId==-1 || pruebaNick==-1 || pruebaFollowers==-1)
		{
			pAux=NULL;
		}
		*/

	}

	return pAux;
}

/*



int user_setNick(eUser* this,char* nick)
{
    int ret = -1;
    if(this!=NULL && nick!=NULL)
    {

        strcpy(this->nick_user , nick);
        ret = 0;
    }


    return ret;

}


int user_getNick(eUser* this,char* nick)
{

    int ret = -1;
    if(this!=NULL && nick!=NULL)
    {

        strcpy(nick,this->nick_user);
        ret = 0;
    }


    return ret;
}



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



int user_setId(eUser* this,int id)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->id_user = id;
        ret = 0;
    }


    return ret;

}


int user_getId(eUser* this,int* id)
{
    int ret = -1;
    if(this!=NULL && id!=NULL)
    {

    	(*id)= this->id_user;
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

		/*
		valor= user_getFollowers(dato1, &numero1);
		valor =user_getFollowers(dato2, &numero2);
		*/
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

		/*
		valor= user_getFollowers(dato1, &numero1);
		valor =user_getFollowers(dato2, &numero2);
		*/
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
	/*
	pruebaId= user_getId(aux, &idAux);
	pruebaNick= user_getNick(aux, nickAux);
	pruebaFollowers= user_getFollowers(aux, &followersAux);

	if(pruebaId==0 && pruebaNick==0 && pruebaFollowers==0)
		{
		}
	*/
	}

	return ret;
}

