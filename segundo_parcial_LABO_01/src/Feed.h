#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id_user;
    int id_post;
    int followers;
    int likes;

}eFeed;


eFeed* feed_new();
eFeed* feed_newParametros(int id_user, int id_post, int followers, int likes);
int feed_mostrarUnFeed (void* auxiliar);
int feed_CompareByLikes(void* e1, void* e2);
int feed_CompareByFollowers(void* e1, void* e2);

/*
eUser* user_new();
eUser* user_newParametros(char* idStr,char* nickStr,char* followersStr);

void user_delete();

int user_setId(eUser* this,int id);
int user_getId(eUser* this,int* id);

int user_setNick(eUser* this,char* nick);
int user_getNick(eUser* this,char* nick);

int user_setFollowers(eUser* this,int followers);
int user_getFollowers(eUser* this,int* followers);
int user_mostrarUnUser (void* aux);

int user_CompareById(void* e1, void* e2);
int user_CompareByName(void* e1, void* e2);
int user_CompareByHours(void* e1, void* e2);
int user_CompareBySalary(void* e1, void* e2);
*/


