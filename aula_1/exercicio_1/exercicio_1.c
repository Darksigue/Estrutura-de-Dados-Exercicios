#include <stdio.h>
#include <math.h>

int main(){
    float peso, altura, indice;

    printf("Peso e Altura: ");

    scanf("%f %f", &peso, &altura);

    indice = peso / pow(altura, 2);

    printf("IMC = %.2f\n", indice);


    return 0;
}