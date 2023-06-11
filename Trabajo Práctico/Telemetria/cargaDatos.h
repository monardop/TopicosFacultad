#ifndef CARGADATOS_H_INCLUDED
#define CARGADATOS_H_INCLUDED

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>

    void crearFecha(uint8_t* bytes, char* mensaje, uint8_t boolEndian);
    void crearNumero(uint8_t* bytes, char* mensaje, uint8_t boolEndian);
    void examinarIntegridad();
    void lecturaArchivo();
    void mergeArchivos();

#endif // CARGADATOS_H_INCLUDED
