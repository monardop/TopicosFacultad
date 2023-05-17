#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

void mapear(void* arr, int nroElementos, int tamElementos, int(*func)(void*));
void filtrar(void* arr, int nroElementos, int tamElementos, int(*cmp)(const void*, const void*));
void reducir(void* arr, int nroElementos, int tamElementos, void(*func)(void*));
int busquedaBinaria(void *arr, int nroElementos, int tamElementos, void* elem, void* max, void* min);
void insertarOrdenado(void *arr, int nroElementos, int tamElementos);
void ordenarBurbujeo(void *arr, int nroElementos, int tamElementos);
void quickSort(void *arr, int nroElementos, int tamElementos, void* elem, void* max, void* min);



#endif // VECTOR_H_INCLUDED
