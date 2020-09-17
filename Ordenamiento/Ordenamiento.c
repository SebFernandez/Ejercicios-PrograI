#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100

void cargarVector (int *vectorNros, int *vectorBurbujeo, int *vectorSeleccion, int *vectorInsercion, int *i) {
    int nroRandom;
    srand(time(0));

    for (*i; *i<TAM; (*i)++)   {
        nroRandom = (rand () % 100);

        //Carga al vector original con números entre 0 y 100.
        *(vectorNros + (*i)) = nroRandom;

        //Carga los vectores a trabajar.
        *(vectorBurbujeo + (*i)) = nroRandom;
        *(vectorSeleccion + (*i)) = nroRandom;
        *(vectorInsercion + (*i)) = nroRandom;
    }
}

void mostrarVector (int *vectorNros, int *i) {
    printf(" {");
    for (*i = 0; *i<TAM; (*i)++)   {
        if (*i != TAM-1)    {
            printf ("%d, ", *(vectorNros + (*i)));
        }   else    {
            printf ("%d}", *(vectorNros + (*i)));
        }
    }
}

//Burbujeo: Va a iterar sobre cada posición analizando si es mayor o menor.
void burbujeo (int *vectorBurbujeo, int *i, int *j) {
    int tmp;

    for (*i = 0; *i<TAM-1; (*i)++)   {
        for (*j = 1; *j < TAM-(*i); (*j)++)   {
            if (*(vectorBurbujeo + (*i)) > *(vectorBurbujeo + (*i) + (*j))) {
                tmp = *(vectorBurbujeo + (*i));
                *(vectorBurbujeo + (*i)) = *(vectorBurbujeo + (*i) + (*j));
                *(vectorBurbujeo + (*i) + (*j)) = tmp;
            }
        }
    }
}

//Selección: Va a iterar buscando el menor de todo el vector y lo va a ir ordenando.
void seleccion (int *vectorSeleccion, int *i, int *j)   {
    //k es un índice auxiliar para guardar en qué posición hubo un menor.
    int k = 0, tmp = 0;

    for (*i = 0; *i< TAM-1; (*i)++)  {
        tmp = *(vectorSeleccion + (*i));
        for (*j = 1; *j < TAM-(*i); (*j)++)  {
            if (tmp > *(vectorSeleccion + (*i) + (*j)))   {
                k = (*j);
                tmp = *(vectorSeleccion + (*i) + (*j));
            }
        }

        //Si es distinto quiere decir que el if del for J modificó encontró uno menor.
        if (tmp != *(vectorSeleccion + (*i)))   {
            *(vectorSeleccion + (*i) + k) = *(vectorSeleccion + (*i));
            *(vectorSeleccion + (*i)) = tmp;
        }
    }
}

//Inserción: A medida que itera va insertandolos a la izquierda.
void insercion (int *vectorInsercion, int *i, int *j)   {
    int tmp = 0;

    for (*i = 0; *i < TAM-1; (*i)++)  {
        if (*(vectorInsercion + (*i)) > *(vectorInsercion + (*i) + 1))   {

            /*
            Si la condición del 1er if se cumple, se vuelve a hacer la iteración pero al revés,
            de esta manera, voy insertando donde vaya mejor el elemento.
            */

            for (*j = *i; *j > -1; (*j)--)   {
                if (*(vectorInsercion + (*j)) > *(vectorInsercion + (*j) + 1))  {
                    tmp = *(vectorInsercion + (*j) + 1);
                    *(vectorInsercion + (*j) + 1) = *(vectorInsercion + (*j));
                    *(vectorInsercion + (*j)) = tmp;
                }
            }
        }
    }
}
