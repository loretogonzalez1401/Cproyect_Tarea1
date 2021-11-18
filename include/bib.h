// ------- Pablo Jeldes ------//

#include <stdbool.h>

#ifndef _BIB_H
#define _BIB_H

static int POS_SAVE;

#define BIB_CAT_TAM         10
#define TAM_STRING          100
#define POS_ORIGIN          0x00
#define POS_INCREASE        0X01
#define POS_LAST            0x02

//categorias
#define LITERARURA          0X00
#define CIENCIAS            0X01

#define BIB_OK             true

//TYPE DEF

/** Name: Manejador de estanterias.
 * @brief BIB_Cat_Handler.
 * Esta diseñado para crear estanterias de una biblioteca, cada estanteria tiene como limite maximo de 10 libros. Los nombres y
 * los autores tienen un limite de 100 caracteres para almacenar el nombre. El numero de copias de cada libro es coincidente 
 * con el indice del vector
 * */
typedef struct BIB_Cat_Handler{
    char libro[BIB_CAT_TAM][TAM_STRING];
    char autor[BIB_CAT_TAM][TAM_STRING];
    unsigned int cpyAvaible[BIB_CAT_TAM];
}BIB_Cat_Handler_t;

/** @brief Function: bool add_to_book
 * 
 * es usada para asignar libros a las estanterias, creadas por el manejador BIB_Cat_Handler. Recive parametros:
 * @param BIB_Cat_Handler_t Manejador de estanterias, guarda el libro en la estanteria.
 * @param libro Puntero, recibe la cadena de texto que es usada para nombrar al libro.
 * @param autor Puntero, recibe la cadena de texto que es usada para nombrar al autor.
 * @param positionInit Entero, recibe un comando con la posicion que ocupa el libro en la estanteria, esta entrada puede ser @code POS_ORIGIN y POS_INCREASE @endcode.
 * @param cant Entero sin signo, es la cantidad de copias del libro en cuestion.
 * */
bool add_to_book(BIB_Cat_Handler_t *Bib,char *libro, char *autor, int positionInit, unsigned int cant);


/** @brief  show_bib.
 * 
 * Esta funcion muestra en consola la biblioteca que recibe como parametro.
 * 
 * @param Bib Manejador de estanterias, imprime esta estanteria.
 * */
void show_bib(BIB_Cat_Handler_t Bib);


/** @brief bib_order_for_book.
 * 
 * Es usada para ordenar por orden alfabetico los libros en la estanteria que recibe como parametro.
 * @param miBib manejador de estanterias, ordena esta estanteria alfabeticamente por libror.
 * */
bool bib_order_for_book(BIB_Cat_Handler_t *miBib);


/** @brief bib_order_for_author.
 * 
 * Es usada para ordenar por orden alfabetico los nombre de autores en la estanteria que recibe como parametro.
 * @param miBib manejador de estanterias, ordena esta estanteria alfabeticamente por autor.
 * */
bool bib_order_for_author(BIB_Cat_Handler_t *bibi);


// --------------------------MAs funciones aquí -----------------//


#endif