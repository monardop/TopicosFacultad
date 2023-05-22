#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

typedef int (*cmp)(const void*, const void*);

void mapear(void* arr, const int nroElementos, const int tamElementos, int(*func)(void*));
void filtrar(void* arr, int nroElementos, const int tamElementos, void*, cmp comparador);
void* reducir(void* arr, int nroElementos, const int tamElementos, void(*func)(void*));
void* busquedaBinaria(const void* arr, size_t nroElementos, size_t tamElemento, const void* objetivo, cmp comparador);
void insertarOrdenado(void *arr, int nroElementos, const int tamElementos);
void ordenarBurbujeo(void *arr, int nroElementos, const int tamElementos);
void quickSort(void *arr, int nroElementos, const int tamElementos, void* elem, void* max, void* min);

#endif // VECTOR_H_INCLUDED
