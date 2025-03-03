#include <stdio.h>

int main(){

    int num;

    printf("Numero: ");

    scanf("%d", &num);

    int soma = 0;

    while(num > 0) {
        soma += num%10;
        num /= 10;
    }

    printf("Soma dos digitos: %d\n", soma);

    return 0;
}