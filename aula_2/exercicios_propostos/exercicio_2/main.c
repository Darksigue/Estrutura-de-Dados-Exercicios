#include <stdio.h>
#include "pilha.h"

int main()
{
    int analysedNum;

    printf("Quantos numeros serao analisados? ");
    scanf("%d", &analysedNum);

    Pilha p1 = pilha(analysedNum); 
    Pilha p2 = pilha(analysedNum); 

    for(int i = 0; i < analysedNum; i++) {
        int num;
        
        printf("Qual e o %io numero analisado? ", i + 1);
        scanf("%d", &num);  
        empilha(num, p2); 
    }


    while (!vaziap(p2)) {
        int temp = topo(p2);
        desempilha(p2);  

        while (!vaziap(p1) && topo(p1) > temp) {
            empilha(topo(p1), p2);  
            desempilha(p1);
        }

        empilha(temp, p1);
    }

  
    while(!vaziap(p1)) {
        int temp_topo = topo(p1);
        desempilha(p1);

       
        if (!existe(temp_topo, p2)) {
            empilha(temp_topo, p2);
        }
    }

   
    printf("Numeros ordenados: ");
    while (!vaziap(p2)) {
        printf("%d ", topo(p2));  
        desempilha(p2); 
    }

    return 0;
}


int existe(int num, Pilha p2) {
    Pilha temp = pilha(10); 
    int found = 0;

    while (!vaziap(p2)) {
        int top = topo(p2);
        desempilha(p2);
        empilha(top, temp);

        if (top == num) {
            found = 1;
        }
    }


    while (!vaziap(temp)) {
        empilha(topo(temp), p2);
        desempilha(temp);
    }

    return found;
}
