// Eric Victor - 148000

// Faça uma função que receba um valor n e crie dinamicamente um vetor de n
// elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
// vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
// função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
// crie uma função principal que leia um valor n e chame a função criada acima. Depois,
// a função principal deve ler os n elementos desse vetor. Então, a função principal deve
// chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
// memória alocada através da função criada para liberação.

#include <stdio.h>
#include <stdlib.h>


int* criaVetor(int);


void imprimeVetor(int*, int);


void liberaVetor(int*);


int main(){
    int n, *v, i;

    printf("N: ");
    scanf("%d", &n);

    v = criaVetor(n);

    for(i=0; i<n; i++){
        printf("%d º elemento: ", i+1);
        scanf("%d", &v[i]);
    }

    imprimeVetor(v, n);
    liberaVetor(v);

    return 0;
}


int* criaVetor(int n){
    return (int *) malloc(n*sizeof(int));
}


void imprimeVetor(int* v, int n){
    int i;

    for(i=0; i<n; i++){
        printf("\n%d º elemento: %d", i+1, v[i]);
    }
}


void liberaVetor(int* v){
    free(v);
}
