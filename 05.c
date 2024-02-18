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

void inserirPilha(Pilha *pilha, int dado){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->dado = dado;

    novo->prox = pilha->topo;
    pilha->topo = novo;

    printf("Numero inserido na pilha!\n");
    getch();
}

void imprimePar(Pilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("Pilha vazia!\n");
    }
    auxi = pilha->topo;
    while (auxi != NULL)
    {
        if (auxi->dado % 2 == 0)
        {
            printf("%d\n", auxi->dado);
        }
        auxi = auxi->prox;
    }
    
}

void imprimePilha(Pilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("Pilha vazia!\n");
    }
    auxi = pilha->topo;
    while (auxi != NULL)
    {
        printf("%d\n", auxi->dado);
        auxi = auxi->prox;
    }
    
}

void removedaPilha(Pilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("Pilha vazia!\n");
        return;
    }

    int dado = 0;
    printf("Digite o numero que quer remover:\n");
    scanf("%d",&dado);

    Elemento *atual = pilha->topo;
    Elemento *anterior = NULL;
    //procurando pelo elemento que vai ser removido
    while (atual != NULL && atual->dado != dado)
    {
        anterior = atual;
        atual = atual->prox;
    }
    
    if (atual == NULL)
    {
        printf("Elemento %d não encontrado na pilha.\n",dado);
        return;
    }

    // removendo o elemento encontrado
    if (anterior == NULL)//se o elemento for o primeiro da pilha
    {
        pilha->topo = atual->prox;
    }else{
        anterior->prox = atual->prox;
    }

    int valor = atual->dado;
    free(atual);
    printf(" elemento %d removido com sucesso!\n",valor);
}

int main(){
    Pilha *p = criaPilha();
    int escolha = 0;
    int num = 0;

    while (1)
    {
    printf("\n-------- MENU DE OPCOES --------\n");
    printf("[1] cadastrar numero\n");
    printf("[2] mostrar numeros pares\n");
    printf("[3] excluir numero\n");
    printf("[4] Sair\n");
    scanf("%d",&escolha);

    switch (escolha)
    {
    case 1:
        printf("Insira o numero que quer cadastrar:\n");
        scanf("%d",&num);
        inserirPilha(p,num);
        break;
    case 2:
        imprimePar(p);
        break;
    case 3:
        printf("\n-----Elementos da pilha-----\n");
        imprimePilha(p);
        removedaPilha(p);
        break;
    case 4:
        printf("Saindo do programa...\n");
        break;
    default:
        printf("Opcao invalida! Escolha outra opcao!!!\n");
        break;
    }
    }
    
    return 0;
}