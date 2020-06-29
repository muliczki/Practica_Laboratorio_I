#include <stdio.h>
#include <stdlib.h>

#include "Controller_Uliczki.h"
#include "LinkedList.h"
#include "datos.h"

int main(void) {

	setbuf(stdout, NULL);

	int pasajeros, opcion;
	char nombreElegido[70];
    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();
    LinkedList* vuelosCortos =NULL;
    LinkedList* soloPortugal =NULL;
    LinkedList* sinAlex =NULL;
    LinkedList* pilotoEleccion =NULL;

   // eVuelo* auxVuelo=NULL;
   // ePiloto* auxPiloto=NULL;


    //printf("\n vuelos - %d\n", ll_len(listaVuelos));

    if(listaVuelos!=NULL && listaPilotos!=NULL)
    {
	do{


		opcion = mostrarMenu();

		// para corroborar que si la lista esta vacia no entre en todas las opciones del menu
		if(ll_isEmpty(listaVuelos)==1 && (opcion!=1 && opcion!=9)){ // disponible solo opcion cargar archivo & salir
			printf("\nLISTA VACIA. POR FAVOR, CARGUE UN ARCHIVO\n\n");
		}else if(ll_isEmpty(listaVuelos)==0 && opcion==1){
			printf("\nLISTA CON INFORMACION. NO PUEDE CARGAR OTRO ARCHIVO\n\n");
		}
		else{

			switch(opcion)
			{
			case 1:
				controller_Uliczki_loadFromText("Vuelos.csv", listaVuelos, parser_VueloFromText);
				controller_Uliczki_loadFromText("pilotos.csv", listaPilotos, parser_PilotoFromText);

				/*
				printf("%10s - %20s - %20s\n","id_piloto", "nombre", "apellido");
				controller_Uliczki_List(listaPilotos, auxPiloto,piloto_mostrarUnPiloto);
				*/
				//controller_Uliczki_cargarListaPilotos(listaPilotos);
				printf("\nARCHIVO CARGADO\n\n");
				break;

		/* MUESTRO ARCHIVO
		printf("%10s - %10s - %10s - %20s - %20s - %10s- %15s - %15s\n", "id_vuelo", "id_avion", "id_piloto", "fecha", "destino","pasajeros","hora_despegue", "hora_llegada");
		controller_List(listaVuelos, auxVuelo, vuelo_mostrarUnVuelo);
	*/
			case 2:
				///MUESTRO CON PILOTOS
				/*
				printf("%10s - %20s\n","id_piloto", "nombre");
				controller_Uliczki_List(listaPilotos, auxPiloto, piloto_mostrarUnPiloto);
				*/
				printf("\nLISTA DE VUELOS CON PILOTOS\n");
				printf("%10s - %10s - %20s - %20s - %20s - %20s - %10s- %15s - %15s\n", "id_vuelo", "id_avion", "nombre piloto", "apellido piloto","fecha", "destino","pasajeros","hora_despegue", "hora_llegada");
				controller_Uliczki_ListFinal(listaPilotos, listaVuelos);
				printf("\n\n");
				break;

			case 3:
				// CANTIDAD PASAJEROS
				pasajeros = ll_count(listaVuelos, vuelo_contarPasajeros);
				printf("\n\nPASAJEROS TOTALES: %d\n", pasajeros);
				printf("\n\n");
				break;

			case 4:
				// PASAJEROS A IRLANDA
				pasajeros = ll_count(listaVuelos, vuelo_contarPasajerosIrlanda);
				printf("\n\nPASAJEROS IRLANDA: %d\n", pasajeros);
				printf("\n\n");
				break;


			case 5:
				// VUELOS CORTOS
				vuelosCortos = ll_filter(listaVuelos, vuelo_ComparoDuracion);
				controller_Uliczki_saveAsText("vuelos_cortos.csv", vuelosCortos);
				printf("\nARCHIVO GENERADO >>> VUELOS CORTOS\n");
				printf("\n\n");
			   // printf("%10s - %10s - %10s - %20s - %20s - %10s- %15s - %15s\n", "id_vuelo", "id_avion", "id_piloto", "fecha", "destino","pasajeros","hora_despegue", "hora_llegada");
				//controller_List(vuelosCortos, auxVuelo, vuelo_mostrarUnVuelo);
				break;

			case 6:
				//VUELOS A PORTUGAL
				printf("\nVUELOS A PORTUGAL\n");
				soloPortugal = ll_filter(listaVuelos, vuelo_soloPortugal);
				printf("%10s - %10s - %20s - %20s - %20s - %20s - %10s- %15s - %15s\n", "id_vuelo", "id_avion", "nombre piloto", "apellido piloto","fecha", "destino","pasajeros","hora_despegue", "hora_llegada");
				//printf("%10s - %10s - %20s - %20s - %20s - %10s- %15s - %15s\n", "id_vuelo", "id_avion", "piloto", "fecha", "destino","pasajeros","hora_despegue", "hora_llegada");
				controller_Uliczki_ListFinal(listaPilotos, soloPortugal);
				printf("\n\n");
				break;

			case 7:
				//VUELOS SIN ALEX
				printf("\nVUELOS SIN ALEX\n");
				sinAlex = ll_filter(listaVuelos, vuelo_SIN_ALEX);
				printf("%10s - %10s - %20s - %20s - %20s - %20s - %10s- %15s - %15s\n", "id_vuelo", "id_avion", "nombre piloto", "apellido piloto","fecha", "destino","pasajeros","hora_despegue", "hora_llegada");
				//printf("%10s - %10s - %20s - %20s - %20s - %10s- %15s - %15s\n", "id_vuelo", "id_avion", "piloto", "fecha", "destino","pasajeros","hora_despegue", "hora_llegada");
				controller_Uliczki_ListFinal(listaPilotos, sinAlex);
				printf("\n\n");
				break;

			case 8:
				//VUELOS SIN ALEX
				printf("\nVUELOS POR PILOTO\n");
				controller_Uliczki_ElegirPiloto(listaPilotos, nombreElegido);
				pilotoEleccion = ll_filter_parametro(listaPilotos, nombreElegido, piloto_filtroPorNombre);
				printf("%10s - %10s - %20s - %20s - %20s - %20s - %10s- %15s - %15s\n", "id_vuelo", "id_avion", "nombre piloto", "apellido piloto","fecha", "destino","pasajeros","hora_despegue", "hora_llegada");
				controller_Uliczki_ListFinal(pilotoEleccion, listaVuelos);
				printf("\n\n");
				break;


			}
		}

	}while(opcion!=9);

    }

    return 0;
}

   // controller_loadFromText("mensajes.csv", listaPosts, parser_PostFromText);

    /*
    printf("%10s - %10s - %10s - %10s - %15s\n", "FECHA", "HORA", "ID SERV", "GRAV", "MENSAJE");
    controller_List(listaErrores, auxError, error_mostrarUnError);
*/
   /*
    printf("\n%10s - %10s - %10s - %15s\n", "ID POST", "ID USER", "LIKES", "POSTEO");
*/
    /*
    controller_ListFinal(listaUser, listaPosts);


    ll_sort(listaUser, user_CompareByNick, 1);
    printf("\n%10s - %15s - %15s\n", "ID USER", "NICK", "FOLLOWERS");
    controller_List(listaUser, auxUser, user_mostrarUnUser);

    ll_sort_dosCampos(listaUser, user_CompareByNick, 0, user_CompareByFollowers, 0);
    printf("\n%10s - %15s - %15s\n", "ID USER", "NICK", "FOLLOWERS");
	controller_List(listaUser, auxUser, user_mostrarUnUser);




	controller_getFeed(listaUser, listaPosts, listaFeed);

    printf("\n%10s - %15s - %10s - %15s\n", "ID POST","LIKES","ID USER", "FOLLOWERS");
    controller_List(listaFeed, auxFeed, feed_mostrarUnFeed);
    ll_sort_dosCampos(listaFeed, feed_CompareByFollowers, 0, feed_CompareByLikes, 0);
    printf("\n%10s - %15s - %10s - %15s\n", "ID POST","LIKES","ID USER", "FOLLOWERS");
    controller_List(listaFeed, auxFeed, feed_mostrarUnFeed);

    printf("\n%10s - %10s - %10s - %15s - %10s - %20s\n", "ID POST", "LIKES", "ID USER", "NICK" , "FOLLOWERS","POSTEO" );
    controller_ListFeed(listaUser, listaPosts, listaFeed);

	controller_saveAsText("feed.csv", listaUser, listaPosts, listaFeed);

    printf("\nBAI post- %d\n", ll_len(listaPosts));
    printf("\nBAI feed- %d\n", ll_len(listaFeed));
*/

