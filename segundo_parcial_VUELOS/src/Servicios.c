
#include "Servicios.h"


eUser* user_new()
{
	eUser* pAux;
	pAux = (eUser*) malloc(sizeof(eUser));
	return pAux; //no valido aca que sea NULL porque seria igualmente pasar NULL, cada vez que se llama a esta funcion se verifica el NULL
}




eUser* user_newParametros(char* idStr,char* nickStr,char* followersStr)
{
	eUser* pAux=NULL;
	int pruebaId;
	int pruebaNick;
	int pruebaFollowers;

	if(idStr!=NULL && nickStr!=NULL && followersStr!=NULL)
	{
		pAux=user_new();

		if(pAux!=NULL)
		{
			//no valido aca, lo hago cuando pido datos.
			//Considero que los datos ya fueron validados antes de ser guardados

			/*
			pAux->id_user = atoi(idStr);
			pAux->followers_user = atoi(followersStr);
			strcpy(pAux->nick_user, nickStr);
			*/

			pruebaId = user_setId(pAux, atoi(idStr));
			pruebaNick= user_setNick(pAux, nickStr);
			pruebaFollowers= user_setFollowers(pAux, atoi(followersStr));

			if(pruebaId==-1 || pruebaNick==-1 || pruebaFollowers==-1)
			{
				pAux=NULL;
			}

		}
	}
	return pAux;
}




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



int user_CompareById(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int numero1;
	int numero2;

	if(e1!=NULL && e2!=NULL)
	{
		eUser* dato1 = (eUser*)e1;
		eUser* dato2 = (eUser*)e2;

		valor= user_getId(dato1, &numero1);
		valor = user_getId(dato2, &numero2);

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


int user_CompareByNick(void* e1, void* e2)
{
	int valor=-10;
	char str1[128];
	char str2[128];

	if(e1!=NULL && e2!=NULL)
	{
		eUser* dato1 = (eUser*)e1;
		eUser* dato2 = (eUser*)e2;

		valor = user_getNick(dato1,str1);
		valor = user_getNick(dato2,str2);

		valor = strcmp(str1, str2);

	}

    return valor;
}



int user_CompareByFollowers(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int numero1;
	int numero2;

	if(e1!=NULL && e2!=NULL)
	{
		eUser* dato1 = (eUser*)e1;
		eUser* dato2 = (eUser*)e2;

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




int user_mostrarUnUser (void* auxiliar)
{
	int ret=-1;
	int pruebaId, pruebaNick, pruebaFollowers;
	int idAux, followersAux;
	char nickAux[128];

	if(auxiliar!=NULL)
	{

	eUser* aux = (eUser*) auxiliar;

	pruebaId= user_getId(aux, &idAux);
	pruebaNick= user_getNick(aux, nickAux);
	pruebaFollowers= user_getFollowers(aux, &followersAux);

	if(pruebaId==0 && pruebaNick==0 && pruebaFollowers==0)
		{
		printf("%10d - %15s - %15d\n", idAux, nickAux, followersAux);
		ret=0;
		}
	}

	return ret;
}
