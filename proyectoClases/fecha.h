#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int day, month, year;
    int diasRel;
}tFecha;

tFecha ingresar_fecha();
int fecha_valida(const tFecha*);
int restar_fechas(const tFecha, const tFecha);
tFecha sumar_dias(int dias, const tFecha f);
void imprimir_fecha(const tFecha *f);

#endif // FECHA_H_INCLUDED
