#include <stdio.h>
#include <string.h>
#include <locale.h>

void invert(char p[]){
    int t = strlen(p);
    int j = t - 1;
    char temp;
    for(int i = 0; i < j; i++, j--) {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    char digits[30];
    printf("Digite uma sequ�ncia de n�meros: ");
    scanf("%s", digits);
    invert(digits);
    printf("os digitos foram: %s", digits);
    return 0;
}

/*Inverso de N�mero
Escreva uma fun��o que inverte os d�gitos de um n�mero (ex: 1234 ? 4321)*/