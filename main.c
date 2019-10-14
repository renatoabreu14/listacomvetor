#include <stdio.h>
#define TAM 10

struct lista{
    int lista[TAM];
    int ultimo;
};

void inicializaLista(struct lista *l){
    l->ultimo = -1;
}

int listaVazia(struct lista l){
    if (l.ultimo == -1){
        return 1;
    }
    return 0;
}

void adicionarNoInicio(struct lista *l, int valor){
    int i;
    if (listaVazia(*l)){
        l->ultimo++;
        l->lista[l->ultimo] = valor;
    }else{
        l->ultimo++;
        for (i = l->ultimo; i > 0 ; i--){
            l->lista[i] = l->lista[i-1];
        }
        l->lista[0] = valor;
    }
}

void adicionarNoFim(struct lista *l, int valor){
    l->ultimo++;
    l->lista[l->ultimo] = valor;
}

void removerNoFim(struct lista *l){
    if (!listaVazia(*l)) {
        l->lista[l->ultimo] = NULL;
        l->ultimo--;
    }else{
        printf("Lista vazia");
    }
}

void removerNoInicio(struct lista *l){
    int i;
    if (!listaVazia(*l)) {
        if (l->ultimo != 0) {
            for (i = 0; i < l->ultimo + 1; i++) {
                l->lista[i] = l->lista[i + 1];
            }
        }
        l->lista[l->ultimo] = NULL;
        l->ultimo--;
    }else{
        printf("Lista vazia");
    }
}

void exibirLista(struct lista l){
    if (listaVazia(l)){
        printf("Lista vazia");
    }else{
        int i;
        for (i = 0; i < l.ultimo+1; i++){
            printf("O %io valor da lista eh: %i\n", (i+1), l.lista[i]);
        }
    }
}

int buscaValor(struct lista l, int valor){
    int i;
    for(i = 0; i < l.ultimo+1; i++){
        if (l.lista[i] == valor){
            return i;
        }
    }
    return -1;
}

void removerPorPosicao(struct lista *l, int pos){
    int i;
    if (!listaVazia(*l)) {
        if (l->ultimo != 0) {
            for (i = pos; i < l->ultimo + 1; i++) {
                l->lista[i] = l->lista[i + 1];
            }
        }
        l->lista[l->ultimo] = NULL;
        l->ultimo--;
    }else{
        printf("Lista vazia");
    }
}

int main() {
    struct lista l1;
    int opcao;
    inicializaLista(&l1);
    do {
        printf("1 - Inicializa lista\n");
        printf("2 - Adiciona no inicio\n");
        printf("3 - Adiciona no fim\n");
        printf("4 - Remove no inicio\n");
        printf("5 - Remove no fim\n");
        printf("6 - Remove por busca\n");
        printf("7 - Exibir lista\n");
        printf("8 - Sair\n");
        printf("\nInforme a opcao desejada:");
        scanf("%i", &opcao);
        switch (opcao){
            case 1:{
                inicializaLista(&l1);
                break;
            }
            case 2:{
                int valor;
                printf("Informe o valor:");
                scanf("%i", &valor);
                adicionarNoInicio(&l1, valor);
                break;
            }
            case 3:{
                int valor;
                printf("Informe o valor:");
                scanf("%i", &valor);
                adicionarNoFim(&l1, valor);
                break;
            }
            case 4:{
                removerNoInicio(&l1);
                break;
            }
            case 5:{
                removerNoFim(&l1);
                break;
            }
            case 6:{
                int valor;
                printf("Informe o valor:");
                scanf("%i", &valor);
                int pos = buscaValor(l1, valor);
                if (pos == -1){
                    printf("Valor não encontrado");
                }else{
                    removerPorPosicao(&l1, pos);
                }
                break;
            }
            case 7:{
                exibirLista(l1);
                break;
            }
        }
    }while(opcao != 8);



    return 0;
}