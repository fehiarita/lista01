#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

//Pilha
typedef struct Aluno{
    int ID;
    char nome[50];
    struct Aluno *prox;
}Aluno;

typedef struct Pilha{
    Aluno *topo;
    int tamanho;
}Pilha;

Aluno *auxia;

Pilha *criaPilha(){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

void inseriraluno(Pilha *pilha,char nome[50]){
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));

    if (novo == NULL)
    {
        printf("Erro de alocacao de memoria para o aluno novo\n");
        return;
    }
    
    novo->ID = pilha->tamanho + 1;
    strcpy(novo->nome,nome);
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
    printf("Aluno inserido com sucesso!!\n");
    printf("ID: %d\n", novo->ID);
    printf("Nome: %s\n", novo->nome);
}

bool verificaAluno(Pilha *pilha,int ID){
    Aluno *atual = pilha->topo;
     while (atual != NULL) {
        if (atual->ID == ID) {
            return true; // O aluno está cadastrado
        }
        atual = atual->prox;
    }

    return false; // O aluno não está cadastrado
}

void imprimeAlunos(Pilha *pilha){
    Aluno *atual = pilha->topo;
    printf("\n-----Alunos Cadastrados-----\n");
    while (atual != NULL)
    {
        printf("ID: %d\n",atual->ID);
        printf("Nome: %s\n",atual->nome);
        atual = atual->prox;
    }
    
}


// fila

typedef struct Nota{
    int ID;
    float valor;
    struct Nota *prox;
}Nota;

typedef struct Fila{
    struct Nota *inicio;
    struct Nota *fim;
}Fila;

Nota *auxin;

Fila *criarFila(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if (fila != NULL)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
    
}

void insereNota(Fila *fila,Pilha *pilha,int numeroaluno,float nota){
    if (!verificaAluno(pilha,numeroaluno))
    {
        printf("\nAluno não cadastrado!\n");
        getch();
        return;
    }
    // alocando memoria para a nota
    Nota *notanova = (Nota*) malloc(sizeof(Nota));

    if (notanova == NULL)
    {
        printf("Erro em alocar a memoria para inserir a nota!\n");
        return;
        
    }
    // preencher os dados da nova nota
        notanova->ID = numeroaluno;
        notanova->valor = nota;
        notanova->prox = NULL;

        if (fila->inicio == NULL)
        {
            fila->inicio = notanova;
        }else
        {// adiconar na fila quando ela ja tem alguma nota 
            fila->fim->prox = notanova;
        }
        fila->fim = notanova;
        printf("ID: %d\n",notanova->ID);
        printf("NOTA: %.2f\n",notanova->valor);
    
}
void removeAluno(Pilha *pilha,Fila *fila) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    int id = 0;
    printf("Digite o ID do aluno que quer remover:\n");
    scanf("%d",&id);

    Aluno *atual = pilha->topo;
    Aluno *anterior = NULL;

    while (atual != NULL && atual->ID != id) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("ID nao encontrado na pilha!\n");
        return;
    }

    auxin = fila->inicio;
    while (auxin != NULL && auxin->ID != (float)id)
    {
        auxin = auxin->prox;
    }
    if (auxin == NULL)
    {
        printf("Nao existe nenhuma nota associada ao aluno de ID %d\n nao pode ser removido!\n",atual->ID);
        return;
    }
    
    if (anterior == NULL) {
        pilha->topo = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    printf("Aluno de ID %d removido com sucesso!\n", atual->ID);
    free(atual);
}

void imprimeNotas(Fila *fila){
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!!\n");
        return;
    }else
    {
        auxin = fila->inicio;
        while (auxin != NULL)
        {
            printf("ID: %d\n",auxin->ID);
            printf("Nota: %.2f\n",auxin->valor);
            auxin = auxin->prox;
        }
        
    }
}

