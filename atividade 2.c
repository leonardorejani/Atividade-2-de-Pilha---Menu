#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 5

int stack[TAMANHO];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == TAMANHO - 1;
}

void push(int data) {
    if (isFull()) {
        printf("Pilha cheia!\n");
        return;
    }
    stack[++top] = data;
    printf("Valor %d empilhado com sucesso!\n", data);
}

int pop() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return -1;
    }
    int temp = stack[top--];
    return temp;
}

void imprime_pilha() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Pilha: ");
    for (int i = 0; i <= top; i++) {
        printf("%d -> ", stack[i]);
    }
    printf("topo\n");
}

void ver_topo() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Topo da pilha: %d\n", stack[top]);
}

int main() {
    int opcao, valor;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1. Empilhar (push)\n");
        printf("2. Desempilhar (pop)\n");
        printf("3. Imprimir pilha\n");
        printf("4. Ver topo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Informe um valor para empilhar: ");
                scanf("%d", &valor);
                push(valor);
                break;
            case 2:
                valor = pop();
                if (valor != -1)
                    printf("Valor desempilhado: %d\n", valor);
                break;
            case 3:
                imprime_pilha();
                break;
            case 4:
                ver_topo();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
