
#include "Fallos.h"


eFallo* fallo_new()
{
	eFallo* pAux;
	pAux = (eFallo*) malloc(sizeof(eFallo));
	return pAux; //no valido aca que sea NULL porque seria igualmente pasar NULL, cada vez que se llama a esta funcion se verifica el NULL
}



eFallo* fallo_newParametros(char* fechaStr, char* horaStr, char* id_servicio, char* gravedad, char* mensaje_error )
{
	eFallo* pAux=NULL;

	if(fechaStr!=NULL && id_servicio!=NULL && mensaje_error!=NULL && gravedad!=NULL && horaStr!=NULL )
	{
		pAux=fallo_new();

		if(pAux!=NULL)
		{
			//no valido aca, lo hago cuando pido datos.
			//Considero que los datos ya fueron validados antes de ser guardados


			fallo_setFecha(pAux, fechaStr);
			fallo_setGravedad(pAux, atoi(gravedad));
			fallo_setId_servicio(pAux, atoi(id_servicio));
			fallo_setHora(pAux, horaStr);
			fallo_setMensaje(pAux, mensaje_error);

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





int fallo_setFecha(eFallo* this,char* fecha)
{

    int ret = -1;
    if(this!=NULL && fecha!=NULL)
    {

        strcpy(this->fecha , fecha);
        ret = 0;
    }

    return ret;

}


int fallo_getFecha(eFallo* this,char* fecha)
{

    int ret = -1;
    if(this!=NULL && fecha!=NULL)
    {

        strcpy(fecha,this->fecha);
        ret = 0;
    }

    return ret;
}

int fallo_setMensaje(eFallo* this,char* mensaje)
{

    int ret = -1;
    if(this!=NULL && mensaje!=NULL)
    {

        strcpy(this->mensaje_error , mensaje);
        ret = 0;
    }

    return ret;

}


int fallo_getMensaje(eFallo* this,char* mensaje)
{

    int ret = -1;
    if(this!=NULL && mensaje!=NULL)
    {

        strcpy(mensaje,this->mensaje_error);
        ret = 0;
    }

    return ret;
}


int fallo_setId_servicio(eFallo* this,int id_servicio)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->id_servicio = id_servicio;
        ret = 0;
    }


    return ret;
}



int fallo_getId_servicio(eFallo* this,int* id_servicio)
{
    int ret = -1;
    if(this!=NULL && id_servicio!=NULL)
    {

    	(*id_servicio)= this->id_servicio;
        ret = 0;
    }


    return ret;

}


int fallo_setHora(eFallo* this,char* hora)
{
    int ret = -1;
    if(this!=NULL && hora!=NULL)
    {
		 strcpy(this->hora , hora);
		 ret = 0;
    }


    return ret;
}



int fallo_getHora(eFallo* this,char* hora)
{
    int ret = -1;
    if(this!=NULL && hora!=NULL)
    {
        strcpy(hora,this->hora);
        ret = 0;
    }


    return ret;

}


int fallo_setGravedad(eFallo* this,int gravedad)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->gravedad = gravedad;
        ret = 0;
    }


    return ret;
}



int fallo_getGravedad(eFallo* this,int* gravedad)
{
    int ret = -1;
    if(this!=NULL && gravedad!=NULL)
    {
    	(*gravedad)= this->gravedad;
        ret = 0;
    }


    return ret;

}

