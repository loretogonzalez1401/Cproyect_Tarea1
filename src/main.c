#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"
#include "bib.h"

int main()
{

	BIB_Cat_Handler_t Bib;

	add_to_book(&Bib,"Odisea","Homero",POS_ORIGIN,0);
	add_to_book(&Bib,"Dracula","Bram Stoker",POS_INCREASE,5);
	add_to_book(&Bib,"La metamorfosis","Franz Kafka",POS_INCREASE,2);
	add_to_book(&Bib,"Las aventuras de Tom Sawyer","Mark Twain",POS_INCREASE,4);
	add_to_book(&Bib,"La vuelta al mundo en 80 dias","Julio Verne",POS_INCREASE,5);
	add_to_book(&Bib,"Cronicas marcianas","Ray Bradbury",POS_INCREASE,5);
	add_to_book(&Bib,"Fundacion","Isaac Asimov",POS_INCREASE,1);
	add_to_book(&Bib,"La casa de los espiritus","Isabel Allende",POS_INCREASE,6);
	add_to_book(&Bib,"Somos polvo de estrellas","Jose Maza",POS_INCREASE,2);
	add_to_book(&Bib,"Sub Terra","Baldomero Lillo",POS_INCREASE,0);


	// printf("author : %s \n",Bib.autor[0]);
	// printf("author : %s \n",Bib.autor[1]);
	// printf("cpynum = %d\n",Bib.cpyAvaible[1]);

	// show_bib(Bib);
	//printf("Obra: %s,\t Autor: %s \t N copias: %d\n",Bib.libro[9],Bib.autor[9],Bib.cpyAvaible[9]);
	// bib_order_for_book(&Bib);
	// printf("----Otro orden------\n");
	// show_bib(Bib);

	//app console
	app_console(Bib);

	// --------------------------MAs funciones aquí -----------------//


	return (0);
}