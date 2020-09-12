#include <stdio.h>
#include <stdlib.h>
#include "Fecha.h"

int main()  {
    //Variables y vector.
    static int vectorDiasMes [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static char *dias [7] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};
    Fecha fecha, fecha2;
    int var = 0;

    //Punteros.
    int *pDiasMes;
    Fecha *pFecha, *pFecha2;

    //Inicializo punteros.
    pDiasMes = &vectorDiasMes[0];
    pFecha = &fecha;
    pFecha2 = &fecha2;

    printf("Se determinará si la fecha ingresada es un año bisiesto.\nIngresar fecha (DD/MM/YYYY): ");
    cargarFecha(pFecha, pDiasMes);

    printf("\n\t- Fecha ingresada %d/%d/%d.\n\n", pFecha->dia, pFecha->mes, pFecha->anio);

    if (esBisiesto(pFecha)){
        printf("\t- El año %d es bisiesto!\n\n", pFecha->anio);
    }   else    {
        printf("\t- El año %d no es bisiesto. :(\n\n", pFecha->anio);
    }

    diaDeSemana(pFecha, pFecha2, pDiasMes, dias);
    diaSiguiente(pFecha, pDiasMes);

    //Fecha2 se utiliza como auxiliar.
    sumarDias (pFecha, pFecha2, pDiasMes);
    restarDias (pFecha, pFecha2,pDiasMes);

    printf("Se deberá ingresar una segunda fecha,\nAsí se calculan los días que hay entre las dos fechas.\nIngresar fecha (DD/MM/YYYY): ");
    cargarFecha(pFecha2, pDiasMes);

    //Va ultima esta función.
    cantDiasRestantes (pFecha, pFecha2, pDiasMes);

    puts ("Chau chau \n");

    return 0;
}
