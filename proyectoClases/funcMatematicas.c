#define EPSILON 0.00001 // Presición deseada

float calcularRaizCuadrada(float num) {
    if (num == 0.0 || num == 1.0) {
        return num;
    }

    float resultado = num;
    float temp;

    while (1) {
        temp = 0.5 * (resultado + num / resultado);
        if (temp - resultado < EPSILON && resultado - temp < EPSILON) {
            break;
        }
        resultado = temp;
    }

    return resultado;
}

double potencia(const double base, int exponente){
    double resultado = 1.0;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}

unsigned int factorial(unsigned int base){
    unsigned int resultado = 1;

    for (int i = 1; i <= base; i++) {
        resultado *= i;
    }
    return resultado;
}

double modulo(double x){
    if(x < 0){
        return x;
    }
    else{
        return -x;
    }
}

// Para cos, sen y e^x usaré series de taylor
double seno(float x){
    double resultado = 0.0;
    int terminos = 30;  // Número de términos en la serie de Taylor

    for (int i = 0; i < terminos; i++) {
        int n = 2 * i + 1;
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        double termino = (signo * potencia(x, n)) / factorial(n);
        resultado += termino;
    }

    return resultado;
}

double coseno(float x){
    double resultado = 0.0;
    int terminos = 30;  // Número de términos en la serie de Taylor

    for (int i = 0; i < terminos; i++) {
        int n = 2 * i;
        double signo = (i % 2 == 0) ? 1.0 : -1.0;
        double termino = (signo * potencia(x, n)) / factorial(n);
        resultado += termino;
    }

    return resultado;
}

double tangente(float x){
    if(x == 90){
        return x;
    }

    double respuesta = seno(x)/coseno(x);
    return respuesta;
}

double potenciaEuler(int x){
    double resultado = 1.0;
    int terminos = 10;  // Número de términos en la serie de Taylor (puedes ajustarlo para mayor precisión)

    for (int i = 1; i <= terminos; i++) {
        resultado += potencia(x, i) / factorial(i);
    }

    return resultado;
}
