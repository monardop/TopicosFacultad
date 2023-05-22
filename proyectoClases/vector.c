#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

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
                memcpy(elementoFiltrado, elemento, tamElemento);
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

void insertarOrdenado(void *arr, size_t nroElementos, size_t tamElementos, void* elementoInsertar){
}
void ordenarBurbujeo(void *arr, size_t nroElementos, size_t tamElementos){
}
void quickSort(void *arr, size_t nroElementos, size_t tamElementos, void* elem, void* max, void* min){
}

