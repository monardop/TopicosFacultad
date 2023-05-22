int compararEnteros(const void* a, const void* b) {
    int elementoA = *(int*)a;
    int elementoB = *(int*)b;

    return elementoA - elementoB;
}