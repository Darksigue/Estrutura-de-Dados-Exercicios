#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.h"
int main(void)
{
    int n;
    char s[200];

    printf("Cadeia de Simbolos:\n");
    scanf("%s", s);

    n = strlen(s);

    Pilha p = pilha(n);
    Pilha aux = pilha(n);

    int i = 0;

    while (i < n)
    {
        empilha(s[i], p);
        i++;
    }

    if (verifica_balanceamento(p, aux))
    {
        printf("A expressao esta balanceada!");
    }
    else
    {
        printf("A expressao nao esta balanceada!");
    }
    return 0;
}

int verifica_balanceamento(Pilha p, Pilha aux)
{
    while (!vaziap(p))
    {
        if (topo(p) == '}' || topo(p) == ')' || topo(p) == ']')
        {
            empilha(desempilha(p), aux);
        }
        else if (!vaziap(aux))
        {
            if (topo(p) == '[')
            {
                if (topo(aux) != ']')
                {
                    return false;
                }
                desempilha(aux);
                desempilha(p);
            }
            else if (topo(p) == '{')
            {
                if (topo(aux) != '}')
                {
                    return false;
                }
                desempilha(aux);
                desempilha(p);
            }
            else if (topo(p) == '(')
            {
                if (topo(aux) != ')')
                {
                    return false;
                }
                desempilha(aux);
                desempilha(p);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}