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

double potencia(const double base, int potencia){
    double resultado = base;
    // Casos especiales
    if(potencia == 0 && base != 0){
        return 1;
    }

    if(base == 0 || base == 1){
        return base;
    }

    if(base == 0 && base == 0){
        return -1;
    }

    // Si no salto lo anterior, calculo.
    for(int i = potencia; i > 1; i--){
        resultado *= base;
    }
    return resultado;
}

unsigned int factorial(unsigned int base){
    unsigned int resultado = 1;
    
    if(base == 0 || base == 1){
        return 1;
    }
    
    for(int i = base; i > 1; i--){
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
    double respuesta = 0, temp;
    int grado = 1, boolSuma = 1;
    
    while(1){
        temp = potencia(x, grado) / factorial(grado);
        if(temp > EPSILON){
           if(boolSuma == 1)
           {
                respuesta += temp; 
                boolSuma = 0;
           } else{
                respuesta -= temp;
                boolSuma = 1;
           }
        }else{
            return respuesta;
        }
        grado += 2;
    }
}

double coseno(float x){
    double respuesta = 0, temp;
    int grado = 0, boolSuma = 1;
    while(1){
        temp = potencia(x, grado) / factorial(grado);
        if(temp > EPSILON){
           if(boolSuma == 1)
           {
                respuesta += temp; 
                boolSuma = 0;
           } else{
                respuesta -= temp;
                boolSuma = 1;
           }
        }else{
            return respuesta;
        }
        grado += 2;
    }
}

double tangente(float x){
    if(x == 90){
        return x;
    }
    
    double respuesta = seno(x)/coseno(x);
    return respuesta;
}

double potenciaEuler(int x){
    double respuesta = 1, temp;
    int i = 1;
    while(1){
        temp = potencia(x,i)/factorial(i);
        if(temp > EPSILON){
            respuesta += temp;
        }else{
            break;
        }
        i++;
    }
    return respuesta;
}
