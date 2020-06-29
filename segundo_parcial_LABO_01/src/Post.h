#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id_post;
    int id_user;
    int likes_post;
    char mensaje[2000];
}ePost;

ePost* post_new();
ePost* post_newParametros(char* idPostStr,char* idUserStr,char* likesStr,char* mensajeStr);

void post_delete();

int post_setId_post(ePost* this,int id_post);
int post_getId_post(ePost* this,int* id_post);

int post_setId_usuario(ePost* this,int id_usuario);
int post_getId_usuario(ePost* this,int* id_usuario);

int post_setMensaje(ePost* this,char* mensaje);
int post_getMensaje(ePost* this,char* mensaje);

int post_setLikes_post(ePost* this,int likes_post);
int post_getLikes_post(ePost* this,int* likes_post);

int post_mostrarUnPost (void* auxiliar);

/*
int employee_CompareById(void* e1, void* e2);
int employee_CompareByName(void* e1, void* e2);
int employee_CompareByHours(void* e1, void* e2);
int employee_CompareBySalary(void* e1, void* e2);
int mostrarUnEmpleado (Employee* aux, int* idAux, char* nombreAux, int* sueldoAux, int* horasAux);
*/


#endif // employee_H_INCLUDED
