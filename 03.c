#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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
void inserirElemento(Pilha *pilha, int dado){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));

    novo->dado = dado;
    novo->prox = pilha->topo;

    pilha->topo = novo;

    printf("Numero inserido na pilha!\n");
    getch();
}

void consultarPilha(Pilha *pilha){
    if (pilha->topo == NULL){
        printf("Pilha vazia!\n");
        return;
    }else{
        auxi = pilha->topo;
        do
        {
            printf("\n%d\n",auxi->dado);
            auxi = auxi->prox;
        } while (auxi != NULL);
        getch();
    }
} 
int fibo(int num){
    if (num <= 1)
    {
        return num;
    }else{
        return fibo(num - 1) + fibo(num - 2);
    }
    
}

int main(){
    Pilha *pi = criaPilha();
    int num;

    printf("Digite o valor para a sequencia de fibonacci:\n");
    scanf("%d",&num);
//  para cada i vai ser calculado o i-nesimo termo de fibonacci
    for (int i = 0; i < num; i++)
    {
        int fib = fibo(i);
        // vai inserir o elemento calculado na pilha
        inserirElemento(pi,fib);

    }
    consultarPilha(pi);
}