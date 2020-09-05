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
        return (*pDiasMes-1) + 1;
    }

    return (*pDiasMes-1);
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

//TO DO: Resolver días restantes en el año.
void cantDiasRestantes(Fecha *pFecha, Fecha *pFecha2, int *pDiasMes)   {
    //Hard codeada para que cantDiasDelMes funcione.
    Fecha *pFechaAux;

    pFechaAux = &pFecha;

    int diasRestantes = 0;

    if (pFecha->mes == pFecha2->mes && pFecha->anio == pFecha2->anio)   {
        diasRestantes = pFecha2->dia - pFecha->dia;
    }   else    {
        diasRestantes += cantDiasDelMes(pFecha, pDiasMes) - pFecha->dia;

        if (pFechaAux->mes + 1 > 12)  {
            pFechaAux->mes=1;
            pFechaAux->anio +=1;
        }   else    {
            pFechaAux->mes+=1;
        }

        //Hay un problema en el While.
        while (pFechaAux->mes != pFecha2->mes || pFechaAux->anio != pFecha2->anio)    {
            diasRestantes+= cantDiasDelMes(pFechaAux, pDiasMes);

            if (pFechaAux->mes + 1 > 12)  {
                pFechaAux->mes=1;
                pFechaAux->anio +=1;
            }   else    {
                pFechaAux->mes +=1;
            }
        }

        if (pFecha2->dia != 1)    {
            diasRestantes += pFecha2->dia;
        }
    }

    printf("Faltan %d día(s)\n\n", diasRestantes);
}
