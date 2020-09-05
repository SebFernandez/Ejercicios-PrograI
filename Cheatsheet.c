#include <stdio.h>
#include <stdlib.h>

int main () {
    int vector [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int *puntero;

    //Asigna la dirección del 1er elemento del vector
    puntero = &vector [0];

    //Printea dirección de memoria de la variable.
    printf ("Dirección de memoria de la variable: %X.\n", &puntero);

    //Printea dirección de memoria del puntero.
    printf ("Dirección de memoria del puntero: %X.\n", puntero);

    //Printea contenido de la dirección de memoria.
    printf ("Contenido del puntero: %d.\n", (*puntero));

    //Printea contenido de la dirección de memoria incrementada.
    printf ("Contenido del puntero: %d.", (*puntero+1));

    puts ("\n\n");
    return 0;
}
