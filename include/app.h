#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

#ifndef _APP_H
#define _APP_H

/** @brief Nuemeracion con opciones para la APP console.
 * compuesta por ONE;TWO;THREE;FOUR.
 * */
enum OPTION{
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4
};


/** @brief Aplicacion que eseña en consola, una biblioteca virtual usando la libreria bib.h
 * @param bibi Manejador de estanterias, se usa para mostrar dicha estanteria por consola.
 * */
void app_console(BIB_Cat_Handler_t bibi);

/** @brief Funcion que pide un libro de una biblioteca, una vez pedido se descuenta a las copias existentes.
 * @param bibi Manejador de estanterias, se usa para pedir el libro de dicha estanteria.
 * */
void get_book(BIB_Cat_Handler_t *bibi);

// --------------------------MAs funciones aquí -----------------//

#endif