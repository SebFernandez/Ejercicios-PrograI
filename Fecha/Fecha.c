#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fecha.h"

int cargarFecha (Fecha *pFecha, int *vectorDiasMes ) {
    do  {
        fflush(stdin);
        scanf("%d/%d/%d", &pFecha->dia, &pFecha->mes, &pFecha->anio);

    } while (esFechaValida(pFecha, vectorDiasMes));
}

int esFechaValida (Fecha *pFecha, int *vectorDiasMes)  {
    if (pFecha->anio > 1600)  {
        if (pFecha->mes >= 1 && pFecha->mes <= 12)  {
            if (pFecha->dia > 0 && pFecha->dia <= cantDiasDelMes(pFecha, vectorDiasMes)) {
                return 0;
            }
        }
    }

    return 1;
}

int esBisiesto (Fecha *pFecha)    {

    if (pFecha->anio % 4 == 0 && pFecha->anio % 100 != 0 || pFecha->anio % 400 == 0)    {
        return 1;
    }

    return 0;
}

int cantDiasDelMes (Fecha *pFecha, int *VectorDiasMes)  {
    if (pFecha->mes == 2 && pFecha->anio % 4 == 0 && pFecha->anio % 100 != 0 || pFecha->anio % 400 == 0)    {
        return (*(VectorDiasMes+(pFecha->mes-1))) + 1;
    }

    return (*(VectorDiasMes+(pFecha->mes-1)));
}

void diaSiguiente (Fecha *pFecha, int *vectorDiasMes)   {
    int dia = pFecha->dia, mes = pFecha->mes, anio = pFecha->anio;

    if ((pFecha->dia + 1) >= cantDiasDelMes(pFecha, vectorDiasMes))    {
        if ((pFecha->mes + 1) > 12)   {
            dia = 1;
            mes = 1;
            anio = pFecha->anio + 1;
        }   else    {
            dia = 1;
            mes = pFecha->mes + 1;
        }
    }   else    {
        dia = pFecha->dia + 1;
    }

    printf("\t- Fecha siguiente %d/%d/%d.\n\n", dia, mes, anio);
}

void sumarDias (Fecha *pFecha, Fecha *pFecha2, int *vectorDiasMes)   {
    int diasAgregados = 0;
    pFecha2->dia = pFecha->dia;
    pFecha2->mes = pFecha->mes;
    pFecha2->anio = pFecha->anio;

    printf ("Días que desea sumarle a la fecha: ");
    scanf("%d", &diasAgregados);

    while (diasAgregados > 0)   {
        if (pFecha2->dia + diasAgregados > cantDiasDelMes(pFecha2, vectorDiasMes)) {
            diasAgregados -= (cantDiasDelMes(pFecha2, vectorDiasMes) - pFecha2->dia);
            incrementarPunteroFecha(pFecha2);

            /* Se decrementa diasAgregados porque la función incrementarPunteroFecha pone a Pfecha->dia en 1,
               técnicamente ya está incrementando por uno la función misma,
               si no se decrementa dias agregados voy a tener un día de sobra. */
            diasAgregados--;

        }   else    {
            pFecha2->dia += diasAgregados;
            diasAgregados = 0;
        }
    }

    printf("Fecha actual más los días agregados resultan ser la fecha: %d/%d/%d.\n\n", pFecha2->dia, pFecha2->mes, pFecha2->anio);
}

void restarDias (Fecha *pFecha, Fecha *pFecha2, int *vectorDiasMes)   {
    int diasRestados = 0;
    pFecha2->dia = pFecha->dia;
    pFecha2->mes = pFecha->mes;
    pFecha2->anio = pFecha->anio;

    printf ("Días que desea restarle a la fecha: ");
    scanf("%d", &diasRestados);

    while (diasRestados > 0)    {
        if (pFecha2->dia - diasRestados <= 0)    {
            diasRestados -= pFecha2->dia;
            decrementarPunteroFecha(pFecha2, vectorDiasMes);
        }   else    {
            pFecha2->dia -= diasRestados;
            diasRestados = 0;
        }
    }

    printf("Fecha actual menos los días restados resultan ser la fecha: %d/%d/%d.\n\n", pFecha2->dia, pFecha2->mes, pFecha2->anio);
}

void decrementarPunteroFecha (Fecha *pFecha, int *vectorDiasMes)    {
    if ((pFecha->mes - 1) < 0)  {
        pFecha->dia = 31;
        pFecha->mes = 12;
        pFecha->anio -= 1;
    }   else    {
        pFecha->mes -= 1;
        pFecha->dia = cantDiasDelMes(pFecha, vectorDiasMes);
    }

}

void incrementarPunteroFecha (Fecha *pFecha)    {
    if ((pFecha->mes + 1) > 12)   {
        pFecha->dia = 1;
        pFecha->mes = 1;
        pFecha->anio += 1;
    }   else    {
        pFecha->dia = 1;
        pFecha->mes += 1;
    }
}

void cantDiasRestantes(Fecha *pFecha, Fecha *pFecha2, int *vectorDiasMes)   {
    int diasRestantes = 0;

    if (pFecha->mes == pFecha2->mes && pFecha->anio == pFecha2->anio)   {
        diasRestantes = pFecha2->dia - pFecha->dia;
    }   else    {
        diasRestantes += cantDiasDelMes(pFecha, vectorDiasMes) - pFecha->dia;

        incrementarPunteroFecha(pFecha);

        while (pFecha->mes != pFecha2->mes || pFecha->anio != pFecha2->anio)  {
            diasRestantes += cantDiasDelMes (pFecha, vectorDiasMes);

            incrementarPunteroFecha(pFecha);
        }

        diasRestantes += pFecha2->dia;
    }

    printf("Faltan %d día(s).\n\n", diasRestantes);
}

void diaDeSemana (Fecha *pFecha, Fecha *pFecha2, char **dias) {
    //Magia china encontrada en internet -> https://bit.ly/33qrxl1.
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int indice = 0;

    pFecha2->dia = pFecha->dia;
    pFecha2->mes = pFecha->mes;
    pFecha2->anio = pFecha->anio;

    pFecha2->anio -= pFecha2->mes < 3;

    indice = (pFecha2->anio + (pFecha2->anio/4) - pFecha2->anio*3/400 - pFecha2->anio/4000 + t[pFecha2->mes-1] + pFecha2->dia) % 7;

    printf ("\t- La fecha ingresada es el día %s.\n\n", dias[indice]);
}
