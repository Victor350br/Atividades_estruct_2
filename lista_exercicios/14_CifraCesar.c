#include <stdio.h>
#include <string.h>
#include <locale.h>

#define max 100

void criptografar(char str[], int tam, int chave){
    int x = 0, y = 0;
    for(x = 0; x < tam; x++){
        for(y = 0; y < chave; y++){
            if(str[x] == 'z'){
                str[x] -= 26;
            }
            str[x] += 1;
        }
    }
}

void descriptografar(char str[], int tam, int chave){
    int x = 0, y = 0;
    for(x = 0; x < tam; x++){
        for(y = 0; y < chave; y++){
            if(str[x] == 'a'){
                str[x] += 26;
            }
            str[x] -= 1;
        }
    }
}

int main(){
    setlocale(LC_ALL, "");
    int opc = 0;
    int chave = 0;
    int tam = 0;
    char string[max];

    while(1){
        printf("\n===== CIFRA DE CESAR =====\n");
        printf("[1] Criptografar \n[2] Descriptografar \n[3] Sair \n>> ");
        scanf("%d", &opc);
        setbuf(stdin, NULL);

        if(opc == 3){
            printf("\n>> Obrigado, volte sempre.\n\n");
            return 0;
        }

        printf("Digite uma mensagem: \n>> ");
        fgets(string, max, stdin);
        string[strcspn(string, "\n")] = 0;
        tam = strlen(string);

        printf("Digite a chave: \n>> ");
        scanf("%d", &chave);
        setbuf(stdin, NULL);

        switch(opc){
            case 1:
                criptografar(string, tam, chave);
                printf("\n>> A mensagem criptografada fica: %s\n\n", string);
                break;
            case 2:
                descriptografar(string, tam, chave);
                printf("\n>> A mensagem descriptografada fica: %s\n\n", string);
                break;
        }
    }
}

/*Cifra de César
Escreva uma função para criptografar uma mensagem 
usando a Cifra de César (deslocamento de letras).*/