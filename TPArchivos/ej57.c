#include <stdio.h>

int integridadArchivos();


int main(){

}

int integridadArchivos(){
    if(fopen("empleados_promedio.txt", "r") == NULL || fopen("empleados_sueldo.txt", "r") == NULL){
        return 0;
    }
    return 1;
}
