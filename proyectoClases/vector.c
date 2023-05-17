void intercambio(void* a, void* b)
{
    void* punteroAux = a;
    a = b;
    b = punteroAux;
}

void mapear(void* arr, int nroElementos, int tamElemento, int(*func)(void*)){
    for(int i = 0; i < nroElementos; i++)
    {
        if(func(arr+(i*tamElemento)) == 1)
            return;
    }
}
void filtrar(void* arr, int nroElementos, int tamElementos, int(*cmp)(const void*, const void*)){
}
void reducir(void* arr, int nroElementos, int tamElementos, void(*func)(void*)){
}
int busquedaBinaria(void *arr, int nroElementos, int tamElementos, void* elem, void* max, void* min){
    return 0;
}
void insertarOrdenado(void *arr, int nroElementos, int tamElementos){
}
void ordenarBurbujeo(void *arr, int nroElementos, int tamElementos){
}
void quickSort(void *arr, int nroElementos, int tamElementos, void* elem, void* max, void* min){
}

