#include <stdio.h>
#include <stdlib.h>

void funcionEjemplo (int *punteroFuncion);

int main () {
    static int vector [10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    int indice = 0;

    int *puntero, *i;

    //Asigna la dirección del 1er elemento del vector
    puntero = &vector [0];

    //Printea dirección de memoria de la variable.
    printf ("Dirección de memoria de la variable: %X.\n", &puntero);

    //Printea dirección de memoria del puntero.
    printf ("Dirección de memoria del puntero: %X.\n", puntero);

    //Printea contenido de la dirección de memoria.
    printf ("Contenido del puntero: %d.\n", (*puntero));

    //Printea contenido de la dirección de memoria incrementada.
    printf ("Contenido del puntero: %d.\n\n", (*puntero+1));

    //Pasar punteros como parámetro.
    funcionEjemplo(puntero);
    printf ("Y también el contenido del vector: %d\n", vector [0]);

    incrementarContenidoPtero(i);

    puts ("\n-----------------------------------------------------\n");
    return 0;
}

void funcionEjemplo (int *punteroFuncion)   {
    int i;

    for (i = 0; i < 10; i++)    {
        printf ("Índice %d printeando el contenido del vector: %d.\n", i, (*(punteroFuncion+i)));
    }

    printf ("\nIngresá algo: ");

    //Importante!!
    scanf ("%d", &(*punteroFuncion));
    printf ("Modificaste el contenido del puntero: %d.\n", (*punteroFuncion));

    return;
}

void incrementarContenidoPtero (int *i) {

    while (*i != -1)    {
        printf("\nNúmero: ");
        fflush(stdin);
        scanf("%d", &(*i));
        printf("\t%d\n", *i);
    }

    *i = 0;
    printf("\n%d\n", *i);

    for (*i; *i<5; (*i)++)    {
        printf("\nValor: %d", *i);
    }

    puts("\n");
}