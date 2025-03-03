#include <stdio.h>
#include "pilha.h"

// Ordenação crescente

/*Crie um programa que usa duas pilhas A e B para ordenar uma sequencia de n números dados pelo usuário. A ideia é organizar a pilha A de modo que nenhum item seja empilhado sobre outro menor (use a pilha B apenas para manobra) e, depois, descarregar e exibir os itens da pilha A.*/

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

       
        while (!vaziap(p1) && topo(p1) < temp) {
            empilha(topo(p1), p2);  
            desempilha(p1);  
        }

      
        empilha(temp, p1);
    }

    
    printf("Numeros ordenados: ");
    while (!vaziap(p1)) {
        printf("%d ", topo(p1));  
        desempilha(p1); 
    }

    return 0;
}
