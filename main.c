#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

struct Pilha{
 int num;
 struct Pilha *prox;
};
typedef struct Pilha tpilha;

int tam;

int menu(void);
void inicia(tpilha *PILHA);
void opcao(tpilha *PILHA, int op);
void exibe(tpilha *PILHA);
void libera(tpilha *PILHA);
void push(tpilha *PILHA);
tpilha *pop(tpilha *PILHA);


int main()
{
    setlocale(LC_ALL,"Portuguese");
    tpilha *PILHA = (tpilha *) malloc(sizeof(tpilha));
    if(!PILHA){
        printf("\nSem memoria disponivel!\n");
        exit(1);
    }else{
        inicia(PILHA);
        int opt;

        tpilha *aux;

        do{
            system("cls");
            menu();
            scanf("%d",&opt);
            //opcao(PILHA,opt);

            switch(opt){
            case 0:
                break;

            case 1:
                push(PILHA);
                break;

            case 2:
                aux= pop(PILHA);
                if(aux != NULL)
                printf("Retirado: %3d\n\n", aux->num);
                break;

            case 3:
                exibe(PILHA);
                break;

            case 4:
                libera(PILHA);
                inicia(PILHA);
                printf("Pilha limpa!\n");
                break;

            }
            getch();
        }while(opt!=0);

        free(PILHA);
        return 0;
    }

}

//Iniciar pilha
void inicia(tpilha *PILHA)
{
 PILHA->prox = NULL;
 tam=0;
}

// Menu
int menu(void){
    system("color 17");
    printf("%65s","--------------------- MENU ---------------------\n");
	printf("\n                - 1: Inserir (PUSH)                            -");
	printf("\n                - 2: Remover (POP)                             -");
	printf("\n                - 3: Exibir pilha                              -");
	printf("\n                - 4: Limpar pilha                              -");
	printf("\n                - 0: Sair                                      -\n");
	printf("%65s","------------------------------------------------\n");
	printf("\n->");
}

//Opções
/*void opcao(tpilha *PILHA, int op)
{
 tpilha *aux;
 switch(op){
  case 0:
   exit(1);
   break;

  case 1:
   push(PILHA);
   break;

  case 2:
   aux= pop(PILHA);
   if(aux != NULL)
   printf("Retirado: %3d\n\n", aux->num);
   break;

  case 3:
   exibe(PILHA);
   break;

  case 4:
   libera(PILHA);
   inicia(PILHA);
   break;

  default:
   printf("Comando invalido\n\n");
 }
} */

//pilha vazia
int vazia(tpilha *PILHA)
{
 if(PILHA->prox == NULL)
  return 1;
 else
  return 0;
}

//aloca memoria
tpilha *aloca()
{
 tpilha *novo=(tpilha *) malloc(sizeof(tpilha));
 if(!novo){
  printf("\nSem memoria disponivel!\n");
  exit(1);
 }else{
  printf("\nNovo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}

//Exibe Pilha
void exibe(tpilha *PILHA)
{
 if(vazia(PILHA)){
  printf("\nPilha vazia!\n\n");
  return ;
 }

 tpilha *aux;
 aux = PILHA->prox;
 system("cls");
 printf("PILHA:\n");

 printf("-----------------------------------------------------------------\n");
 printf("||                                                             ||\n");
 printf("||");
 while( aux != NULL){
  printf("%d", aux->num);
  if(aux->prox!=NULL)printf(", ");
  else printf(" ->");
  aux = aux->prox;
 }
 printf("\n||                                                             ||\n");
 printf("-----------------------------------------------------------------\n");


 /*printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1); */


 printf("\n\n");
}

//Libera
void libera(tpilha *PILHA)
{
 if(!vazia(PILHA)){
  tpilha *proxtpilha,
     *atual;

  atual = PILHA->prox;
  while(atual != NULL){
   proxtpilha = atual->prox;
   free(atual);
   atual = proxtpilha;
  }
 }
}

//Inserir
void push(tpilha *PILHA)
{
 tpilha *novo=aloca();
 novo->prox = NULL;

 if(vazia(PILHA))
  PILHA->prox=novo;
 else{
  tpilha *aux = PILHA->prox;

  while(aux->prox != NULL)
   aux = aux->prox;

  aux->prox = novo;
 }
 tam++;
}

// Remover
tpilha *pop(tpilha *PILHA)
{
 if(PILHA->prox == NULL){
  printf("\nPilha ja esta vazia\n\n");
  return NULL;
 }else{
  tpilha *ultimo = PILHA->prox,
  *penultimo = PILHA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}
