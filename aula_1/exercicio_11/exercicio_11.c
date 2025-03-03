#include <stdio.h>

int main(){
    int var = 5;
    int *pointer;

    pointer = &var;

    *pointer = *pointer + 2;

    printf("var= %d, *pointer = %d \n", var, *pointer);

    return 0;
}