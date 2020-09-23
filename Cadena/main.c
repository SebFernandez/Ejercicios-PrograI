#include <stdio.h>
#include <stdlib.h>
#include "Cadena.h"
#define TAM 20

int main () {
    char vector [TAM], subVector [TAM];

    //Índice para todos.
    int indiceI = 0, indiceJ = 0;

    //Puntero índice.
    int *i = &indiceI, *j = &indiceJ;

    getCadena (vector);

    normalizar(vector, subVector, i, j);
    printf("\n\n%s\n", subVector);

    printf("\nGoodbye world!\n");

    return 0;
}
