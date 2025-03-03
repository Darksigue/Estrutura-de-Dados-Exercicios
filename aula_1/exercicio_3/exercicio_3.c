#include <stdio.h>

int main()
{
    int placa;

    printf("Placa: ");

    scanf("%d", &placa);

    switch (placa % 10)
    {
    case 1:
    case 2:
        printf("Segunda-feira");
        break;
    case 3:
    case 4:
        printf("Terca-feira");
        break;
    case 5:
    case 6:
        printf("Quarta-feira");
        break;
    case 7:
    case 8:
        printf("Quinta-feira");
        break;
    default:
        printf("Sexta-feira");
    }

    return 0;
}