#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id_vuelo;
    int id_avion;
    int id_piloto;
    char fecha[65];
    char destino[60];
    int cant_pasajeros;
    int hora_despegue;
    int hora_llegada;
}eVuelo;

eVuelo* vuelo_new();
eVuelo* vuelo_newParametros(char* id_vueloStr,char* id_avionStr,char* id_pilotoStr,char* fechaStr, char* destinoStr, char* pasajeros, char*hora_despegue, char* hora_llegada );

int vuelo_mostrarUnVuelo (void* auxiliar);

int vuelo_setFecha(eVuelo* this,char* fecha);
int vuelo_getFecha(eVuelo* this,char* fecha);

int vuelo_setDestino(eVuelo* this,char* destino);
int vuelo_getDestino(eVuelo* this,char* destino);

int vuelo_setId_vuelo(eVuelo* this,int id_vuelo);
int vuelo_getId_vuelo(eVuelo* this,int* id_vuelo);

int vuelo_setId_avion(eVuelo* this,int id_avion);
int vuelo_getId_avion(eVuelo* this,int* id_avion);

int vuelo_setId_piloto(eVuelo* this,int id_piloto);
int vuelo_getId_piloto(eVuelo* this,int* id_piloto);

int vuelo_setHora_despegue(eVuelo* this,int hora_despegue);
int vuelo_getHora_despegue(eVuelo* this,int* hora_despegue);

int vuelo_setHora_llegada(eVuelo* this,int hora_llegada);
int vuelo_getHora_llegada(eVuelo* this,int* hora_llegada);

int vuelo_setPasajeros(eVuelo* this,int pasajeros);
int vuelo_getPasajeros(eVuelo* this,int* pasajeros);


int vuelo_contarPasajeros (void* this);
int vuelo_contarPasajerosIrlanda (void* v1);

int vuelo_ComparoDuracion(void* e1);
int vuelo_soloPortugal(void* e1);
int vuelo_SIN_ALEX(void* e1);

/*
void post_delete();

int post_setId_post(eVuelo* this,int id_post);
int post_getId_post(eVuelo* this,int* id_post);

int post_setId_usuario(eVuelo* this,int id_usuario);
int post_getId_usuario(eVuelo* this,int* id_usuario);

int post_setMensaje(eVuelo* this,char* mensaje);
int post_getMensaje(eVuelo* this,char* mensaje);

int post_setLikes_post(eVuelo* this,int likes_post);
int post_getLikes_post(eVuelo* this,int* likes_post);

int post_mostrarUnPost (void* auxiliar);
*/
/*
int employee_CompareById(void* e1, void* e2);
int employee_CompareByName(void* e1, void* e2);
int employee_CompareByHours(void* e1, void* e2);
int employee_CompareBySalary(void* e1, void* e2);
int mostrarUnEmpleado (Employee* aux, int* idAux, char* nombreAux, int* sueldoAux, int* horasAux);
*/


#endif // employee_H_INCLUDED
