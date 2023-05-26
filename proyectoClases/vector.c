#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void memcpyPropia(void *dest, const void *src, size_t n){
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (size_t i = 0; i < n; i++){
        cdest[i] = csrc[i];
    }
}

void intercambiar(void* dest, void* src, size_t bytes){
    void* aux = malloc(bytes);
    memcpyPropia(aux, src, bytes);
    memcpyPropia(src, dest, bytes);
    memcpyPropia(dest, aux, bytes);
}

void mapear(void* arr, size_t nroElementos, size_t tamElemento, void(*func)(void*))
{
    void* elementoActual;
    for (size_t i = 0; i < nroElementos; i++)
    {
        elementoActual = (char*)arr + (i*tamElemento);
        func(elementoActual);
    }
}

void filtrar(void* arr, size_t nroElem, size_t tamElemento, int(*func)(const void*)) {
    int indiceFiltrado = 0;
    void *elementoFiltrado, *elemento;
    // Recorrer el vector y filtrar los elementos
    for (size_t i = 0; i < nroElem; i++) {
        elemento = (char*)arr + i * tamElemento;

        if (func(elemento)) {
            // Mantener el elemento en el arr
            if (i != indiceFiltrado) {
                // Si el elemento no está en la posición correcta, moverlo
                elementoFiltrado = (char*)arr + indiceFiltrado * tamElemento;
                memcpyPropia(elementoFiltrado, elemento, tamElemento);
            }

            indiceFiltrado++;
        }
    }
    printf("Se filtro %d elementos.\n", indiceFiltrado);
}

void reducir(void* arr, size_t nroElementos, size_t tamElemento, void*(*func)(const void*, void*), void* acumulador){
    void* elementoActual;

    for (size_t i = 0; i < nroElementos; i++)
    {
        elementoActual = (char*)arr + (i*tamElemento);
        func(elementoActual, acumulador);
    }
}

void* busquedaBinaria(const void* arr, size_t nroElementos, size_t tamElemento, const void* objetivo, cmp comparador) {
    size_t inicio = 0;
    size_t fin = nroElementos - 1;
    size_t medio = (inicio + fin) / 2;
    int resultado;
    void* elementoMedio;

    while (inicio <= fin) {
        medio = (inicio + fin) / 2;
        elementoMedio = (char*)arr + medio * tamElemento;

        resultado = comparador(elementoMedio, objetivo);

        if (resultado == 0) {
            return elementoMedio;
        } else if (resultado < 0) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return NULL;
}

void agregarElementoOrdenado(void* vector, size_t* nroElementos, size_t tamElemento, size_t topeMax, const void* elemento, cmp comparador) {
    if (*nroElementos >= topeMax) {
        printf("Error: El vector está completo.\n");
        return;
    }
    void *destino, *origen;

    // Encontrar la posición de inserción
    size_t posicion = 0;
    while (posicion < *nroElementos && comparador((const char*)vector + posicion * tamElemento, elemento) < 0) {
        posicion++;
    }

    // Desplazar los elementos a la derecha para hacer espacio
    for (size_t i = *nroElementos; i > posicion; i--) {
        destino = (char*)vector + i * tamElemento;
        origen = (char*)vector + (i - 1) * tamElemento;
        memcpyPropia(destino, origen, tamElemento);
    }

    // Copiar el elemento en la posición de inserción
    destino = (char*)vector + (posicion * tamElemento);
    memcpyPropia(destino, elemento, tamElemento);
}

void ordenarBurbujeo(void *vector, size_t nroElementos, size_t tamElemento, cmp cmp){
    void* elemActual, *elemSiguiente;
    for(size_t i = 0; i < nroElementos; i++){
        for(size_t j = 0; j < nroElementos - 1; j++){
            elemActual = (char*)vector + (tamElemento * j);
            elemSiguiente = (char*)vector + (tamElemento * j) + 1;
            if(cmp(elemActual, elemSiguiente) != 0){
                intercambiar(elemActual, elemSiguiente, tamElemento);
            }
        }
    }
}

void quickSort(void *vector, size_t tamElementos, int izquierda, int derecha, cmp cmp){
    if(izquierda<derecha){
        void* pivot = (char*)vector + derecha*tamElementos;
        int i = izquierda - 1;
        for(int j = izquierda; j < derecha; j++){
            void* current = (char*)vector + j* tamElementos;
            if(cmp(current, pivot) < 0){
                i++;
                intercambiar((char*)vector + (i*tamElementos), current, tamElementos);
            }
            intercambiar((char*)vector + (i+1) * tamElementos, pivot, tamElementos);
            quickSort(vector, izquierda, i, tamElementos, cmp);
            quickSort(vector, i + 2, derecha, tamElementos, cmp);
        }
    }
}

