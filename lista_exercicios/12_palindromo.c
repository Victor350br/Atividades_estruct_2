#include <stdio.h>
#include <string.h>
#include <locale.h>

#define max 50

int verificador(char s[], int tam){
    char copia[tam];
    int y = tam;
    for(int x = 0; x <= tam; x++, y--){
        copia[x] = s[y];
    }
    if(strcmp(s, copia) == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    setlocale(LC_ALL, "");
    char string[max];
    printf("Digite uma string: ");
    fgets(string, max, stdin);
    string[strcspn(string, "\n")] = 0;
    
    int tam = strlen(string) - 1;
    printf("\nA string digitada %s", verificador(string, tam) 
        ? "é um palíndromo" : "Não é um palíndromo");

    return 0;
}
/*Verificador de Palíndromo
Dada uma string (array de char), diga se ela é um palíndromo (ex: ?arara?, ?radar?).*/