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

int main() {
    struct lista l1;
    int opcao;
    inicializaLista(&l1);
    do {
        printf("1 - Inicializa lista\n");
        printf("2 - Adiciona no inicio\n");
        printf("3 - Exibir lista\n");
        printf("4 - Sair\n");
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
                exibirLista(l1);
                break;
            }
        }
    }while(opcao != 4);



    return 0;
}