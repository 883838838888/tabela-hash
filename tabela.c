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


int inserir(int valor){

   int id = funcaohash(valor);
    while(t[id] != 0){
        id = funcaohash(id + 1);

    }  
    t[id] =  valor;
}

int busca(int t[], int chave){

  
   int id = funcaohash(chave);
    while(t[id] != 0){
      if(t[id] == chave){
           return t[id];
      }else{
        id = funcaohash(id + 1);
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
         printf("\n\t0 - sair \n\t1 - inserir \n\t2 - buscar \n\t3 - imprimir");
        scanf("%d", &op);
       
       switch(op){
             
         case 1:
            printf("qual o valor que desejar inserir? \n");
             scanf("%d", &valor);
             inserir(tabelahash, valor);
         break;
         
          case 2:
             printf("qual o valor que desejar buscar? \n");
             scanf("%d", &valor);
             retorno = busca(tabelahash, valor);
             if(retorno != 0 ){
                printf("valor encontrado: %d\n", retorno);
                
             }else{
                printf("valor nao encontrado!\n");
             }
         break;
           
         case 3:
           imprimir(tabelahash);
         break;

        default:
          printf("opcao invalida!\n");
       }

     }while(op != 0);

    return 0;
}