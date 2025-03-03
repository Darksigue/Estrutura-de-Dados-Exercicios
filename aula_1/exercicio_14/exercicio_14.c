#include <stdio.h>
#include <stdlib.h>

float media(float valores[], int n);

int main(){
    int n;

    printf("Quantidade de numeros: ");
    scanf("%d", &n);

    float *v = malloc(n * sizeof(float));

    for(int i = 0; i < n; i++) {
        printf("%d o numero: ", i + 1);
        scanf("%f", &v[i]);
    }

    printf("Media: %.2f\n", media(v, n));


    return 0;
}

float media(float valores[], int n) {
    float soma = 0;

    for(int i = 0; i < n; i++) {
        soma += valores[i];
    }

    return soma / n;
}
