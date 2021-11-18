//-----Pablo Jeldes ------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bib.h"




bool add_to_book(BIB_Cat_Handler_t *Bib,char *libro, char *autor, int positionInit, unsigned int cant){
    static int indice = 0;
    if(positionInit == POS_ORIGIN){
        //save the last position
        //POS_SAVE = indice;
        indice = 0;
        //POS_SAVE = indice;
    }
    if(positionInit == POS_LAST){
        indice = 9;
    }
    BIB_Cat_Handler_t miBib;

    miBib.cpyAvaible[indice] = cant;
    // miBib.autor[indice][TAM_STRING] = autor;
    // miBib.libro[indice][TAM_STRING] = libro;
    strcpy(&miBib.autor[indice],autor);
    strcpy(&miBib.libro[indice],libro);

    indice++;

    *Bib = miBib;
    return BIB_OK;
}

void show_bib(BIB_Cat_Handler_t miBib){
    //BIB_Cat_Handler_t miBib;
    for(int i = 0; i<BIB_CAT_TAM;i++){
        //printf("Obra: %s,\t Autor: %s \t N copias: %d\n",miBib.libro[i],miBib.autor[i],miBib.cpyAvaible[i]);
        printf("%-30s || %-20s || %-5d \n",miBib.libro[i],miBib.autor[i],miBib.cpyAvaible[i]);
    }
}


bool bib_order_for_book(BIB_Cat_Handler_t *bibi){
    BIB_Cat_Handler_t B;
    B = *bibi;

    char aux[100] = "";
    int aux2;
    for(int i = 1; i <= BIB_CAT_TAM;i++){
        for(int k = 0; k < BIB_CAT_TAM-1;k++){
            if(strcmp(B.libro[k],B.libro[k+1]) >0 ){
                strcpy(aux,B.libro[k]);
                strcpy(B.libro[k],B.libro[k+1]);
                strcpy(B.libro[k+1],aux);

                strcpy(aux,B.autor[k]);
                strcpy(B.autor[k],B.autor[k+1]);
                strcpy(B.autor[k+1],aux);
                
                aux2=B.cpyAvaible[k]; 
        		B.cpyAvaible[k]=B.cpyAvaible[k+1]; 
        		B.cpyAvaible[k+1]=aux2; 
            }
        }
    }
    *bibi = B;
    return BIB_OK;
}


bool bib_order_for_author(BIB_Cat_Handler_t *bibi){
    BIB_Cat_Handler_t B;
    B = *bibi;

    char aux[100] = "";
    int aux2;
    for(int i = 1; i <= BIB_CAT_TAM;i++){
        for(int k = 0; k < BIB_CAT_TAM-1;k++){
            if(strcmp(B.autor[k],B.autor[k+1]) >0 ){
                strcpy(aux,B.libro[k]);
                strcpy(B.libro[k],B.libro[k+1]);
                strcpy(B.libro[k+1],aux);

                strcpy(aux,B.autor[k]);
                strcpy(B.autor[k],B.autor[k+1]);
                strcpy(B.autor[k+1],aux);
                
                aux2=B.cpyAvaible[k]; 
        		B.cpyAvaible[k]=B.cpyAvaible[k+1]; 
        		B.cpyAvaible[k+1]=aux2; 
            }
        }
    }
    *bibi = B;
    return BIB_OK;
}

// --------------------------MAs funciones aquí -----------------//