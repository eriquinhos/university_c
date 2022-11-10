#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000


typedef struct{
  int chave;
  char nome[50];
}TItem;


typedef struct Lista{
  TItem info[MAX];
  int ult;
}TLista;


typedef TLista *PLista;

void inicializaLista(PLista);
int listaCheia(PLista);
int listaVazia(PLista);
int insereListaFim(PLista, TItem);
int insereListaIn(PLista, TItem);
int insereListaPos(PLista, TItem, int);
int buscaItem(PLista, int);
void imprimeItem(PLista, int);
void imprimeLista(PLista);
int removeFim(PLista, TItem*);
int removeIn(PLista, TItem*);
int removePos(PLista, TItem*, int);
int removeItem(PLista, TItem*, int);
void destroiLista(PLista);
