#include <stdio.h>
#include "pilha.h"

int main(){
    Pilha P = pilha(5);

    char s[11];

    for(int i = 0; i < 3; i++) {
        printf("? ");
        gets(s);
        empilha(s, P);
    }

    while(!vaziap(P)) puts(desempilha(P));

    return 0;
}

//O Código retorna tres, tres, tres. Pois a função empilhada está apontando para o mesmo endereço de memória durante o retorno com o desempilha, portanto o retorno será o mesmo.