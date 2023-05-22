#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

typedef int (*cmp)(const void*, const void*);

void mapear(void*, const int , const  , int(*func)(void*));
void filtrar(void* , size_t , size_t , int(*func)(const void*));
void* reducir(void*, int , const int , void(*func)(void*));
void* busquedaBinaria(const void*, size_t , size_t , const void* , cmp );
void insertarOrdenado(void* , int , const int );
void ordenarBurbujeo(void* , int , const int );
void quickSort(void*, int , const  , void* , void* , void* );

#endif // VECTOR_H_INCLUDED
