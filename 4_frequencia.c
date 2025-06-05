#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define max 10

typedef struct{
    int temp[max];
    int jafoi[max];
}numero;

int main(){
    setlocale(LC_ALL, "");
    numero *n = (numero *)calloc(1, sizeof(numero));
    if(n == NULL){
        printf("\n>> Erro na alocação de memória.\n");
        return 1;
    }
    int quant = 0;
    int val = 0;
    for(int x = 0; x < max; x++){
        printf("Digite o %dº número: ", x+1);
        scanf("%d", &val);
        n->temp[x] = val;
    }
    printf("\n===== RESULTADO ======\n");
    for(int z = 0; z < max; z++){
        quant = 0;
        for(int d = 0; d < max; d++){
            if(n->temp[d] == n->temp[z]){
                quant += 1;
            }
        }
        for(int d = 0; d < max; d++){
            if(n->temp[z] == n->jafoi[d]){
                quant = 0;
                break;
            }
        }
        if(quant > 0){
            n->jafoi[z] = n->temp[z];
            printf(">> O número %d apareceu %d vez%s.\n", n->temp[z], quant, quant > 1 ? "es" : "");
        }
    }
    free(n);
    return 0;
}