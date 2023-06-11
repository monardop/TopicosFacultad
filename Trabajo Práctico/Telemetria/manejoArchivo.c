#include "cargaDatos.h"

#define ARCHTELEMETRIA "../Archivos/HKTMST.bin"
#define ARCHVALORES "../Archivos/Mediciones.txt"
#define ARCHIVOFECHAS "../Archivos/Fechas.txt"


void examinarIntegridad(){
    FILE *telemetria = fopen(ARCHTELEMETRIA, "rb");
    uint32_t tamArchivo;

    if (telemetria == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    fseek(telemetria, 0L, SEEK_END);
    tamArchivo = ftell(telemetria);

    fclose(telemetria);

    if(tamArchivo % 4000 != 0){
        printf("El archivo esta corrupto\n");
        exit(EXIT_FAILURE);
    }
}

int pruebaEndiandad(){
    unsigned int numero = 1;
    unsigned char *byte = (unsigned char *)&numero;

    return (*byte == 1)? 1: 0;
}

void cargarArchivo(char* archivo, char* mensaje){
    FILE *mediciones = fopen(archivo, "at");
    fputs(mensaje, mediciones);
    fclose(mediciones);
}

void lecturaArchivo(){
    uint8_t bytesSegundos[4], bytesVoltaje[2], endiandad;
    char mensaje[40];
    int registro = 0;
    endiandad = pruebaEndiandad();
    FILE* telemetria = fopen(ARCHTELEMETRIA,"rb");

    while(!feof(telemetria))
    {
        fseek(telemetria, registro + 100, SEEK_SET); //posiciono fechas
        fread(bytesSegundos, sizeof(uint8_t), 4, telemetria);
        if(ferror(telemetria)){
            printf("Error en la lectura.\n");
            exit(EXIT_FAILURE);
        }
        // Procesamiento segundos
        crearFecha(bytesSegundos, mensaje, endiandad);
        cargarArchivo(ARCHIVOFECHAS, mensaje);


        fseek(telemetria, registro + 2354, SEEK_SET); // posiciono avg
        fread(bytesVoltaje, sizeof(uint8_t), 2, telemetria);
        if(ferror(telemetria)){
            printf("Error en la lectura.\n");
            exit(EXIT_FAILURE);
        }
        // procesamiento voltajes
        crearNumero(bytesVoltaje, mensaje, endiandad);
        cargarArchivo(ARCHVALORES, mensaje);

        registro += 4000;
    }
    fclose(telemetria);
}

void mergeArchivos(){
    FILE *archivoFechaHora = fopen(ARCHIVOFECHAS, "rt");
    FILE *archivoValores = fopen(ARCHVALORES, "rt");
    FILE *archivoCSV = fopen("../Archivos/datos.csv", "wt");

    if (archivoFechaHora == NULL || archivoValores == NULL || archivoCSV == NULL) {
        printf("Error al abrir los archivos.\n");
        exit(EXIT_FAILURE);
    }

    int dia, mes, anio, hora, minuto, segundo;
    float valor;

    fprintf(archivoCSV, "fecha;valor;\n");  // Escribir encabezado en el archivo CSV

    while (fscanf(archivoFechaHora, "%d/%d/%d %d:%d:%d", &dia, &mes, &anio, &hora, &minuto, &segundo) == 6 &&
           fscanf(archivoValores, "%f", &valor) == 1) {
        fprintf(archivoCSV, "%02d/%02d/%04d %02d:%02d:%02d;%.3f;\n", dia, mes, anio, hora, minuto, segundo, valor);
    }

    fclose(archivoFechaHora);
    fclose(archivoValores);
    fclose(archivoCSV);

}