void removeNota(Fila *fila){
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!\n");
        return;
    }
    imprimeNotas(fila);
    float NOTA = 0.0;
    printf("Digite a nota que quer remover:\n");
    scanf("%f",&NOTA);

    auxin = fila->inicio;
    Nota *antes = NULL;
    while (auxin != NULL)
    {
        if (auxin->valor == NOTA)
        {
            if (antes == NULL)
            {
                fila->inicio = auxin->prox;
                free(auxin);
                printf("Nota %.2f removida com sucesso!\n",NOTA);
                return;
            }else
            {
                antes->prox = auxin->prox;
                free(auxin);
                printf("Nota %.2f removida com sucesso!\n",NOTA);
                return;
            }
        }
        
    antes = auxin;
    auxin = auxin->prox;
    } 
    printf("Nota %.2f não encontrada na fila.\n", NOTA);   
}
void imprimesemNota(Fila *fila,Pilha *pilha){
    Aluno *atual = pilha->topo;
    bool simnota;
    printf("\n-----Alunos sem Nota-----\n");
    if (atual != NULL)
    {
        simnota = false;
        Nota *notaatual = fila->inicio;

        while (notaatual != NULL)
        {
            if (notaatual->ID == atual->ID)
            {
                simnota = true;//porque o aluno tem nota
                break;
            }
            notaatual = notaatual->prox;
        }
        
        if (!simnota)
        {
            printf("%s\n",atual->nome);
        }
        atual = atual->prox;
    }
    
    
    
}
int mediaNotas(Fila *fila,int id){
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!!\n");
    }
    float soma = 0.0;
    int cont = 0;
    Nota *atual = fila->inicio;
    while (atual != NULL)
    {
        if (atual->ID == id)
        {
            soma += atual->valor;
            cont++;
        }
        atual = atual->prox;
    }
    if (cont == 0)
    {
        printf("Não foi encontrada nenhuma nota no ID %d\n",id);
    }
    return soma / cont;
    
}
int main(){
    Pilha *alunos = criaPilha();
    Fila *notas = criarFila();
    int escolha = 0;
    char nome[50];
    int numaluno = 0;
    float notaaluno = 0.0;
    int id3 = 0;
    int media = 0;
    while (1)
    {
    printf("\n-------- MENU DE OPCOES --------\n");
    printf("[1] cadastrar aluno\n");
    printf("[2] cadastrar nota\n");
    printf("[3] Calcular a media de um aluno\n");
    printf("[4] listar os nomes dos alunos sem notas\n");
    printf("[5] excluir aluno\n");
    printf("[6] excluir nota\n");
    printf("[7] Sair\n");
    scanf("%d",&escolha);

    switch (escolha)
    {
    case 1:
        printf("Digite o nome do aluno:\n");
        fflush(stdin); // Limpa o buffer de entrada
        fgets(nome,sizeof(nome),stdin);
        inseriraluno(alunos,nome);
        break;
    case 2:
        imprimeAlunos(alunos);
        printf("Digite o ID do aluno que quer inserir a nota:\n");
        scanf("%d",&numaluno);
        printf("Digite a nota do aluno:\n");
        scanf("%f",&notaaluno);                  
        if (notaaluno < 0 || notaaluno > 10)
        {
            printf("Nota invalida![0-10]\n");
        }else
        {
        insereNota(notas,alunos,numaluno,notaaluno);
        }
        
        break;
    case 3:
        imprimeAlunos(alunos);
        printf("Digite o ID do aluno para saber a media:\n");
        scanf("%d",&id3);
        media = mediaNotas(notas,id3);
        printf("Media: %d\n",media);
        break;
    case 4:
        imprimesemNota(notas,alunos);
        break;
    case 5:
        imprimeAlunos(alunos);
        removeAluno(alunos,notas);
        break;
    case 6:
    removeNota(notas);
        break;
    case 7:
        printf("Saindo do menu...");
        break;
    default:
        printf("Opcao invalida! escolha uma nova opcao!!!!\n");
        break;
    }
        
    }
    
}