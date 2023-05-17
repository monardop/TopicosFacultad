#include <stdio.h>
#include "fecha.h"

#define FECHA_INICIO 1601

// defino constantes mes
const int dias_bisiesto[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
const int dias_normal[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
// dias gregorianos
const int gregoria_normal[] = {
    0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
    };
const int gregoriano_bisisesto[] = {
    0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335
    };

int es_bisiesto(const int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1: 0;
}

int fecha_valida(const tFecha *f)
{
    if(f->year < FECHA_INICIO){
        printf("Anio invalido.\n");
        return 0;
    }
    if(f->month > 12 || f->month < 1){
        printf("Mes invalido. \n");
        return 0;
    }
    if(f->day < 1){
        return 0;
    }
    if(es_bisiesto(f->year) == 1)
    {
        if(f->day > *(dias_bisiesto + (f->month))){
            printf("Dia invalido.\n");
            return 0;
        }
    }else
    {
        if(f->day > *(dias_normal + (f->month))){
            printf("Dia invalido.\n");
            return 0;
        }
    }

    return 1;
} 

void dias_relativos(tFecha *f)
{
    int diff_year, dd_aaaa_completos, dias_anio; 

    diff_year = f->year - FECHA_INICIO;
    dd_aaaa_completos = diff_year * 365 
                        + diff_year / 4 
                        - diff_year / 100 
                        - diff_year / 400;

    if(es_bisiesto(f->year) == 1)
    {
        dias_anio = *(gregoriano_bisisesto + f->month) + f->day;
    }else
    {
        dias_anio = *(gregoria_normal + f->month) + f->day;
    }

    f->diasRel = dias_anio + dd_aaaa_completos;
}

tFecha ingresar_fecha()
{
    tFecha fecha;

    do
    {
        printf("La fecha debe ser superior al 1600 DC.\n");
        printf("Ingrese una fecha con el formato dd/mm/aaaa:  ");
        scanf("%d/%d/%d", &fecha.day, &fecha.month, &fecha.year);
    } while (fecha_valida(&fecha) == 0);
    dias_relativos(&fecha);
    
    return fecha;
}

tFecha fecha_nueva(int dias_relativos)
{

}