#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct  {
    int dia;
    int mes;
    int anio;
} Fecha;

int esFechaValida (Fecha fecha);
int esBisiesto (int mes, int anio) ;
void diaSiguiente(Fecha fecha);
void cantDiasRestantes(Fecha fecha, Fecha fecha2);

#endif // FECHA_H_INCLUDED
