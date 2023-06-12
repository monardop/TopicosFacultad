#include <stdio.h>
#include <string.h>

#define ARCHIVOPROMEDIOS "empleados_promedio.txt"
#define ARCHIVOSUELDOS "empleados_sueldo.txt"
#define FORMATO "%010d%20s%20s%f\n"

typedef struct 
{
    unsigned dni;
    char apellido[20], nombre[20];
    float nota;
}TPromedio;
typedef struct 
{
    unsigned dni;
    char apellido[20], nombre[20];
    double sueldo;
}TSueldo;


int integridadArchivos();

int main(){
    if(integridadArchivos() == 0){
        printf("Se produjo un error.\n");
        return 1;
    }


    return 0;
}


int integridadArchivos(){
    if(fopen(ARCHIVOPROMEDIOS, "r") == NULL || fopen(ARCHIVOSUELDOS, "r") == NULL){
        return 0;
    }
    return 1;
}

void actualizarRegistros(){
    FILE *promedios = fopen(ARCHIVOPROMEDIOS, "r");
    FILE *sueldo = fopen(ARCHIVOSUELDOS, "w+t");
    
    int ptrEmpleado = 0, ptrPromedio = 0;
    TSueldo empleadoActual;
    TPromedio promActual = {0};

    while(!feof(promedios) && !feof(sueldo)){
        ptrPromedio = fscanf(sueldo, FORMATO, empleadoActual.dni, \
        empleadoActual.apellido, empleadoActual.nombre, empleadoActual.sueldo);
        while(!feof(promedios)){
            ptrEmpleado += fscanf(promedios, FORMATO, promActual.dni, \
            promActual.apellido, promActual.nombre, promActual.nota);
            if(strncmp(empleadoActual.apellido, promActual.apellido, 1) < 0){
                fseek(promedios, -ptrEmpleado, SEEK_CUR);
                ptrEmpleado = 0;
                break;
            }
            if(strncmp(empleadoActual.nombre, promActual.nombre, 1) < 0){
                fseek(promedios, -ptrEmpleado, SEEK_CUR);
                ptrEmpleado = 0;
                break;
            }
            if(promActual.dni == empleadoActual.dni){
                //funcion que chequee nota y cambie sueldo
                ptrEmpleado = 0;
                break; 
            }
        }
        
    }
}
