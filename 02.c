#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Elemento{
    int dado;
    struct Elemento *prox;
}Elemento;

typedef struct Fila{
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;

Elemento *auxi;

Fila *criar_fila(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if (fila != NULL)
    {
        fila->fim = NULL;
        fila->inicio = NULL;
    }
    return fila;
}

void insere_fila(Fila *fila, int dado){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->dado = dado;
    novo->prox = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = novo;
        fila->fim = novo;
    }else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    printf("\nNumero inserido na fila!");
    getch();
}

void consulta_fila(Fila *fila){
    if (fila->inicio == NULL)
    {
        printf("\nFila Vazia!");
    }else{
        auxi = fila->inicio;
        printf("%d removido!", fila->inicio->dado);
        fila->inicio = fila->inicio->prox;
        free(auxi);
    }
    getch();
}

void esvazia_fila(Fila *fila){
    if (fila->inicio == NULL)
    {
        printf("\nFila Vazia!");
    }else{
        auxi = fila->inicio;
        do
        {
            fila->inicio = fila->inicio->prox;
            free(auxi);
            auxi = fila->inicio;
        } while (auxi != NULL);
        printf("\n Fila esvaziada!");        
    }
    getch();
}

int compararFila(Fila *F1,Fila *F2){
    Elemento *agoraF1 = F1->inicio;
    Elemento *agoraF2 = F2->inicio;
    while (agoraF1 != NULL && agoraF2 != NULL)
    {
        if (agoraF1->dado != agoraF2->dado)
        {
            // filas diferentes 
            return 0;
        }
        agoraF1 = agoraF1->prox;
        agoraF2 = agoraF2->prox;
    }
    // para verificar se alguma fila ainda tem elementos 
    if (agoraF1 != NULL && agoraF2 == NULL)
    {
        return 1;//F1 tem mais que F2  
    }else if (agoraF1 == NULL && agoraF2 != NULL)
    {
       return -1; //F2 tem mais que F1
    }else{
        // filas iguais 
        return 0; 
    }
}
int maiordaFila(Fila *fila){
    int maior = auxi->dado;
    if (fila->inicio == NULL && fila->fim == NULL)
    {
        printf("Fila vazia!\n");
    }
    auxi = fila->inicio;
    while (auxi != NULL)
    {
        if (auxi->dado > maior)
        {
            maior = auxi->dado;
        }
        auxi = auxi->prox;
    }
    return maior;
    
}

int menordaFila(Fila *fila){
    int menor = auxi->dado;
    if (fila->inicio == NULL && fila->fim == NULL)
    {
       printf("Fila vazia!\n"); 
    }
    auxi = fila->inicio;
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
int filaVazia(Fila *fila){
    if (fila->inicio == NULL && fila->fim == NULL)
    {
        return 1;//fila vazia 
    }else{
        return 0;
    }
    
}
float mediaFila(Fila *fila){
    float soma = 0;
    float media = 0.0;
    int contador = 0;
    if (filaVazia(fila))
    {
        printf("Fila vazia!\n");
        return 0.0;
    }
    Elemento *auxi = fila->inicio;
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

void transferirFila(Fila *F1, Fila *F2){
    if (F1->inicio == NULL && F1->fim == NULL)
    {
       printf("Fila vazia!\n"); 
       return;
    }
    Elemento *auxi = F1->inicio;
    while (auxi != NULL)
    {
        insere_fila(F2,auxi->dado);
        printf("Elemento transferido: %d\n", auxi->dado);
        auxi = auxi->prox;
    }
    
}
void retornaImpar(Fila *fila){
    if (filaVazia(fila))
    {
        printf("Fila vazia!\n");
        return;
    }
    auxi = fila->inicio;
    while (auxi != NULL)
    {
        if (auxi->dado % 2 != 0)
        {
            printf("%d\n",auxi->dado);
        }
        auxi = auxi->prox;
    }
}
void retornaPar(Fila *fila){
    if (filaVazia(fila))
    {
        printf("Fila vazia!\n");
        return;
    }
    auxi = fila->inicio;
    while (auxi != NULL)
    {
        if (auxi->dado % 2 == 0)
        {
            printf("%d\n", auxi->dado);
        }
        auxi = auxi->prox;
    }
    
}
void esvaziaFila(Fila *fila){
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!!\n");
    }
    auxi = fila->inicio;
    while (auxi != NULL)
    {
        fila->inicio = fila->inicio->prox;
        free(auxi);
        auxi = fila->inicio;
    }
    printf("Fila esvaziada!!\n");
    getch();
}
int main(){
    Fila *F1 = criar_fila();
    Fila *F2 = criar_fila();
    int escolha = 0;
    int result = 0;
    insere_fila(F1,5);
    insere_fila(F1,6);
    insere_fila(F1,10);
    insere_fila(F1,20);

    insere_fila(F2,80);
    insere_fila(F2,20);
    insere_fila(F2,2);
    insere_fila(F2,4);


    while (1)
    {
        printf("\n-------- MENU DE OPCOES --------\n");
        printf("[1] igualdade das filas\n");
        printf("[2] maior da fila 1\n");
        printf("[3] maior da fila 2\n");
        printf("[4] menor da fila 1\n");
        printf("[5] menor da fila 2\n");
        printf("[6] media dos elementos da fila 1\n");
        printf("[7] media dos elementos da fila 2\n");
        printf("[8] transferir F1 para F2\n");
        printf("[9] elementos ímpares da fila 1\n");
        printf("[10] elementos ímpares da fila 2\n");
        printf("[11] elementos pares da fila 1\n");
        printf("[12] elementos pares da fila 2\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            esvazia_fila(F1);
            esvazia_fila(F2);
            break;
        case 1:
            result = compararFila(F1,F2);
            if (result == 0)
            {
                printf("As filas são iguais!\n");
            }else if (result == 1)
            {
                printf("A fila F1 é maior que a F2!\n");
            }else if (result == -1)
            {
                printf("A fila F2 é maior que a F1!\n");
            }
            break;
        case 2:
            printf("%d\n",maiordaFila(F1));
            break;
        case 3:
            printf("%d\n",maiordaFila(F2));
            break;
        case 4:
            printf("%d\n",menordaFila(F1));
            break;
        case 5:
            printf("%d\n",menordaFila(F2));
            break;
        case 6:
            mediaFila(F1);
            break;
        case 7:
            mediaFila(F2);
            break;
        case 8:
            transferirFila(F1,F2);
            break;
        case 9:
            retornaImpar(F1);
            break;
        case 10:
            retornaImpar(F2);
            break;
        case 11:
            retornaPar(F1);
            break;
        case 12:
            retornaPar(F2);
            break;
        default:
            break;
        }
    }
    
    return 0;
}