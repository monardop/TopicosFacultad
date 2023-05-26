#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

typedef int (*cmp)(const void*, const void*);

void mapear(void* arr, size_t nroElementos, size_t tamElemento, void(*func)(void*));
void filtrar(void* arr, size_t nroElem, size_t tamElemento, int(*func)(const void*));
void reducir(void* arr, size_t nroElementos, size_t tamElemento, void*(*func)(const void*, void*), void* acumulador);
void* busquedaBinaria(const void* arr, size_t nroElementos, size_t tamElemento, const void* objetivo, cmp comparador);
void agregarElementoOrdenado(void* vector, size_t* nroElementos, size_t tamElemento, size_t topeMax, const void* elemento, cmp comparador);
void ordenarBurbujeo(void *arr, size_t nroElementos, size_t tamElemento, cmp cmp);
void quickSort(void *arr, size_t tamElementos, int izquierda, int derecha, cmp cmp);

#endif // VECTOR_H_INCLUDED
