#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct  {
    int dia;
    int mes;
    int anio;
} Fecha;

int esFechaValida (Fecha *pFecha, int *vectorDiasMes);
int esBisiesto (Fecha *pFecha);
void diaSiguiente (Fecha *pFecha, int *vectorDiasMes);
void sumarDias (Fecha *pFecha, Fecha *pFecha2, int *vectorDiasMes);
void restarDias (Fecha *pFecha, Fecha *pFecha2, int *vectorDiasMes);
int cantDiasDelMes (Fecha *pFecha, int *vectorDiasMes);
void diaDeSemana (Fecha *pFecha,Fecha *pFecha2, char **dias);
void incrementarPunteroFecha (Fecha *pFecha);
void decrementarPunteroFecha (Fecha *pFecha, int *vectorDiasMes);
void cantDiasRestantes(Fecha *pFecha, Fecha *pFecha2, int *vectorDiasMes);

#endif // FECHA_H_INCLUDED
