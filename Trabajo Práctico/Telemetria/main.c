#include <stdio.h>

#include "cargaDatos.h"

int main()
{
    examinarIntegridad();
    lecturaArchivo();
    mergeArchivos();

    printf("\nProceso finalizado.\n");

    return 0;
}