///////////////////   VUELOS
/*
eVuelo* vuelo_new()
{
	eVuelo* pAux;
	pAux = (eVuelo*) malloc(sizeof(eVuelo));
	return pAux; //no valido aca que sea NULL porque seria igualmente pasar NULL, cada vez que se llama a esta funcion se verifica el NULL
}




eVuelo* vuelo_newParametros(char* id_vueloStr,char* id_avionStr,char* id_pilotoStr,char* fechaStr, char* destinoStr, char* pasajeros, char*hora_despegue, char* hora_llegada )
{
	eVuelo* pAux=NULL;

	if(fechaStr!=NULL && id_avionStr!=NULL && id_pilotoStr!=NULL && id_pilotoStr!=NULL && destinoStr!=NULL && hora_despegue!=NULL && hora_llegada!=NULL && pasajeros!=NULL)
	{
		pAux=vuelo_new();

		if(pAux!=NULL)
		{
			//no valido aca, lo hago cuando pido datos.
			//Considero que los datos ya fueron validados antes de ser guardados



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






		}
	}
	return pAux;
}



int vuelo_setFecha(eVuelo* this,char* fecha)
{

    int ret = -1;
    if(this!=NULL && fecha!=NULL)
    {

        strcpy(this->fecha , fecha);
        ret = 0;
    }

    return ret;

}


int vuelo_getFecha(eVuelo* this,char* fecha)
{

    int ret = -1;
    if(this!=NULL && fecha!=NULL)
    {

        strcpy(fecha,this->fecha);
        ret = 0;
    }

    return ret;
}

int vuelo_setDestino(eVuelo* this,char* destino)
{

    int ret = -1;
    if(this!=NULL && destino!=NULL)
    {

        strcpy(this->destino , destino);
        ret = 0;
    }

    return ret;

}


int vuelo_getDestino(eVuelo* this,char* destino)
{

    int ret = -1;
    if(this!=NULL && destino!=NULL)
    {

        strcpy(destino,this->destino);
        ret = 0;
    }

    return ret;
}


int vuelo_setId_vuelo(eVuelo* this,int id_vuelo)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->id_vuelo = id_vuelo;
        ret = 0;
    }


    return ret;
}



int vuelo_getId_vuelo(eVuelo* this,int* id_vuelo)
{
    int ret = -1;
    if(this!=NULL && id_vuelo!=NULL)
    {

    	(*id_vuelo)= this->id_vuelo;
        ret = 0;
    }


    return ret;

}



int vuelo_setId_avion(eVuelo* this,int id_avion)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->id_avion = id_avion;
        ret = 0;
    }


    return ret;

}



int vuelo_getId_avion(eVuelo* this,int* id_avion)
{
    int ret = -1;
    if(this!=NULL && id_avion!=NULL)
    {

    	(*id_avion)= this->id_avion;
        ret = 0;
    }


    return ret;
}

int vuelo_setId_piloto(eVuelo* this,int id_piloto)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->id_piloto = id_piloto;
        ret = 0;
    }


    return ret;

}



int vuelo_getId_piloto(eVuelo* this,int* id_piloto)
{
    int ret = -1;
    if(this!=NULL && id_piloto!=NULL)
    {

    	(*id_piloto)= this->id_piloto;
        ret = 0;
    }


    return ret;
}








int vuelo_setHora_despegue(eVuelo* this,int hora_despegue)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->hora_despegue = hora_despegue;
        ret = 0;
    }


    return ret;
}



int vuelo_getHora_despegue(eVuelo* this,int* hora_despegue)
{
    int ret = -1;
    if(this!=NULL && hora_despegue!=NULL)
    {
    	(*hora_despegue)= this->hora_despegue;
        ret = 0;
    }


    return ret;

}


int vuelo_setHora_llegada(eVuelo* this,int hora_llegada)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->hora_llegada = hora_llegada;
        ret = 0;
    }


    return ret;
}



int vuelo_getHora_llegada(eVuelo* this,int* hora_llegada)
{
    int ret = -1;
    if(this!=NULL && hora_llegada!=NULL)
    {
    	(*hora_llegada)= this->hora_llegada;
        ret = 0;
    }


    return ret;

}

int vuelo_setPasajeros(eVuelo* this,int pasajeros)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->cant_pasajeros = pasajeros;
        ret = 0;
    }


    return ret;
}



int vuelo_getPasajeros(eVuelo* this,int* pasajeros)
{
    int ret = -1;
    if(this!=NULL && pasajeros!=NULL)
    {
    	(*pasajeros)= this->cant_pasajeros;
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




int vuelo_mostrarUnVuelo (void* auxiliar)
{
	int ret=-1;
	char  fecha[500], destino[500];
	int id_vuelo, id_avion, id_piloto, hora_despegue, hora_llegada, pasajeros;

	if(auxiliar!=NULL)
	{

	eVuelo* pAux = (eVuelo*) auxiliar;


	id= aux->id_servicio;
	gravedad = aux->gravedad_error;
	strcpy(hora ,aux->hora_error);
	strcpy(fecha, aux->fecha_error);
	strcpy(mensaje,aux->mensaje_error);


	vuelo_getId_avion(pAux, &id_avion);
	vuelo_getId_piloto(pAux, &id_piloto);
	vuelo_getId_vuelo(pAux, &id_vuelo);
	vuelo_getDestino(pAux, destino);
	vuelo_getFecha(pAux, fecha);
	vuelo_getHora_despegue(pAux, &hora_despegue);
	vuelo_getHora_llegada(pAux, &hora_llegada);
	vuelo_getPasajeros(pAux, &pasajeros);


	printf("%10d - %10d - %10d - %20s - %20s - %10d - %15d - %15d\n", id_vuelo, id_avion, id_piloto, fecha, destino,pasajeros,hora_despegue, hora_llegada);

		ret=0;
	}

	return ret;
}


int vuelo_contarPasajeros (void* v1)
{
	int contar=0;

	if(v1!=NULL)
	{
	eVuelo* dato1 = (eVuelo*)v1;

	vuelo_getPasajeros(dato1, &contar);

	}

	return contar;
}

int vuelo_contarPasajerosIrlanda (void* v1)
{
	int contar=0;
	char destino[60];

	if(v1!=NULL)
	{
	eVuelo* dato1 = (eVuelo*)v1;

	vuelo_getDestino(dato1, destino);
	if(strcmp(destino, "Irlanda")==0)
	{
		vuelo_getPasajeros(dato1, &contar);
	}

	}

	return contar;
}

int vuelo_ComparoDuracion(void* e1)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int horas_despegue;
	int horas2_llegada;

	if(e1!=NULL)
	{
		eVuelo* dato1 = (eVuelo*)e1;

		vuelo_getHora_despegue(dato1, &horas_despegue);
		vuelo_getHora_llegada(dato1, &horas2_llegada);

		if(horas2_llegada-horas_despegue<3)
		{
			valor=1;
		}else{
			valor=0;
		}

    }

    return valor;
}


int vuelo_soloPortugal(void* e1)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	char destino[60];

	if(e1!=NULL)
	{
		eVuelo* dato1 = (eVuelo*)e1;

		vuelo_getDestino(dato1, destino);

		if(strcmp(destino, "Portugal")==0)
		{
			valor=1;
		}else{
			valor=0;
		}

    }

    return valor;
}


int vuelo_SIN_ALEX(void* e1)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int id_piloto;

	if(e1!=NULL)
	{
		eVuelo* dato1 = (eVuelo*)e1;

		vuelo_getId_piloto(dato1, &id_piloto);

		if(id_piloto==1) //id alex =1
		{
			valor=0;
		}else{
			valor=1;
		}

    }

    return valor;
}

*/


