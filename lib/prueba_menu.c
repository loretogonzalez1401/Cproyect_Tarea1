//----- Loreto Gonzalez -------//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	//Declaracion de variables
	int i,j;
	char aux[100];
	char pedir[100]="";
	char libro[10][100];

	strncpy(libro[0], "Odisea",100);
	strncpy(libro[1], "Dracula",100);
	strncpy(libro[2], "La metamorfosis",100);
	strncpy(libro[3], "Las aventuras de Tom Sawyer",100);
	strncpy(libro[4], "La vuelta al mundo en 80 dias",100);
	strncpy(libro[5], "Cronicas marcianas",100);
	strncpy(libro[6], "Fundacion",100);
	strncpy(libro[7], "La casa de los espiritus",100);
	strncpy(libro[8], "Somos polvo de estrellas",100);
	strncpy(libro[9], "Sub Terra",100);
	
	char autor[10][100];
	strncpy(autor[0], "Homero",100);
	strncpy(autor[1], "Bram Stoker",100);
	strncpy(autor[2], "Franz Kafka",100);
	strncpy(autor[3], "Mark Twain",100);
	strncpy(autor[4], "Julio Verne",100);
	strncpy(autor[5], "Ray Bradbury",100);
	strncpy(autor[6], "Isaac Asimov",100);
	strncpy(autor[7], "Isabel Allende",100);
	strncpy(autor[8], "Jose Maza",100);
	strncpy(autor[9], "Baldomero Lillo",100);
	
	int copias[10]={2, 3, 4, 5, 9, 19, 30, 13, 4, 1}; 
	int aux2=0;
	
	
	//Ciclo que ordena los nombres por orden alfabetico (se considera de menor a mayor)
	//Debe ser una funcion para que reciba los nombres de los libros o de los autores
	for(i=1;i<11;i++){ 
  		for(j=0;j<10-i;j++){ 
    		 if(strcmp(libro[j],libro[j+1])>0) //compara el nombre actual con el siguiente
        	{								   //si el actual es "mayor" los intercambia
        		strcpy(aux,libro[j]); //Guardamos el nombre actual en la variable Auxiliar
        		strcpy(libro[j],libro[j+1]); //El nombre siguiente pasa a ser el actual
        		strcpy(libro[j+1],aux); //Pasamos el Aux al siguiente
				
				//Se cambian los nombres de los autores con el mismo orden
				strcpy(aux,autor[j]); //Guardamos el nombre actual en la variable Auxiliar
        		strcpy(autor[j],autor[j+1]); //El nombre siguiente pasa a ser el actual
        		strcpy(autor[j+1],aux); //Pasamos el Aux al siguiente
				
				//Se cambian las copias de los libros con el mismo orden
				aux2=copias[j]; //Guardamos el nombre actual en la variable Auxiliar
        		copias[j]=copias[j+1]; //El nombre siguiente pasa a ser el actual
        		copias[j+1]=aux2; //Pasamos el Aux al siguiente
    	    }
		}
	}
	
	
	
	
	printf("\n \n---- LIBROS DISPONIBLES ---- \n");
	//Mostramos los nombres ordenados
	for(i=0;i<10;i++){
		printf("%-30s || %-20s || %-5d \n",libro[i], autor[i], copias[i]);
	}
	
	
	
	int n, opcion;
	
	
	printf("\n \n---- BIENVENIDO A LA BIBLIOTECA ---- \n");

    do
    {
        printf( "\n   Seleccione alguna de las siguientes opciones:");
		printf( "\n   1. Ver libros disponibles, por nombre del libro.");
        printf( "\n   2. Ver libros disponibles, por nombre del autor.");
        printf( "\n   3. Pedir un libro.");
        printf( "\n   4. Salir." );

        /* Filtramos la opción elegida por el usuario */
        do
        {
            printf( "\n   Introduzca su opci%cn (1-4): ", 162 );
            scanf( "%d", &opcion );

        } while ( opcion < 1 || opcion > 4 );
        /* La opción sólo puede ser 1, 2, 3 ó 4 */

        switch ( opcion )
        {
            case 1: printf("\n \n---- LIBROS DISPONIBLES ---- \n");
					//Mostramos los nombres ordenados
					for(i=0;i<10;i++){
						printf("%-30s || %-20s || %-5d \n",libro[i], autor[i], copias[i]);
					}
                    break;

            case 2: printf("\n \n---- LIBROS DISPONIBLES ---- \n");
					//Mostramos los nombres ordenados
					for(i=0;i<10;i++){
						printf("%-20s || %-30s || %-5d \n",autor[i], libro[i], copias[i]);
					}
					break;

            case 3: printf( "\n   Introduzca el nombre del libro que quiere pedir: ");
					scanf( "%s", &pedir );
    
	
					for (int x = 0; x < 10; x++) {
						if(strcmp(libro[x],pedir)==0){
							copias[x]=copias[x]-1;
							printf("\n Usted a pedido el libro %s, ahora quedan %d copias disponibles \n", pedir, copias[x]);
						}
					}
         }

    } while ( opcion != 4 );
	
	
	
	
	
	
	return 0;
}