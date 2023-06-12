#include <stdio.h>
#include <string.h>
/*
Recibo un string de palabras separadas por punto o el caracter nulo. El
objetivo es leer el archivo, revisar cuantas veces se repita la primera palabra,
cuantas palabras hay y cuantos caracteres tiene la palabra más larga.
_EN_
I receive a string with words separated by a period or the null character. The
objective is to read the file, check how many times the first word is repeated,
count the total number of words, and determine the length of the longest word.
*/

#define MAXLEN 100
void lector(char* string);
void limpiarstr(char*);

int main(){
    char string[MAXLEN] = "pablo.pablo.pablo.holasoypablo.pablo";

    // printf("Inserte palabras separadas por un punto:\n");
    // fgets(string, sizeof(string), stdin);

    limpiarstr(string);
    lector(string);

    return 0;
}

void limpiarstr(char* str){
    int i=0;
    while(*str && i < MAXLEN){
        if(*str == '\n'){
            *str = '\0';
            break;
        }
        str++;
        i++;
    }
    if(i == 99){
        *str = '\0';
    }
}

int buscarFinPalabra(char* string){
    int contador = 0;
    while(*string){
        if(*string == '.'){
            break;
        }
        contador++;
        string++;
    }
    if(contador == 0)
        return 1;
    return contador;
}

void lector(char* string){
    int contadorPalabras = 1, maxLongitud, repeticionPrimera = 0;
    char primeraPalabra[MAXLEN];
    char* punteroPalabras = string;
    
    maxLongitud = buscarFinPalabra(punteroPalabras);
    strncpy(primeraPalabra, string, maxLongitud);
    punteroPalabras += maxLongitud;
    while(*punteroPalabras){
        int nuevaLongitud = buscarFinPalabra(punteroPalabras);
        if(nuevaLongitud > maxLongitud){
            maxLongitud = nuevaLongitud;
        }
        if(strncmp(primeraPalabra, punteroPalabras, nuevaLongitud) == 0){
            repeticionPrimera++;
        }
        if(*punteroPalabras != '.'){
            contadorPalabras++;
        }
        punteroPalabras += nuevaLongitud;
    }
    
    printf("\n");
    printf("-Primer palabra: %s\n-Cant palabras: %d\n-Repeticion primer palabra: %d", primeraPalabra, contadorPalabras, repeticionPrimera);
    printf("\n-La long maxima es de %d", maxLongitud);
    printf("\n");
}
