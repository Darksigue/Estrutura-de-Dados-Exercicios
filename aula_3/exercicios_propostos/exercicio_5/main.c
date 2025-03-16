#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

int prio(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void strrev_custom(char *str) {
    int i, j;
    char temp;
    int len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

char *prefixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);
    
    strrev_custom(e);

    for (int i = 0; e[i]; i++) {
        if (e[i] == ')') {
            empilha(')', P);
        } 
        else if (isdigit(e[i])) {
            s[j++] = e[i];
        } 
        else if (strchr("+-/*", e[i])) {
            while (!vaziap(P) && prio(topo(P)) > prio(e[i])) {
                s[j++] = desempilha(P);
            }
            empilha(e[i], P);
        } 
        else if (e[i] == '(') {
            while (topo(P) != ')') {
                s[j++] = desempilha(P);
            }
            desempilha(P); 
        }
    }

    while (!vaziap(P)) {
        s[j++] = desempilha(P);
    }

    s[j] = '\0';
    
    strrev_custom(s);
    
    destroip(&P);
    return s;
}


int main() {
    char e[513];

    printf("Infixa: ");
    fgets(e, 513, stdin);
    e[strcspn(e, "\n")] = '\0'; 

    printf("Prefixa: %s\n", prefixa(e));

    return 0;
}
