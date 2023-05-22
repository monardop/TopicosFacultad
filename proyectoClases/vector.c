#include <stdio.h>
#include "vector.h"

void intercambio(void* a, void* b)
{
    void* punteroAux = a;
    
    a = b;
    b = punteroAux;
}

void borrarElemento(void* arreglo, const int ce, const int tamElemento){

    // Mover los elementos siguientes una posición hacia atrás
    for (int i = 0; i < ce - 1; i++) {
        arreglo = arreglo + (i * tamElemento);
    }
}

void mapear(void* arr, int nroElementos, int tamElemento, int(*func)(void*))
{
    for(int i = 0; i < nroElementos; i++)
    {
        if(func(arr+(i*tamElemento)) == 1)
            return;
    }
}

void filtrar(void* arr, int nroElementos, const int tamElementos, const void* parametro , cmp comparador)
{
    // si cmp da 1 significa que cumple el criterio. De lo contrario hay cambio.
    int i = 0;  
    while(i < nroElementos)
    {
        if(comparador(arr, parametro) == 0){
            borrarElemento(arr,nroElementos, tamElementos);
            nroElementos--;
        }
        i++;
        arr += tamElementos;
    }
}
void* reducir(void* arr, int nroElementos, int tamElementos, void(*func)(void*), void* elem){
    
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

void insertarOrdenado(void *arr, int nroElementos, int tamElementos){
}
void ordenarBurbujeo(void *arr, int nroElementos, int tamElementos){
}
void quickSort(void *arr, int nroElementos, int tamElementos, void* elem, void* max, void* min){
}

