#include <stdio.h>
#include <locale.h>

int fibonacci(int n){
    if(n <= 1){
        return 0;
    }else if(n == 2){
        return 1;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    setlocale(LC_ALL, "");
    int n = 0, f = 0;
    printf("Digite um n�mero: ");
    scanf("%d", &n);
    f = fibonacci(n);
    printf("O %d� n�mero da sequ�ncia � %d.\n", n, f);
    return 0;
}
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

/*Sequ�ncia de Fibonacci Recursiva
Escreva uma fun��o recursiva para gerar o n-�simo n�mero de Fibonacci.*/