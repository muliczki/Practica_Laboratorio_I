#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Pilotos.h"
#include "Servicios.h"
#include "Vuelos.h"


int parser_VueloFromText(FILE* pFile , LinkedList* this);

int parser_ErrorFromText(FILE* pFile , LinkedList* this);

int parser_UserFromText(FILE* pFile , LinkedList* pArrayListUser);

/*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
*/
