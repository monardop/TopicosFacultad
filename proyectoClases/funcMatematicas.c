float calcularRaizCuadrada(float num) {
    if (num == 0.0 || num == 1.0) {
        return num;
    }

    float resultado = num;
    float epsilon = 0.00001;  // Precisión deseada
    while (1) {
        float temp = 0.5 * (resultado + num / resultado);
        if (temp - resultado < epsilon && resultado - temp < epsilon) {
            break;
        }
        resultado = temp;
    }

    return resultado;
}

double pow(const double base, int potencia){
    double resultado = base;
    // Casos especiales
    if(potencia == 0 && base != 0)
        return 1;

    if(base == 0 || base == 1)
        return base;

    if(base == 0 && base == 0)
        return -1;
    // Si no salto lo anterior, calculo.
    for(potencia; potencia > 0; potencia--){
        resultado += base;
    }
    return resultado;
}

unsigned int factorial(unsigned int base){
    unsigned int resultado = 1;
    
    if(base == 0 || base == 1)
        return 1;
    
    for(base; base > 0; base--){
        resultado *= base;
    }
    return resultado;
}

double abs(double x){
    if(x < 0){
        return x;
    }
    else{
        return -x;
    }
}

/* */
