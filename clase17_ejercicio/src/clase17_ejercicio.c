/*
 ============================================================================
Crear una funcion (que recibe void). Dicha funcion creara una estructura del
tipo Alumno(legajo, division(un solo caracter) y nota).
Hardcodear datos en la funcion y retornar un puntero a dicha variable.
Mostrar en el main dos veces dicho alumno.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct
{
	int legajo;
	char division;
	float nota;
} typedef eAlumno;

eAlumno* puntearEstructura (void);



int main(void)
{
	eAlumno* punteroAlumno;

	punteroAlumno = puntearEstructura();

	printf("%d - %c - %.2f\n", punteroAlumno->legajo, punteroAlumno->division, punteroAlumno->nota);

	printf("%d - %c - %.2f\n", punteroAlumno->legajo, punteroAlumno->division, punteroAlumno->nota);


	return EXIT_SUCCESS;
}



eAlumno* puntearEstructura (void)
{

	eAlumno* puntero;
	puntero = (eAlumno*) malloc(sizeof(eAlumno));

	if(puntero!=NULL)
	{
	puntero->legajo=100;
	puntero->division='f';
	puntero->nota=7.5;
	}

	return puntero;
}
