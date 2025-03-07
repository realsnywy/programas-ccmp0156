#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definição da estrutura da pilha
typedef struct {
    int topo;
    int size;
    int *pilha;
} Stack;

// Aloca memória para a pilha e inicializa os valores
Stack* stk_alloc(int size) {
    Stack *s1 = malloc(sizeof(Stack));
    if (s1) {
        s1->topo = -1;
        s1->size = size;
        s1->pilha = malloc(size * sizeof(int));
        if (!s1->pilha) {
            free(s1);
            return NULL;
        }
    }
    return s1;
}

// Libera a memória da pilha
void stk_free(Stack *s1) {
    free(s1->pilha);
    free(s1);
}

// Verifica se a pilha está vazia
bool stk_empty(Stack *s1) {
    return s1->topo == -1;
}

// Verifica se a pilha está cheia
bool stk_full(Stack *s1) {
    return s1->topo == s1->size - 1;
}

// Empilha um elemento
void stk_push(Stack *s1, int i) {
    s1->pilha[++s1->topo] = i;
}

// Desempilha um elemento
int stk_pop(Stack *s1) {
    return s1->pilha[s1->topo--];
}

// Retorna o elemento do topo sem remover
int stk_top(Stack *s1) {
    return s1->pilha[s1->topo];
}

// Função principal para testar a pilha
int main() {
    Stack *s1 = stk_alloc(5);
    int i = 10;

    while (!stk_full(s1)) {
        stk_push(s1, i);
        i += 5;
    }

    while (!stk_empty(s1)) {
        printf("%d\n", stk_pop(s1));
    }

    stk_free(s1);
    return 0;
}
