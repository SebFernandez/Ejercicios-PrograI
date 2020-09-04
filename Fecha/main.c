#include <stdio.h>
#include <stdlib.h>
#include "Fecha.h"

int main()  {
    static int vectorDiasMes [12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
    Fecha fecha, fecha2;

    do  {
        printf("Se determinará si la fecha ingresada es un año bisiesto.\nIngresar fecha (DD/MM/YYYY): ");
        fflush(stdin);
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    } while (esFechaValida(fecha));

    printf("\n\t- Fecha ingresada %d/%d/%d.\n\n", fecha.dia, fecha.mes, fecha.anio);
    if (esBisiesto(fecha.mes, fecha.anio) == 29){
        printf("\t- El año %d es bisiesto!\n\n", fecha.anio);
    }
    diaSiguiente(fecha);

     do  {
        printf("Ingrese una 2da fecha para determinar la cantidad de días restantes (DD/MM/YYYY): ");
        fflush(stdin);
        scanf("%d/%d/%d", &fecha2.dia, &fecha2.mes, &fecha2.anio);
     } while (esFechaValida(fecha2));

    cantDiasRestantes (fecha, fecha2);

    puts ("Chau chau \n");

    return 0;
}
