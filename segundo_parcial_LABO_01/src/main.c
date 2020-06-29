#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "datos.h"

int main(void) {

	setbuf(stdout, NULL);

    LinkedList* listaPosts = ll_newLinkedList();
    LinkedList* listaUser = ll_newLinkedList();
    LinkedList* listaFeed = ll_newLinkedList();


    eUser* auxUser=NULL;
    ePost* auxPost=NULL;
   // eFeed* auxFeed=NULL;





    controller_loadFromText("usuarios.csv", listaUser, parser_UserFromText);
    controller_loadFromText("mensajes.csv", listaPosts, parser_PostFromText);

    printf("\n%10s - %15s - %15s\n", "ID USER", "NICK", "FOLLOWERS");
    controller_List(listaUser, auxUser, user_mostrarUnUser);

    printf("\n%10s - %10s - %10s - %15s\n", "ID POST", "ID USER", "LIKES", "POSTEO");
    controller_List(listaPosts, auxPost, post_mostrarUnPost);

    /*
    controller_ListFinal(listaUser, listaPosts);


    ll_sort(listaUser, user_CompareByNick, 1);
    printf("\n%10s - %15s - %15s\n", "ID USER", "NICK", "FOLLOWERS");
    controller_List(listaUser, auxUser, user_mostrarUnUser);

    ll_sort_dosCampos(listaUser, user_CompareByNick, 0, user_CompareByFollowers, 0);
    printf("\n%10s - %15s - %15s\n", "ID USER", "NICK", "FOLLOWERS");
	controller_List(listaUser, auxUser, user_mostrarUnUser);



*/

	controller_getFeed(listaUser, listaPosts, listaFeed);

	/*
    printf("\n%10s - %15s - %10s - %15s\n", "ID POST","LIKES","ID USER", "FOLLOWERS");
    controller_List(listaFeed, auxFeed, feed_mostrarUnFeed);
*/
    ll_sort_dosCampos(listaFeed, feed_CompareByFollowers, 0, feed_CompareByLikes, 0);
/*
    printf("\n%10s - %15s - %10s - %15s\n", "ID POST","LIKES","ID USER", "FOLLOWERS");
    controller_List(listaFeed, auxFeed, feed_mostrarUnFeed);
*/

    printf("\n%10s - %10s - %10s - %15s - %10s - %20s\n", "ID POST", "LIKES", "ID USER", "NICK" , "FOLLOWERS","POSTEO" );
    controller_ListFeed(listaUser, listaPosts, listaFeed);

	controller_saveAsText("feed.csv", listaUser, listaPosts, listaFeed);




    printf("\nBAI user - %d\n", ll_len(listaUser));
    printf("\nBAI post- %d\n", ll_len(listaPosts));
    printf("\nBAI feed- %d\n", ll_len(listaFeed));

    return 0;
}
