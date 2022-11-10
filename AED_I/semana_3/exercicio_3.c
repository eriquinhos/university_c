//Eric Victor - 148000

// Construa um programa (main) que aloque em tempo de execução (dinamicamente)
// uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a função
// malloc. Agora, aproveite este programa para construir uma função que recebendo os
// parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
// matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
// matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
// criadas acima.

#include <stdlib.h>
#include <stdio.h>


int** alocaMatriz(int**, int, int);


void liberaMatriz(int**, int);


int main(){
    int **mat, m, n, i, j;
    
    printf("Número de linhas (m): ");
    scanf("%d", &m);
    
    printf("Número de colunas (n): ");
    scanf("%d", &n);

    mat = alocaMatriz(mat, m, n);

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("Matriz [%d][%d]: ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    liberaMatriz(mat, m);
    return 0;
}

int** alocaMatriz(int **matriz, int m, int n){
    int i;

    matriz = (int**)malloc(m*sizeof(int*));

    for(i=0; i<m; i++){
        matriz[i] = (int*)malloc(n*sizeof(int));
    }
    return matriz;
}


void liberaMatriz(int **matriz, int m){
    int i;

    for(i=0; i<m; i++){
        free(matriz[i]);
    }
    free(matriz);
}
