#include <stdio.h>

int main(){

    int num;

    printf("Numero: ");

    scanf("%d", &num);

    printf("Fatorial: %d", fatorial(num));

    return 0;
}

int fatorial(int num) {

    if(num == 1 || num == 0) return 1;

    return num * fatorial(num-1);
}