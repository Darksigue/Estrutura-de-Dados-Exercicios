#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"


int prio(char op) {
    if (op == '!') return 3;
    if (op == '&') return 2;
    if (op == '|') return 1;
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
        else if (e[i] == 'V' || e[i] == 'F') {  
            s[j++] = e[i];
        } 
        else if (strchr("!&|", e[i])) { 
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


int avaliarPosfixa(char *exp) {
    Pilha P = pilha(256);

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == 'V') empilha(1, P);
        else if (exp[i] == 'F') empilha(0, P);
        else {
            if (exp[i] == '!') {
                int a = desempilha(P);
                empilha(!a, P);
            } 
            else {
                int b = desempilha(P);
                int a = desempilha(P);
                if (exp[i] == '&') empilha(a & b, P);
                else if (exp[i] == '|') empilha(a | b, P);
            }
        }
    }

    int resultado = desempilha(P);
    destroip(&P);
    return resultado;
}


int main() {
    char e[513];

    printf("Infixa: ");
    fgets(e, 513, stdin);
    e[strcspn(e, "\n")] = '\0'; 

    char *p = posfixa(e);
    printf("Posfixa: %s\n", p);
    printf("Resultado: %d\n", avaliarPosfixa(p));

    return 0;
}
