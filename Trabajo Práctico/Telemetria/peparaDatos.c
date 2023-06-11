#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#include "manejoDatos.h"

void calcularFecha(int segundos, struct tm *fecha){
    struct tm fechaReferencial = {0};
    fechaReferencial.tm_year = 80;
    fechaReferencial.tm_mon = 5;
    fechaReferencial.tm_mday = 1;

    time_t tiempoReferencial = mktime(&fechaReferencial);
    time_t tiempoFinal = tiempoReferencial + segundos;

    struct tm *fechaResultante = gmtime(&tiempoFinal);
    *fecha = *fechaResultante;
}

void crearFecha(uint8_t* bytes, char* mensaje, uint8_t boolEndian){
    struct tm fechaResultante;
    
    int segundos = (int)((*bytes) << 24) | (int)(*(bytes +1) << 16) | (int)(*(bytes + 2) << 8) | (int)*(bytes + 3);
    if(boolEndian == 0){
        segundos = ((segundos >> 24) & 0xFF) | ((segundos >> 8) & 0xFF00) | ((segundos << 8) & 0xFF0000) | ((segundos << 24) & 0xFF000000);
    }

    calcularFecha(segundos, &fechaResultante);

    sprintf(mensaje, "%02d/%02d/%04d %02d:%02d:%02d\n", fechaResultante.tm_mday, fechaResultante.tm_mon + 1, fechaResultante.tm_year + 1900, fechaResultante.tm_hour, fechaResultante.tm_min, fechaResultante.tm_sec);
    *(mensaje + 33) = '\0'; // la cadena de fecha ocupa 32 char.
}

void crearNumero(uint8_t* bytes, char* mensaje, uint8_t boolEndian){
    uint16_t numero = (uint16_t)((*bytes) << 8) | (uint16_t)*(bytes+1) ;
    float numeroFinal;

    if(boolEndian == 0){
        numero = ((numero & 0x00FF) << 8) | ((numero & 0xFF00) >> 8);
    }
    numeroFinal = (numero* 0.01873128) - 38.682956;
    
    sprintf(mensaje, "%.3f\n",numeroFinal);
    *(mensaje + 7) = '\0';
}
