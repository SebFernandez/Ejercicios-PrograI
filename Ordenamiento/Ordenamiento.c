#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void cargarVector (int *vectorNros, int *vectorBurbujeo, int *vectorSeleccion, int *vectorInsercion, int *i) {
    int nroRandom;
    srand(time(0));

    for (*i; *i<10; (*i)++)   {
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
        if (*i != 9)    {
            printf ("%d, ", *(vectorNros + (*i)));
        }   else    {
            printf ("%d}", *(vectorNros + (*i)));
        }
    }
}

void burbujeo (int *vectorBurbujeo, int *i, int *j) {
    int tmp;

    for (*i = 0; *i<TAM-1; (*i)++)   {
        for (*j = 1; *j<TAM-(*i); (*j)++)   {
            if (*(vectorBurbujeo + (*i)) > *(vectorBurbujeo + (*i) + (*j))) {
                tmp = *(vectorBurbujeo + (*i));
                *(vectorBurbujeo + (*i)) = *(vectorBurbujeo + (*i) + (*j));
                *(vectorBurbujeo + (*i) + (*j)) = tmp;
            }
        }
    }
}
