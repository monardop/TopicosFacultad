#include <stdio.h>

int existeArchivo(char* ruta, int tipo){
    // arg tipo = 1 binario, 0 txt
    if(tipo == 1){
        FILE *pf = fopen(ruta, "rb");
        if(pf == NULL){
            fclose(pf);
            return 0;
        }else{
            fclose(pf);
            return 1;
        }
    }else{
        FILE *pf = fopen(ruta, "rt");
        if(pf == NULL){
            fclose(pf);
            return 0;
        }else{
            fclose(pf);
            return 1;
        }
    }
}
