#include "Employee.h"

Employee* employee_new()
{
	Employee* pAuxEmpleado;
	pAuxEmpleado = (Employee*) malloc(sizeof(Employee));
	return pAuxEmpleado;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pAuxEmpleado;
	pAuxEmpleado=employee_new();

	if(pAuxEmpleado!=NULL)
	{
		pedirNombreAlUsuario(nombreStr);
	}

	//employee_setNombre(pAuxEmpleado, nombreStr);

	// mal pero para probar:

	return pAuxEmpleado;
}

void pedirNombreAlUsuario (char* nombreStr)
{
	char nombreAux[128];
	int largoString;
	int i;

	printf("Ingrese el nombre: ");
	fflush(stdin);
	//gets(nombreAux);
	//__fpurge(stdin);
	fgets(nombreAux,128,stdin);

	largoString= strlen(nombreAux);       // busco el largo del string
	nombreAux[largoString-1]='\0';
	largoString= strlen(nombreAux);       // busco el largo del string

	strlwr(nombreAux);

	nombreAux[0] = toupper(nombreAux[0]);

	for(i=0; i<largoString; i++)
	{
		if(nombreAux[i]==' ')
		{
			nombreAux[i+1]=toupper(nombreAux[i+1]);
		}
	}



	strcpy(nombreStr, nombreAux);

}

/*
int employee_setNombre(Employee* this,char* nombre)
{

}

int employee_getNombre(Employee* this,char* nombre)
{

}



int employee_setSueldo(Employee* this,int sueldo)
{

}
int employee_getSueldo(Employee* this,int* sueldo)
{


}

int employee_setId(Employee* this,int id)
{

}
int employee_getId(Employee* this,int* id)
{

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{


}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    //verificar nulidad

    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    //verificar nulidad

    if(e1->id > e2->id)
    {
        return 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }



    return strcmp(e1->nombre, e2->nombre);
}
*/


