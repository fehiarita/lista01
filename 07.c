#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//pilha
typedef struct Elemento{
    int dado;
    struct Elemento *prox; 
}Elemento;

typedef struct Pilha{
    Elemento *topo;
}Pilha;

Elemento *auxip;

Pilha *criaPilha(){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void insereElemento(Pilha *pilha, int numero){
    Elemento *novo =(Elemento*) malloc(sizeof(Elemento));

        if (novo == NULL)
        {
            printf("Falha em alocar memoria!!");
            return;
        }
        
        novo->dado = numero;
        novo->prox = pilha->topo;
        pilha->topo = novo;
        printf("Numero inserido na pilha com sucesso!\n");
}
//fila
typedef struct Fila{
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;
Elemento *auxif;

Fila *criaFila(){
    Fila *fila =(Fila*) malloc(sizeof(Fila));
    if (fila != NULL)
    {
        fila->fim = NULL;
        fila->inicio = NULL;
    }
    return fila; 
}

void inserepar(Fila *fila, Pilha *pilha){
    auxip = pilha->topo;

    while (auxip != NULL)
    {
        if (auxip->dado % 2 == 0)
        {
            Elemento *novo =(Elemento*) malloc(sizeof(Elemento));
            novo->dado = auxip->dado;
            novo->prox = NULL;
            printf("Numero %d inserido na fila com sucesso!!\n", novo->dado);
            if (fila->inicio == NULL)
            {
                fila->inicio = novo;
                fila->fim = novo;
            }else{
                fila->fim->prox = novo;
                fila->fim = novo;
            }
            
        }
       auxip = auxip->prox; 
    }
    if (fila->inicio == NULL)
    {
        printf("Fila de par vazia!\n");
    }
}
void insereimpar(Fila *fila ,Pilha *pilha){
    auxip = pilha->topo;

    while (auxip != NULL)
    {
        if (auxip->dado % 2 != 0)
        {
            Elemento *novo =(Elemento*) malloc(sizeof(Elemento));
            novo->dado = auxip->dado;
            novo->prox = NULL;
            printf("Numero %d inserido na fila com sucesso!!\n", novo->dado);
            if (fila->inicio == NULL)
            {
                fila->inicio = novo;
                fila->fim = novo;
            }else{
                fila->fim->prox = novo;
                fila->fim = novo;
            }
            
        }
        auxip = auxip->prox;
    }
    if (fila->inicio == NULL)
    {
        printf("Fila de impar vazia!\n");
    }
    
}
void liberaPilha(Pilha *pilha) {
    Elemento *atual = pilha->topo;
    while (atual != NULL) {
        Elemento *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pilha);
}

void liberaFila(Fila *fila) {
    Elemento *atual = fila->inicio;
    while (atual != NULL) {
        Elemento *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
}
void imprimeFila(Fila *fila){
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!\n");
    }
    auxif = fila->inicio;
    printf("-----fila-----");
    while (auxif != NULL)
    {
        printf("%d\n",auxif->dado);
        auxif = auxif->prox;
    }
}
int main() {
    Pilha *pilha = criaPilha();
    Fila *filapar = criaFila();
    Fila *filaimpar = criaFila();
    int num = 0;

    while (1) {
        printf("Digite o numero que quer guardar na pilha:\n");
        scanf("%d", &num);
        
        if (num < 0) {
            break;
        }
        
        insereElemento(pilha, num);
    }
    
    insereimpar(filaimpar, pilha);
    inserepar(filapar, pilha);

    printf("Fila de pares:\n");
    imprimeFila(filapar);
    printf("Fila de ímpares:\n");
    imprimeFila(filaimpar);

    liberaPilha(pilha);
    liberaFila(filapar);
    liberaFila(filaimpar);

    return 0;
}
