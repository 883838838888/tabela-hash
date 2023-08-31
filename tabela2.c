#include<stdio.h>
#include<stdlib.h>

#define MAX 31

void inicializartabela(int t[]){
    int i;

    for(i = 0; i < MAX; i++){
        t[i] = 0;
    }
}

int funcaohash(int chave){
    return chave % MAX;
}

int inserir(int t[], int valor){
    int id = funcaohash(valor);
    while(t[id] != 0){
        id = (id + 1) % MAX;
    }  
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = funcaohash(chave);
    while(t[id] != 0){
        if(t[id] == chave){
            return t[id];
        }else{
            id = (id + 1) % MAX;
        }
    }  
    return 0;
}

void imprimir(int t[]){
    int i;

    for(i =  0; i < MAX; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int main(){
    int tabelahash[MAX];
    int op, valor, retorno;

    inicializartabela(tabelahash);

    do{
        printf("\n\t0 - sair \n\t1 - inserir \n\t2 - buscar \n\t3 - imprimir\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Qual o valor que deseja inserir? \n");
                scanf("%d", &valor);
                inserir(tabelahash, valor);
                break;

            case 2:
                printf("Qual o valor que deseja buscar? \n");
                scanf("%d", &valor);
                retorno = busca(tabelahash, valor);
                if(retorno != 0 ){
                    printf("Valor encontrado: %d\n", retorno);
                }else{
                    printf("Valor nao encontrado!\n");
                }
                break;

            case 3:
                imprimir(tabelahash);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    }while(op != 0);

    return 0;
}
