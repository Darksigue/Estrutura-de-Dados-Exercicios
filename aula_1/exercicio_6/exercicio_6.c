#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int chute, numero = rand()% 10 + 1;

    do{
        printf("Chute entre 1 e 10: ");

        scanf("%d", &chute);

        if(chute < numero) printf("Baixo\n");

        else if(chute > numero) printf("Alto\n");
    }while(numero != chute);

    printf("Acertou!");


    return 0;
}