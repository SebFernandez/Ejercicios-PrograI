#include "Fecha.h"

int esFechaValida (Fecha fecha)  {
    if (fecha.anio > 1600)  {
        if (fecha.mes >= 1 && fecha.mes <= 12)  {
            if (fecha.dia > 0 && fecha.dia <= esBisiesto (fecha.mes, fecha.anio)) {
                return 0;
            }
        }
    }

    return 1;
}

int esBisiesto (int mes, int anio)    {
    static int vectorDiasMes [12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};

    if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)    {
        return vectorDiasMes [mes-1] + 1;
    }

    return vectorDiasMes [mes-1];
}

void diaSiguiente (Fecha fecha)   {
    int dia = fecha.dia, mes = fecha.mes, anio = fecha.anio;

    if ((fecha.dia + 1) >= esBisiesto(fecha.mes, fecha.anio))    {
        if ((fecha.mes + 1) > 12)   {
            dia = 1;
            mes = 1;
            anio = fecha.anio + 1;
        }   else    {
            dia = 1;
            mes = fecha.mes + 1;
        }
    }   else    {
        dia = fecha.dia + 1;
    }

    printf("\t- Fecha siguiente %d/%d/%d.\n\n", dia, mes, anio);
}

//TO DO: Resolver días restantes en el año.
void cantDiasRestantes(Fecha fecha, Fecha fecha2)   {
    int mes1 = fecha.mes, anio1 = fecha.anio;
    int diasRestantes = 0;

    if (fecha.mes == fecha2.mes && fecha.anio == fecha2.anio)   {
        diasRestantes = fecha2.dia - fecha.dia;
    }   else    {

        diasRestantes += esBisiesto(fecha.mes, fecha.anio) - fecha.dia;

        if (mes1 + 1 > 12)  {
            mes1=1;
            anio1 +=1;
        }   else    {
            mes1+=1;
        }

        while (mes1 != fecha2.mes || anio1 != fecha2.anio)    {
            diasRestantes+= esBisiesto(mes1, anio1);

            if (mes1 + 1 > 12)  {
                mes1=1;
                anio1 +=1;
            }   else    {
                mes1+=1;
            }
        }

        if (fecha2.dia != 1)    {
            diasRestantes += fecha2.dia;
        }
    }

    printf("Faltan %d día(s)\n\n", diasRestantes);
}
