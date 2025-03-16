#include <stdio.h>
#include "pilha.h"
#include <string.h>
#include <ctype.h>

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

double avaliarPosfixa(char *exp) {
    Pilha P = pilha(256);
    char *token = strtok(exp, " ");

    while (token) {
        if (isdigit(token[0])) {
            empilha(atof(token), P);
        } 
        else {
            double b = desempilha(P);
            double a = desempilha(P);

            switch (token[0]) {
                case '+': empilha(a + b, P); break;
                case '-': empilha(a - b, P); break;
                case '*': empilha(a * b, P); break;
                case '/': empilha(a / b, P); break;
            }
        }
        token = strtok(NULL, " ");
    }

    double resultado = desempilha(P);
    destroip(&P);
    return resultado;
}

int main() {
    char e[513];

    printf("Infixa: ");
    fgets(e, sizeof(e), stdin);
    e[strcspn(e, "\n")] = '\0'; 

    char posf[256];
    strcpy(posf, posfixa(e)); 
    printf("Posfixa: %s\n", posf);

    double resultado = avaliarPosfixa(posf);
    printf("Resultado: %.2f\n", resultado);

    return 0;
}