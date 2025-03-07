#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int topo = -1;
int pilha[MAX];

void push(int i) {
    pilha[++topo] = i;
}

int pop() {
    return pilha[topo--];
}

int stacktop() {
    return pilha[topo];
}

bool empty() {
    return topo == -1;
}

bool full() {
    return topo == MAX - 1;
}

int main() {
    int i = 10;
    while (!full()) {
        push(i);
        i += 5;
    }
    while (!empty()) {
        printf("%d\n", pop());
    }
    return 0;
}
