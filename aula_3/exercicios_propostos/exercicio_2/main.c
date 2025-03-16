#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prio(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for (int i = 0; e[i]; i++) {
        if (e[i] == '(') {
            empilha('(', P);
        } 
        else if (isdigit(e[i])) {  
            s[j++] = e[i];
            if (!isdigit(e[i + 1])) s[j++] = ' '; 
        } 
        else if (strchr("+-/*", e[i])) { 
            while (!vaziap(P) && prio(topo(P)) >= prio(e[i])) {
                s[j++] = desempilha(P);
                s[j++] = ' ';
            }
            empilha(e[i], P);
        } 
        else if (e[i] == ')') {
            while (topo(P) != '(') {
                s[j++] = desempilha(P);
                s[j++] = ' ';
            }
            desempilha(P); 
        }
    }

    while (!vaziap(P)) {
        s[j++] = desempilha(P);
        s[j++] = ' ';
    }
    
    s[j] = '\0';

    destroip(&P);
    return s;
}

int main() {
    char e[513];

    printf("Infixa: ");
    gets(e);
    e[strcspn(e, "\n")] = '\0';

    printf("Posfixa: %s\n", posfixa(e));

    return 0;
}
