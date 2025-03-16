#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"


int prio(char o) {
    switch (o) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return -1;
    }
}

int valor(char *e) {
    Pilha P = pilha(256);

    for (int i = 0; e[i]; i++) {
        if (isdigit(e[i])) {
            empilha(e[i] - '0', P);
        } else {
            int y = desempilha(P); 
            int x = desempilha(P);

            switch (e[i]) {
                case '+': empilha(x + y, P); break;
                case '-': empilha(x - y, P); break;
                case '*': empilha(x * y, P); break;
                case '/': empilha(x / y, P); break;
                default: break;  
            }
        }
    }

    int z = desempilha(P);
    destroip(&P);  

    return z;
}

int main() {
    char expressao[] = "53+82-*";  
    int resultado = valor(expressao);
    printf("Resultado da expressao posfixa %s: %d\n", expressao, resultado);
    return 0;
}
