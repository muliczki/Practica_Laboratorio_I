
#include "Post.h"


ePost* post_new()
{
	ePost* pAux;
	pAux = (ePost*) malloc(sizeof(ePost));
	return pAux; //no valido aca que sea NULL porque seria igualmente pasar NULL, cada vez que se llama a esta funcion se verifica el NULL
}




ePost* post_newParametros(char* idPostStr,char* idUserStr,char* likesStr,char* mensajeStr)
{
	ePost* pAux=NULL;
	int pruebaId_post;
	int pruebaId_usuario;
	int pruebaMensaje;
	int pruebaLikes;

	if(idPostStr!=NULL && idUserStr!=NULL && likesStr!=NULL && mensajeStr!=NULL)
	{
		pAux=post_new();

		if(pAux!=NULL)
		{
			//no valido aca, lo hago cuando pido datos.
			//Considero que los datos ya fueron validados antes de ser guardados

			pruebaId_post = post_setId_post(pAux, atoi(idPostStr));
			pruebaId_usuario = post_setId_usuario(pAux, atoi(idUserStr));
			pruebaMensaje= post_setMensaje(pAux, mensajeStr);
			pruebaLikes= post_setLikes_post(pAux, atoi(likesStr));

			/*
			pAux->id_post = atoi(idPostStr);
			pAux->id_user = atoi(idUserStr);
			pAux->likes_post = atoi(likesStr);
			strcpy(pAux->mensaje, mensajeStr);
			*/

			if(pruebaId_post==-1 || pruebaId_usuario==-1 || pruebaLikes==-1 || pruebaMensaje==-1)
			{
				pAux=NULL;
			}

		}
	}
	return pAux;
}



int post_setMensaje(ePost* this,char* mensaje)
{

    int ret = -1;
    if(this!=NULL && mensaje!=NULL)
    {

        strcpy(this->mensaje , mensaje);
        ret = 0;
    }

    return ret;

}


int post_getMensaje(ePost* this,char* mensaje)
{

    int ret = -1;
    if(this!=NULL && mensaje!=NULL)
    {

        strcpy(mensaje,this->mensaje);
        ret = 0;
    }

    return ret;
}



int post_setId_usuario(ePost* this,int id_usuario)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->id_user = id_usuario;
        ret = 0;
    }


    return ret;
}



int post_getId_usuario(ePost* this,int* id_usuario)
{
    int ret = -1;
    if(this!=NULL && id_usuario!=NULL)
    {

    	(*id_usuario)= this->id_user;
        ret = 0;
    }


    return ret;

}



int post_setId_post(ePost* this,int id_post)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->id_post = id_post;
        ret = 0;
    }


    return ret;

}



int post_getId_post(ePost* this,int* id_post)
{
    int ret = -1;
    if(this!=NULL && id_post!=NULL)
    {

    	(*id_post)= this->id_post;
        ret = 0;
    }


    return ret;
}



int post_setLikes_post(ePost* this,int likes_post)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->likes_post = likes_post;
        ret = 0;
    }


    return ret;
}



int post_getLikes_post(ePost* this,int* likes_post)
{
    int ret = -1;
    if(this!=NULL && likes_post!=NULL)
    {
    	(*likes_post)= this->likes_post;
        ret = 0;
    }


    return ret;

}

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

int post_mostrarUnPost (void* auxiliar)
{
	int ret=-1;
	int pruebaIdPost, pruebaIdUser, pruebaLikes, pruebaMensaje;
	int idUserAux, idPostAux, LikesAux;
	char mensajeAux[2000];

	if(auxiliar!=NULL)
	{

	ePost* aux = (ePost*) auxiliar;

	pruebaIdPost= post_getId_post(aux, &idPostAux);
	pruebaIdUser= post_getId_usuario(aux, &idUserAux);
	pruebaLikes= post_getLikes_post(aux, &LikesAux);
	pruebaMensaje= post_getMensaje(aux, mensajeAux);

	if(pruebaIdPost==0 && pruebaIdUser==0 && pruebaLikes==0 && pruebaMensaje==0)
		{
		printf("%10d - %10d - %10d - %15s\n", idPostAux, idUserAux, LikesAux, mensajeAux);
		ret=0;
		}
	}

	return ret;
}
