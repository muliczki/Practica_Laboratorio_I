#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "datos.h"





int controller_Uliczki_loadFromText(char* path , LinkedList* this, int pFunc (FILE* , LinkedList*));
int controller_Uliczki_List(LinkedList* this, void* pElemento, int pFunc (void*));
int controller_Uliczki_ListFinal(LinkedList* this1, LinkedList* this2);
int controller_Uliczki_saveAsText(char* path , LinkedList* this);
int controller_Uliczki_cargarListaPilotos(LinkedList* this);
void controller_Uliczki_ElegirPiloto(LinkedList* this, char* nombreElegido);


/*
int controller_loadFromText(char* path , LinkedList* this, int pFunc (FILE* pFile , LinkedList* pArrayListPost));
int controller_List(LinkedList* this, void* pElemento, int pFunc (void* pElemento)); //(void* pElemento));
int controller_ListFinal(LinkedList* this1, LinkedList* this2);
//int controller_saveAsText(char* path , LinkedList* this1, LinkedList* this2, LinkedList* this3);
int controller_getFeed(LinkedList* this1, LinkedList* this2, LinkedList* this3);
int controller_ListFeed(LinkedList* this1, LinkedList* this2, LinkedList* this3);
int controller_saveAsText(char* path , LinkedList* this);

int controller_cargarListaPilotos(LinkedList* this);
int buscarIdSinUso (LinkedList* pArrayListEmployee);
int buscarIndice (LinkedList* pArrayListEmployee);
int buscarId(LinkedList* pArrayListEmployee, int idIngresadoPorUsuario);


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, int id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

*/
