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
    }
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for(int i = 0; e[i]; i++) {
        if (e[i] == '(') {
            empilha('(', P);
        } 
        else if (isdigit(e[i])) {
            s[j++] = e[i];
        } 
        else if (strchr("+-/*", e[i])) {
            while (!vaziap(P) && prio(topo(P)) >= prio(e[i])) {
                s[j++] = desempilha(P);
            }
            empilha(e[i], P);
        } 
        else if (e[i] == ')') {
            while (topo(P) != '(') {
                s[j++] = desempilha(P);
            }
            desempilha(P);
        }
    }

    while (!vaziap(P)) {
        s[j++] = desempilha(P);
    }

    s[j] = '\0';
    destroip(&P);
    return s;
}

int main() {
    char text[256];

    printf("Conversão de infixa para pós-fixa\n");
    printf("Digite a expressão infixa: ");
    
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 

    printf("Expressão pós-fixa: %s\n", posfixa(text));

    return 0;
}
