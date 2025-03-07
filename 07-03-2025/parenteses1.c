// Anotações para o programa 'parenteses1.c'

// Objetivo: Verificar se uma expressão possui algum erro de parenteses
// Explicação do Fucionamento: Verificaria-se char por char a existência de um parênteses dentro de uma expressão, adicionando/removendo 1 em um contador. Caso o contador devolver um valor diferente de 0, exisitiria um erro na expressão.

// Expressões para testar
// 2 / ((1 / a) + (1 / b))
// (a + b) + ) c
// (a + b) + ( c

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    bool valid = true;
    int counter = 0;
    char string[] = "2 / ((1 / a) + (1 / b))";
    for (int i = 0; string[i] != '\0' && valid; i++)
    {
        if (string[i] == '(')
            counter++;
        else if (string[i] == ')')
            counter--;
        if (counter < 0)
            valid = false;
    }
    printf("Contador: %d\n", counter);
    if (counter != 0)
        valid = false;
    if (valid)
        printf("Expressão perfeita, sem erros!\n");
    else
        printf("Há erros na expressão!\n");
    return 0;
}