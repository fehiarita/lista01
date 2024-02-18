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

// ponteiro auxiliar 
Elemento *auxi;

Pilha *criaPilha(){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha != NULL){
        pilha->topo = NULL;
    }
    return pilha;
}

void inserirElemento(Pilha *pilha,int dado){
    Elemento *novo =(Elemento*) malloc(sizeof(Elemento));

    novo->dado = dado;
// para o novo dado da pilha apontar para o topo dela 
    novo->prox = pilha->topo;

    pilha->topo = novo;

    printf("Numero inserido na pilha!\n");
    getch();
}
void transferirPilha(Pilha *P1, Pilha *P2){
    if (P1->topo == NULL)
    {
        printf("Pilha vazia!\n");
        return;
    }
    auxi = P1->topo;
    while (auxi != NULL)
    {
        inserirElemento(P2,auxi->dado);
        auxi = auxi->prox;
    }
    
    
}

void liberarPilha(Pilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("\nPilha vazia!");
    }else{
        auxi = pilha->topo;
        do
        {
            pilha->topo = pilha->topo->prox;
            free(auxi);
            auxi = pilha->topo;
        } while (auxi != NULL);
        printf("\nPilha esvaziada com sucesso!");
        
    }
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
            printf("%d",auxi->dado);
            auxi = auxi->prox;
        } while (auxi != NULL);
        getch();
    }
}

void retornaImpar(Pilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("Pilha vazia!\n");
        return;
    }
    auxi = pilha->topo;
    while (auxi != NULL)
    {
        if (auxi->dado % 2 != 0)
        {
            printf("%d\n",auxi->dado);
        }
        auxi = auxi->prox;
    }
  
}

void retornaPar(Pilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("Pilha vazia!\n");
    }
    auxi = pilha->topo;
    while(auxi != NULL){
        if (auxi->dado % 2 == 0)
        {
            printf("%d\n", auxi->dado);
        }
        auxi = auxi->prox;
    }
    
}



int maiordaPilha(Pilha *pilha){
    int maior = 0;
    if (pilha->topo == NULL){
        printf("Pilha vazia!\n");
        
    }else{
        auxi = pilha->topo;
        maior = auxi->dado;
        while (auxi != NULL)
        {
            if (auxi->dado > maior)
            {
                maior = auxi->dado;
            }
            auxi = auxi->prox;
        }
        
    }

    return maior;
}

int menordaPilha(Pilha *pilha){
    int menor = 0;
    if (pilha->topo == NULL)
    {
        printf("Pilha vazia!\n");
    }
    
    auxi = pilha->topo;
    menor = auxi->dado;
    while (auxi != NULL)
    {
        if (auxi->dado < menor)
        {
            menor = auxi->dado;
        }
        auxi = auxi->prox;
    }
    return menor;
}
int pilha_vazia(Pilha *p) {
    if (p->topo == -1) {
        return 1; // pilha vazia
    } else {
        return 0; // pilha não vazia
    }
}


float mediaPilha(Pilha *pilha){
    float soma = 0;
    float media = 0.0;
    int contador = 0;
    if (pilha_vazia(pilha))
    {
        printf("Pilha vazia!\n");
        return 0.0;
    }
    Elemento *auxi = pilha->topo;
   while (auxi != NULL)
   {
    soma += auxi->dado;
    contador++;
    auxi = auxi->prox;
    
   }
   media = soma/contador;
   printf("%.2f",media);
   return media;
    
}


int compararPilhas(Pilha *P1,Pilha *P2){
    // dois ponteiros para percorrer as duas pilhas 
    Elemento *agoraP1 = P1->topo;
    Elemento *agoraP2 = P2->topo;

    while (agoraP1 != NULL && agoraP2 != NULL)
    {
        if (agoraP1->dado != agoraP2->dado)
        {
            // pilhas diferentes 
            return 0;
        }
        agoraP1 = agoraP1->prox;
        agoraP2 = agoraP2->prox;
    }
    // para saber se uma pilha é maior que a outra
    if (agoraP1 != NULL && agoraP2 == NULL)
    {
        return 1;
    }else if (agoraP1 == NULL && agoraP2 != NULL)
    {
        return -1;
    }else{
        // pilhas iguais 
        return 0;
    }
    
}

int main() {
    Pilha *P1 = criaPilha();
    Pilha *P2 = criaPilha();
    int escolha = 0;
    int resultado = 0;

    inserirElemento(P1,7);
    inserirElemento(P1,5);
    inserirElemento(P1,5);
    inserirElemento(P1,10);
    inserirElemento(P1,10);

    inserirElemento(P2,4);    
    inserirElemento(P2,7);    
    inserirElemento(P2,56);    
    inserirElemento(P2,34);    
    inserirElemento(P2,8);

    while (1) {
        printf("\n-------- MENU DE OPCOES --------\n");
        printf("\n[1] igualdade das pilhas\n");
        printf("[2] maior da pilha 1\n");
        printf("[3] maior da pilha 2\n");
        printf("[4] menor da pilha 1\n");
        printf("[5] menor da pilha 2\n");
        printf("[6] media dos elementos da pilha 1\n");
        printf("[7] media dos elementos da pilha 2\n");
        printf("[8] transferir P1 para P2\n");
        printf("[9] elementos ímpares da pilha 1\n");
        printf("[10] elementos ímpares da pilha 2\n");
        printf("[11] elementos pares da pilha 1\n");
        printf("[12] elementos pares da pilha 2\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 0:
                liberarPilha(P1);
                liberarPilha(P2);
                return 0;
            case 1:
                resultado = compararPilhas(P1,P2);
                if (resultado == 1) {
                    printf("A pilha P1 eh maior que a pilha P2");
                } else if (resultado == -1) {
                    printf("A pilha P2 eh maior que a pilha P1");
                } else {
                    printf("as pilhas sao iguais");
                }
                break;
            case 2:
                printf("%d",maiordaPilha(P1));
                break;
            case 3:
                printf("%d",maiordaPilha(P2));
                break;
            case 4:
                printf("%d",menordaPilha(P1));
                break;
            case 5:
                printf("%d",menordaPilha(P2));
                break;
            case 6:
                mediaPilha(P1);
                // printf("%.2f\n",mediaPilha(P1));
                break;
            case 7:
                mediaPilha(P2);
                break;
            case 8:
                transferirPilha(P1,P2);
                break;
            case 9:
                retornaImpar(P1);
                break;
            case 10:
                retornaImpar(P2);
                break;
            case 11:
                retornaPar(P1);
                break;
            case 12:
                retornaPar(P2);
                break;
            default:
                printf("Opção invalida! Por favor, escolha outra opcao\n");
        }
        // Limpa o buffer de entrada
        while (getchar() != '\n');
    }

    return 0;
}

    




