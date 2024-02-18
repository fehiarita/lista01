#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// fila

typedef struct Tipo{
    char tipo[2];
    int imposto;
    struct Tipo *prox;
}Tipo;

typedef struct Produto{     
    char tipo[2];
    int ID;
    float preco;
    struct Produto *prox;
}Produto; 
typedef struct Fila{
    struct Produto *inicio;     
    struct Produto *fim;
    struct Tipo *iniciot;
    struct Tipo *fimt;
    int tamanho;
}Fila;


void imprimetipo(Fila *fila){
    if (fila->iniciot == NULL)
    {
        printf("Fila vazia!\n");
        return;
    }else
    {
        Tipo *auxi = fila->iniciot;
        while (auxi != NULL)
        {
            printf("TIPO: %s\n",auxi->tipo);
            printf("IMPOSTO: %d\n",auxi->imposto);
            auxi = auxi->prox;
        }
        
    }
    
    
}
void insereTipo(Fila *fila, char tipo[2], int imposto){
    Tipo *novo =(Tipo*) malloc(sizeof(Tipo));
    if (novo == NULL)
    {
        printf("Falha em alocar memoria!\n");
        return;
    }
    
    strncpy(novo->tipo,tipo,sizeof(novo->tipo) - 1);
    novo->tipo[sizeof(novo->tipo) - 1] = '\0';


    novo->imposto = imposto;
    novo->prox = NULL;

    if (fila->iniciot == NULL)
    {
        fila->iniciot = novo;
        fila->fimt = novo;
    }else{
        fila->fimt->prox = novo;
        fila->fimt = novo;
    }

    printf("TIPO: %s\n",novo->tipo);
    printf("IMPOSTO: %d\n",novo->imposto);
    printf("Tipo cadastrado com sucesso!\n");
}

void insereProduto(Fila *filap, Fila *filat,  char tip[20],float preco){
    Produto *novo =(Produto*) malloc(sizeof(Produto));

    if (novo == NULL)
    {
        printf("Falha em alocar memoria!\n");
        return;
    }

    Tipo *auxi = filat->iniciot;
    int encontratipo = 0;
    while (auxi != NULL)
    {
        if (strcmp(auxi->tipo,tip) == 0)
        {
            encontratipo = 1;
            strncpy(novo->tipo, tip, sizeof(novo->tipo) - 1);
            novo->tipo[sizeof(novo->tipo) - 1] = '\0';
            break;
        }
        auxi = auxi->prox;
    }
    if (!encontratipo)
    {
        printf("Tipo nao encontrado!\n");
        free(novo);
        return;
    }
    
    novo->ID = filap->tamanho + 1;
    novo->preco = preco;
    novo->prox = NULL;

    if (filap->inicio == NULL)
    {
        filap->inicio = novo;
        filap->fim = novo;
    }else
    {
        filap->fim->prox = novo;
        filap->fim = novo;
    }
    
    filap->tamanho++;
    printf("ID: %d\n",novo->ID);
    printf("TIPO: %s\n",novo->tipo);
    printf("PRECO: %.2f\n",novo->preco);
    printf("Produto cadastrado com sucesso!\n");
}
Fila *criaFila(){
    Fila *fila =(Fila*) malloc(sizeof(Fila));
    if (fila != NULL)
    {
        fila->fim = NULL;
        fila->inicio = NULL;
    }
    return fila;
}

void consultaprecoproduto(Fila *filap, Fila *filat, int ID){
    if (filap->inicio == NULL)
    {
        printf("Fila vazia!\n");
        return;
    }
    
    //declarando ponteiro auxiliar
    Produto *atual = filap->inicio;
    while (atual != NULL)
    {
        if (atual->ID == ID)//verificando quando o ID é compativel 
        {
            Tipo *auxi = filat->iniciot;//outro ponteiro auxiliar para percorrer os tipos
            float percentual = 0.0;// vai armazenar o percentual do produto
            while (auxi != NULL)
            {
                if (strcmp(auxi->tipo,atual->tipo) == 0)
                {
                    percentual = auxi->imposto;
                    break;
                }
                auxi = auxi->prox;
            }
            if (percentual == 0.0)
            {
                printf("Percentual de imposto nao encontrado!\n");
            }
            
            float precocalculado = atual->preco - (atual->preco * percentual/ 100.0);
            printf("PRECO: %.2f\n", precocalculado);
            return;
        }
        atual = atual->prox;
    }
    printf("Produto nao escontrado!\n");
}

void excluirtipo(Fila *fila, char tipo[2]){
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!!\n");
    }else{
//      ponteiros auxiliares para percorrer a fila
        Produto *atual = fila->inicio;
        Produto *antes = NULL;

        while (atual != NULL)
        {
            if (strcmp(atual->tipo,tipo) == 0)// comparar para ver se existe o tipo
            {
                printf("Produto do tipo %s e ID %d a ser excluido!!\n",atual->tipo,atual->ID);

                if (antes == NULL)
                {
                    fila->inicio = atual->prox;
                    printf("Produto removido do inicio!\n");
                }else
                {
                    antes->prox = atual->prox;
                    printf("Produto removido da fila!\n");
                }
                free(atual);
                atual = fila->inicio;
            }else{
                antes = atual;
                atual = atual->prox;
            }
        }
    
    }
}
int main(){
    Fila *tipo = criaFila();
    Fila *produto = criaFila();

    int escolha = 0;
    char no[20];
    int impo = 0;
    char no2[20];
    float preco = 0.0;
    int id = 0;
    char no3[20];

    Tipo *auxit = tipo->iniciot;
    Produto *auxip = produto->inicio;

    while (1)
    {
    printf("\n-----MENU DE OPCOES-----\n");
    printf("[1] Cadastrar tipo\n");
    printf("[2] cadastrar produto\n");
    printf("[3] Consultar preco de um produto\n");
    printf("[4] Excluir tipo\n");
    printf("[5] Sair\n");
    scanf("%d",&escolha);

    switch (escolha)
    {
    case 1:
        printf("Digite o tipo do produto:\n");
        scanf("%s",no);
        printf("Digite o imposto desse tipo:\n");
        scanf("%d",&impo);
        insereTipo(tipo,no,impo);
        break;
    case 2:
        imprimetipo(tipo);
        printf("Digite o tipo que prefere:\n");
        scanf("%s",no2);
        printf("Digite o preco do produto:\n");
        scanf("%f",&preco);
        insereProduto(produto,tipo,no2,preco);
        break;
    case 3:
        printf("Produtos disponiveis:\n");
            Produto *auxip = produto->inicio;
            while (auxip != NULL) {
                printf("ID: %d\n", auxip->ID);
                auxip = auxip->prox;
            }
        printf("Digite o ID do produto que quer consultar:\n");
        scanf("%d",&id);
        consultaprecoproduto(produto,tipo,id);
        break;

    case 4:
        printf("Tipos disponiveis:\n");
        imprimetipo(tipo);
        printf("Digite tipo do produto que quer excluir:\n");
        scanf("%s",no3);
        excluirtipo(tipo,no3);
    case 5:
        printf("Saindo do programa...\n");
        exit(0);
        break;
    default:
        printf("Opcao invalida\n");
        break;
    }
    }
    free(tipo);
    free(produto);

    return 0;
}