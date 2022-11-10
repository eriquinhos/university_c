#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
    int senha;
    int prioridade;  // A prioridade será 1, quando preferencial e 0 quando comum
}TSenha;


typedef struct fila{
    TSenha info; 
    struct fila *prox;
}TFila;


typedef TFila *PFila;

TSenha* geradorSenhas(TSenha*, int);
PFila inicializaFila_circ(PFila);
PFila insereFila_circ(PFila, TSenha);
PFila removeFila_circ(PFila, TSenha*);
void imprimeFila_circ(PFila);