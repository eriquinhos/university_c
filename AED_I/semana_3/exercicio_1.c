// Eric Victor - 148000

// Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
// e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
// programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
// finalizar o programa, deve-se liberar a área de memória alocada.

#include <stdio.h>
#include <stdlib.h>


void leiaVetor(int*, int);


int main(){
    int tam, *v, i;

    printf("Tamanho do Vetor: ");
    scanf("%i", &tam);
  
    v = (int*) malloc(tam * sizeof(int));
  
    leiaVetor(v, tam);
  
    for(i=0; i<tam; i++){
        printf("%i\t", v[i]);
    }

    free(v);
    return 0;
}


void leiaVetor(int* v, int tam){
    int i;
  
    for(i=0; i<tam; i++){
        printf("%d º elemento: ", i+1);
        scanf("%d", &v[i]);
    }
}
