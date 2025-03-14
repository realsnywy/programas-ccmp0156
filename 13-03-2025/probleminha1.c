//! Escreva um algoritmo para determinar se uma string é da forma: xCy
//! onde x é uma string com as letras A e B, e y é o inverso de x.
//! Por exemplo: Se x = ABAAB, então y = BAABA.
//! A string é ABAABCBAABA.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool valid = true;
    char str[] = "ABAABCBAABA";

    //* Informações sobre a string.
    printf("String a ser testada: %s\n", str);
    printf("Tamanho da string: %d\n", sizeof(str) - 1);

    //* Condição para verificar se a string é válida, com base no enunciado.
    if (str[(sizeof(str) - 1) / 2] != 'C' || (sizeof(str) - 1) % 2 == 0)
    {
        valid = false;
    }
    //* Início da verificação entre a primeira metade da string e a segunda metade.
    else
    {
        for (int i = 0; i < ((sizeof(str) - 1) / 2); i++)
        {
            printf("%c %c\n", str[i], str[sizeof(str) - 2 - i]);
            if (str[i] != str[sizeof(str) - 2 - i] || (str[i] != 'A' && str[i] != 'B') || (str[sizeof(str) - 2 - i] != 'A' && str[sizeof(str) - 2 - i] != 'B') || str[i] == 'C' || str[sizeof(str) - 2 - i] == 'C')
            {
                valid = false;
                break;
            }
        }
    }
    //* Retornar ao usuário a condição da string.
    printf("%s", valid ? "String válida!" : "String inválida!");
    return 0;
}