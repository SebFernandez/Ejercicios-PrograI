#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 20

void getCadena (char *vec)   {
    printf ("Ingresar una frase: ");
    fgets (vec, TAM, stdin);
    printf("%s", vec);
}

void normalizar (char *vec, char *subVec, int *i, int *j) {
    *i = 0;
    *j = 0;

    while (*(vec + (*i)) != NULL && *(vec + (*i)) != '\n')   {
        if (tolower (*(vec + (*i))) >= 'a' && tolower (*(vec + (*i))) <= 'z')   {
            *(subVec + (*j)) = tolower (*(vec + (*i)));
            (*j)++;
        }

        (*i)++;
    }

    *subVec = toupper (*subVec);
    *(subVec + (*j)) = '\0';
}
