#include <stdio.h>
#include <locale.h>

int ehPrimo(int n){
    int y = 0, z = 0;
    for(y = 1; y <= n; y++){
        if(n % y == 0){z++;}
        if(z > 2){break;}
    }
    return (z == 2);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int a = 0, b = 0, x = 0;
    printf("Digite um valor inicial: ");
    scanf("%d", &a);
    printf("Digite um valor final: ");
    scanf("%d", &b);
    for(x = a; x <= b; x++){
        printf("%d: %s\n", x, ehPrimo(x) ? "� primo" : "n�o � primo");
    }
    return 0;
}
/*N�meros Primos em Intervalo
Escreva uma fun��o bool ehPrimo(int n) e use-a para listar todos 
os primos entre dois n�meros dados pelo usu�rio.*/