#include <stdio.h>

int main(){

    printf("Fatorial de 7: %d", fat(7));

    return 0;
}

int fat(int num) {
    int f = 1;

    for(int i = 2; i < num; i ++) f*=i;

    return f;
}