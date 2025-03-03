#include <stdio.h>
#include "pilha.h"
#include <string.h>

//Palavra reversa

int main(){
    Pilha p1 = pilha(50);
    char name[50];

    printf("Entre com a palavra: ");
    gets(name);

    for(int i = 0; i < strlen(name); i ++) {
        empilha(name[i],p1);
    }

    while(!vaziap(p1)) {
        printf("%c", topo(p1));
        desempilha(p1);
    }

    destroip(&p1);

    return 0;
}