int fallo_gravedadCuatroSiete(void* e1)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int gravedad;

	if(e1!=NULL)
	{
		eFallo* dato1 = (eFallo*)e1;

		fallo_getGravedad(dato1, &gravedad);

		if(gravedad>=4 && gravedad<=7) //id alex =1
		{
			valor=1;
		}else{
			valor=0;
		}

    }

    return valor;
}

int fallo_gravedadTresMenos45(void* e1)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int gravedad, id;

	if(e1!=NULL)
	{
		eFallo* dato1 = (eFallo*)e1;

		fallo_getGravedad(dato1, &gravedad);
		fallo_getId_servicio(dato1, &id);

		if(gravedad==3 && id!=45) //id alex =1
		{
			valor=1;
		}else{
			valor=0;
		}

    }

    return valor;
}


int fallo_gravedadMayorSiete(void* e1)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int gravedad;

	if(e1!=NULL)
	{
		eFallo* dato1 = (eFallo*)e1;

		fallo_getGravedad(dato1, &gravedad);

		if(gravedad>7) //id alex =1
		{
			valor=1;
		}else{
			valor=0;
		}

    }

    return valor;
}


int fallo_contarGravedadMenor3 (void* v1)
{
	int contar=0, gravedad;

	if(v1!=NULL)
	{
	eFallo* dato1 = (eFallo*)v1;

	fallo_getGravedad(dato1, &gravedad);
	if(gravedad<3)
	{
		contar++;
	}

	}

	return contar;
}

int fallo_contarGravedadIgual3 (void* v1)
{
	int contar=0, gravedad;

	if(v1!=NULL)
	{
	eFallo* dato1 = (eFallo*)v1;

	fallo_getGravedad(dato1, &gravedad);
	if(gravedad==3)
	{
		contar++;
	}

	}

	return contar;
}


int fallo_contarGravedadEntre4y7 (void* v1)
{
	int contar=0, gravedad;

	if(v1!=NULL)
	{
	eFallo* dato1 = (eFallo*)v1;

	fallo_getGravedad(dato1, &gravedad);
	if(gravedad>=4 && gravedad<=7)
	{
		contar++;
	}

	}

	return contar;
}


int fallo_contarGravedadMayor7 (void* v1)
{
	int contar=0, gravedad;

	if(v1!=NULL)
	{
	eFallo* dato1 = (eFallo*)v1;

	fallo_getGravedad(dato1, &gravedad);
	if(gravedad>7)
	{
		contar++;
	}

	}

	return contar;
}

int fallo_contarPorServicio (void* v1, int idServicio)
{
	int contar=0, id_servicio;

	if(v1!=NULL)
	{
	eFallo* dato1 = (eFallo*)v1;

	fallo_getId_servicio(dato1, &id_servicio);
	if(id_servicio==idServicio)
	{
		contar++;
	}

	}

	return contar;
}


int fallo_mostrarUnFallo (void* auxiliar)
{
	int ret=-1;
	char  fecha[500], hora[500], mensaje_error[500];
	int id_servicio, gravedad;

	if(auxiliar!=NULL)
	{

	eFallo* pAux = (eFallo*) auxiliar;

	fallo_getFecha(pAux, fecha);
	fallo_getGravedad(pAux, &gravedad);
	fallo_getId_servicio(pAux, &id_servicio);
	fallo_getHora(pAux, hora);
	fallo_getMensaje(pAux, mensaje_error);

	/*
	id= aux->id_servicio;
	gravedad = aux->gravedad_error;
	strcpy(hora ,aux->hora_error);
	strcpy(fecha, aux->fecha_error);
	strcpy(mensaje,aux->mensaje_error);


	vuelo_getId_avion(pAux, &id_avion);
	vuelo_getId_piloto(pAux, &id_piloto);
	vuelo_getId_vuelo(pAux, &id_vuelo);
	vuelo_getDestino(pAux, destino);
	vuelo_getFecha(pAux, fecha);
	vuelo_getHora_despegue(pAux, &hora_despegue);
	vuelo_getHora_llegada(pAux, &hora_llegada);
	vuelo_getPasajeros(pAux, &pasajeros);

	*/


	printf("%20s - %10s - %10d - %20d - %20s\n", fecha, hora, id_servicio, gravedad, mensaje_error);
		ret=0;
	}

	return ret;
}

