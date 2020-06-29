#include <stdio.h>
#include <stdlib.h>

#include "Fallos.h"
#include "LinkedList.h"
#include "Servicio.h"


int parser_FalloFromText(FILE* pFile , LinkedList* this);

int parser_ServicioFromText(FILE* pFile , LinkedList* this);

int parser_ErrorFromText(FILE* pFile , LinkedList* this);

int parser_UserFromText(FILE* pFile , LinkedList* pArrayListUser);

/*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
*/
