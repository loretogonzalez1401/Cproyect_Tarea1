#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"
#include "bib.h"

void get_book(BIB_Cat_Handler_t *bibi){
    BIB_Cat_Handler_t B;
    B = *bibi;
    char pedir[100];
    char out[100];
	int encontrado=0;

    scanf("%[^\n]s",pedir);

	for (int x = 0; x < 10; x++) {
		if(strcmp(B.libro[x],pedir)==0 && B.cpyAvaible[x]  >= 1){

			B.cpyAvaible[x]=B.cpyAvaible[x]-1;
            printf("\n	Prestamo: %s",pedir);
      
			if(B.cpyAvaible[x]>1){
				printf("\n	Usted a pedido el libro %s, ahora quedan %d copias disponibles \n", pedir, B.cpyAvaible[x]);
				encontrado=1;
            }
			else if(B.cpyAvaible[x]==1){
				printf("\n	Usted a pedido el libro %s, ahora queda %d copia disponible \n", pedir, B.cpyAvaible[x]);
				encontrado=1;
			} 
		}
        if(strcmp(B.libro[x],pedir)==0 && B.cpyAvaible[x]  <= 0){
            printf("	No quedan copias de ese libro\n");
			encontrado=1;
        }
	}
	
	if(encontrado==0){
		printf("	No se ha encontrado ese libro, intente otra vez.\n\n");
	}
	
	
	
    *bibi = B;
}

void app_console(BIB_Cat_Handler_t bibi){
    int option;
    char temp;

    printf("\n \n---- BIENVENIDO A LA BIBLIOTECA ---- \n");
    do{
        printf( "\n   Seleccione alguna de las siguientes opciones:");
		printf( "\n   1. Ver libros disponibles, por nombre del libro.");
        printf( "\n   2. Ver libros disponibles, por nombre del autor.");
        printf( "\n   3. Pedir un libro.");
        printf( "\n   4. Salir." );

        do
        {
            printf( "\n   Introduzca su opcion (1-4): ");
            scanf( "%d", &option );
            scanf("%c",&temp);//clear buffer

        } while ( option < 1 || option > 4 );

        switch (option)
        {
        case ONE:
            bib_order_for_book(&bibi);
            show_bib(bibi);
            break;
        case TWO:
            bib_order_for_author(&bibi);
            show_bib(bibi);
            break;
        case THREE:
            printf( "\n   Introduzca el nombre del libro que quiere pedir:");
            get_book(&bibi);
            break;

        }

    }while(option != 4);
}

// --------------------------MAs funciones aquí -----------------//