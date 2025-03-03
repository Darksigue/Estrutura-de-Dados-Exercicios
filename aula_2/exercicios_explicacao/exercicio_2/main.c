#include <stdio.h>
#include "pilha.h"

int main(){

    char c[513];

    Pilha P = pilha(513);

    printf("Cadeia: ");

    gets(c);

    for(int i = 0; c[i]; i++) {
        empilha(c[i],P);
        
    }
    
    while(!vaziap(P)) {

        printf("Inverso: \n");
        
        printf("%c", desempilha(P));
    
        puts("\n");
    }

    destroip(&P);

    return 0;
}