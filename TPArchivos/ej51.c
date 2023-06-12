#include <stdio.h>

#define LECTOR(path, modo)({\
    if(fopen(path, modo) == NULL){\
        printf("No se pudo abrir el archivo.\n");\
    }\
    else{\
        printf("Archivo en orden.\n");\
    }\
    })

int main(){
    LECTOR("empleados_promedio.txt", "rt");
    printf("Salio todo bien.");
}