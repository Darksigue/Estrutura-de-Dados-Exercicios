#include <stdio.h>
#include <math.h>

int main(){

    float peso, altura, indice;

    printf("Peso e altura: ");

    scanf("%f %f", &peso, &altura);

    indice = peso / pow(altura, 2);

    printf("IMC = %.2f\n", indice);

    if(indice < 18.5) printf("Magra");

    else if(indice > 30) printf("Obesa");

    else printf("Normal");


    return 0;
}