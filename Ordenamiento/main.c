#include <stdio.h>
#include <stdlib.h>
#include "Ordenamiento.h"
#define TAM 100

//TO-DO: Hacer inserción.
int main() {
    //Vectores.
    int vectorNros [TAM], vectorBurbujeo [TAM], vectorSeleccion [TAM], vectorInsercion [TAM];

    //Índices para todos.
    int indiceI = 0, indiceJ = 0;

    //Punteros índice. Ja.
    int *i, *j;

    //Inicializo puntero índice. Porque puedo y quiero.
    i = &indiceI;
    j = &indiceJ;

    cargarVector (vectorNros, vectorBurbujeo, vectorSeleccion, vectorInsercion, i);
    printf ("Vector original:\t\t");
    mostrarVector(vectorNros, i);

    burbujeo(vectorBurbujeo, i, j);
    printf ("\nVector burbujeo ordenado:\t");
    mostrarVector(vectorBurbujeo, i);

    seleccion (vectorSeleccion, i, j);
    printf("\nVector selección ordenado:\t");
    mostrarVector(vectorSeleccion, i);

    insercion (vectorInsercion, i, j);
    printf("\nVector inserción ordenado:\t");
    mostrarVector(vectorInsercion, i);

    printf("\n\nGoodbye world!\n");
    return 0;
}
