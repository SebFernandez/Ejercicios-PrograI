#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct  {
    int dia;
    int mes;
    int anio;
} Fecha;

int esFechaValida (Fecha *pFecha, int *pDiasMes);
int esBisiesto (Fecha *pFecha);
void diaSiguiente (Fecha *pFecha, int *pDiasMes);
int cantDiasDelMes (Fecha *pFecha, int *pDiasMes);
void cantDiasRestantes(Fecha *pFecha, Fecha *pFecha2, int *pDiasMes);

#endif // FECHA_H_INCLUDED
