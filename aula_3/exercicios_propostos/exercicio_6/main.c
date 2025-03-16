#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int valpre(char *e) {
    Pilha P = pilha(256);
    int len = strlen(e);


    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(e[i])) {
            empilha(e[i] - '0', P); 
        } 
        else if (strchr("+-*/", e[i])) {
            int op1 = desempilha(P);
            int op2 = desempilha(P);
            
            
            switch (e[i]) {
                case '+': empilha(op1 + op2, P); break;
                case '-': empilha(op1 - op2, P); break;
                case '*': empilha(op1 * op2, P); break;
                case '/': empilha(op1 / op2, P); break;
            }
        }
    }

    int resultado = desempilha(P);
    destroip(&P);
    return resultado;
}

int main() {
    char e[513];

    printf("Expressão Prefixa: ");
    fgets(e, 513, stdin);
    e[strcspn(e, "\n")] = '\0'; 

    printf("Valor da Expressão: %d\n", valpre(e));

    return 0;
}
