#include <stdio.h>
#include "pilha.h"
#include <string.h>

int main(){
    Pilha P = pilha(5);

    char s[11];

    for(int i = 0; i < 3; i++) {
        printf("? ");
        gets(s);
        empilha(_strdup(s), P);
    }


    while(!vaziap(P)) puts(desempilha(P));

    return 0;
}