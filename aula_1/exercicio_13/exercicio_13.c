#include <stdio.h>

int main(){

    int a = 5;
    int b = 3;

    trocar(&a, &b);

    printf("%d\n", a);

    printf("%d\n", b);

    return 0;
}

int trocar(int *a, int *b) {
    int c = *a;

    *a = *b;

    *b = c;
}