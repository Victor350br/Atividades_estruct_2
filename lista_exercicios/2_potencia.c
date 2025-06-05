#include <stdio.h>
#include <locale.h>

int potencia(int base, int expoente){
    int x = 0, pot = 1;
    for(x = expoente; x >= 1; x--){
        pot *= base;
    }
    return pot;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int b = 0, e = 0;
    printf("Digite o valor da base: ");
    scanf("%d", &b);
    printf("Digite o valor do expoente: ");
    scanf("%d", &e);
    printf("O resultado �: %d", potencia(b, e));
    return 0;
}

/*Pot�ncia (sem usar pow)
Implemente uma fun��o int potencia(int base, int expoente) que 
calcule pot�ncias usando apenas multiplica��es.*/