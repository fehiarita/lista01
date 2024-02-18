#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
// fila
typedef struct Elemento{
    int dado;
    struct Elemento *prox;
}Elemento;

typedef struct Fila{
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;

Elemento *auxi;

Fila *criaFila(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if (fila != NULL)
    {
        fila->fim = NULL;
        fila->inicio = NULL;
    }
    return fila;
}

void insereFila(Fila *fila,int dado){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->dado = dado;
    novo->prox = NULL;
    if (fila->inicio == NULL)
    {
        printf("\nFila Vazia!\n");
    }else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    printf("\nNumero inserido na fila!\n");
    getch();
}

void imprimeFila(Fila *fila){
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!\n");
        return;
    }else
    {
        auxi = fila->inicio;
        while (auxi != NULL)
        {
            printf("%d\n",auxi->dado);
            auxi = auxi->prox;
        }
        getch();
    }
    
    
}
// pilha

typedef struct Elemento{
    int dado;
    struct Elemento *prox;
}Elemento;

typedef struct Pilha{
    Elemento *topo;
}Pilha;

Elemento *auxi;

Pilha *criaPilha(){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha != NULL)
    {
        pilha->topo = NULL;
    }
    return pilha;
}

inserePilha(Pilha *pilha, int dado){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));

    novo->dado = dado;
    novo->prox = pilha->topo;
    printf("Numero inserido na pilha com sucesso!\n");
    getch();
}
void imprimePilha(Pilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("Pilha vazia!\n");
    }else
    {
        auxi = pilha->topo;
        while (auxi != NULL)
        {
            printf("%d\n",auxi->dado);
            auxi = auxi->prox;
        }
        getch();
    }
    
    
}
int main(){
    Pilha *P = criaPilha();
    Fila *F = criaFila();
    int escolha = 0;

    inserePilha(P,7);
    inserePilha(P,8);
    inserePilha(P,9);
    inserePilha(P,10);
    inserePilha(P,11);

    insereFila(F,3);
    insereFila(F,4);
    insereFila(F,5);
    insereFila(F,6);
    insereFila(F,2);

    while (1)
    {
        printf("\n-------- MENU DE OPCOES --------\n");
        printf("[1] imprimir as duas estruturas\n");
        printf("[2] imprimir fila\n");
        printf("[3] imprimir pilha\n");
        printf("Escolha uma opcao:\n");
        scanf("%d\n",&escolha);

        switch (escolha)
        {
        case 1:
            imprimeFila(F);
            imprimePilha(P);
            break;
        case 2:
            imprimeFila(F);
            break;
        case 3:
            imprimePilha(P);
            break;
        default:
            printf("Opção invalida! Por favor, escolha outra opcao\n");
        }
    }
    
}