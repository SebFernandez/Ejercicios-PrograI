#include <stdio.h>
#include <stdlib.h>
#include "Fecha.h"

int cargarFecha (Fecha *pFecha, int *pDiasMes ) {
    do  {
        fflush(stdin);
        scanf("%d/%d/%d", &pFecha->dia, &pFecha->mes, &pFecha->anio);

    } while (esFechaValida(pFecha, pDiasMes));
}

int esFechaValida (Fecha *pFecha, int *pDiasMes)  {
    if (pFecha->anio > 1600)  {
        if (pFecha->mes >= 1 && pFecha->mes <= 12)  {
            if (pFecha->dia > 0 && pFecha->dia <= cantDiasDelMes(pFecha, pDiasMes)) {
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

int cantDiasDelMes (Fecha *pFecha, int *pDiasMes)  {
    if (pFecha->mes == 2 && pFecha->anio % 4 == 0 && pFecha->anio % 100 != 0 || pFecha->anio % 400 == 0)    {
        return (*(pDiasMes+(pFecha->mes-1))) + 1;
    }

    return (*(pDiasMes+(pFecha->mes-1)));
}

void diaSiguiente (Fecha *pFecha, int *pDiasMes)   {
    int dia = pFecha->dia, mes = pFecha->mes, anio = pFecha->anio;

    if ((pFecha->dia + 1) >= cantDiasDelMes(pFecha, pDiasMes))    {
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

void sumarDias (Fecha *pFecha, Fecha *pFecha2, int *pDiasMes)   {
    int diasAgregados = 0;
    pFecha2->dia = pFecha->dia;
    pFecha2->mes = pFecha->mes;
    pFecha2->anio = pFecha->anio;

    printf ("Días que desea sumarle a la fecha: ");
    scanf("%d", &diasAgregados);


}

void restarDias (Fecha *pFecha, Fecha *pFecha2, int *pDiasMes)   {
    puts ("Nada\n");
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

void cantDiasRestantes(Fecha *pFecha, Fecha *pFecha2, int *pDiasMes)   {
    int diasRestantes = 0;

    if (pFecha->mes == pFecha2->mes && pFecha->anio == pFecha2->anio)   {
        diasRestantes = pFecha2->dia - pFecha->dia;
    }   else    {
        diasRestantes += cantDiasDelMes(pFecha, pDiasMes) - pFecha->dia;

        incrementarPunteroFecha(pFecha);

        while (pFecha->mes != pFecha2->mes || pFecha->anio != pFecha2->anio)  {
            diasRestantes += cantDiasDelMes (pFecha, pDiasMes);

            incrementarPunteroFecha(pFecha);
        }

        diasRestantes += pFecha2->dia;
    }

    printf("Faltan %d día(s).\n\n", diasRestantes);
}
