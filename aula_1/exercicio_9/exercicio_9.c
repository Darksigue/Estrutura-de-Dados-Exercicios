#include <stdio.h>
#include <string.h>

int main(){

    char senha[256];

    printf("Senha: ");

    gets(senha);

    if(strcmp(senha, "abracadabra") == 0) printf("OK");
    else printf("Senha invalida");

    return 0;
}