#include <stdio.h>

/*
Recibo un archivo de palabras separadas por punto o el caracter nulo. El 
objetivo es leer el archivo, revisar cuantas veces se repita la primera palabra,
cuantas palabras hay y cuantos caracteres tiene la palabra más larga.
_EN_
I receive a file with words separated by a period or the null character. The 
objective is to read the file, check how many times the first word is repeated, 
count the total number of words, and determine the length of the longest word.
*/

void fileReader(const char*, const char*);

int main(){
    fileReader("palabras.txt", "rt");

    return 0;    
}


int stringLenght(const char* string){
    int count = 0;

    while(*string != '\0' && *string != '.'){
        count++;
        string++;
    }   

    return count;
}

int stringCompare(const char* str1, const char* str2){
    int counter = 0;
    while(*str1 && *str1 != '.'){
        counter += (int)(*str1);
        str1++;
    }
    while(*str2 && *str1 != '.'){
        counter -= (int)(*str2);
        str2++;
    }
    return counter;
}

void resultPrinter(char* firstWord, const int words, const int maxlen, const int firstTimes){
    printf("The first word is: %s and it appeared %d times.\n", *firstWord, firstTimes);
    printf("%d words in this file. \n", words);
    printf("The length of the longest word was %d chars.\n", maxlen);
}

void fileReader(const char* path, const char* mode){
    FILE* words = fopen(path, mode);
    char newWord[30], firstWord[30];
    unsigned maxLen, wordsCounter = 1, firstWordTimes = 0;

    fgets(firstWord, 30, words);
    maxLen = stringLenght(firstWord);
    printf("%s", firstWord);
    while (fgets(newWord,30,words) != NULL){
        int newLen = stringLenght(newWord);
        if(newLen > maxLen){
            maxLen = newLen;
        }
        if(stringCompare(firstWord, newWord) == 0){
            firstWordTimes++;
        }
        wordsCounter++;
    }
    fclose(words); 
    // resultPrinter(firstWord,wordsCounter,maxLen,firstWordTimes);
}