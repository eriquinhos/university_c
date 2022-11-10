#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSeqE.h"


void inicializaLista(PLista l){
  l->ult = 0;
}


int listaCheia(PLista l){
  return l->ult == MAX;
}


int listaVazia(PLista l){
  return l->ult == 0;
}


int insereListaFim(PLista l, TItem novo){
  int pos = l->ult;
  
  if(listaCheia(l)){
    printf("Lista cheia!");
    return 0;
  }
  else{
    l->info[pos] = novo;
    l->ult++;
    printf("Item inserido à lista.\n");
    return 1;
  }
}


int insereListaIn(PLista l, TItem novo){
  int pos = l->ult, i;

  if(listaCheia(l)){
    printf("Lista cheia!\n");
    return 0;
  }
  else{
    for(i = pos; i>0; i--){
      l->info[i] = l->info[i-1];
    }
    l->info[0] = novo;
    l->ult++;
    printf("Item inserido à lista.\n");
    return 1;
  } 
}


int insereListaPos(PLista l, TItem novo, int pos){
  int i, fim = l->ult;
  pos--;
   
  if(listaCheia(l)){
    printf("Lista cheia!\n");
    return 0;
  }
  else{
    if(pos == 0){
      return insereListaIn(l, novo);
    }
    else if(pos == fim){
      return insereListaFim(l, novo);
    }
    else if(pos > fim || pos < 0){
      printf("Posição inválida.\n");
      return 0;
    }
    else{
      for(i=pos; i<=fim; i++){
        l->info[i+1] = l->info[i];
      }
      l->info[pos] = novo;
      l->ult++;
      printf("Item inserido à lista.\n");
      return 1;
    }
  }
}


int buscaItem(PLista l, int chave){
  int i, fim = l->ult;
  
  if(listaVazia(l)){
    printf("Lista vazia!\n");
    return -1;
  }
  else{
    for(i=0; i<fim; i++){
      if(l->info[i].chave == chave){
        return i;
      }
    }
    return -1;
  }
}


void imprimeItem(PLista l, int chave){
  int pos = buscaItem(l, chave);
  printf("Chave: %d\n", l->info[pos].chave);
  printf("Item: %s\n", l->info[pos].nome);
}


void imprimeLista(PLista l){
  int i, fim = l->ult;

  for(i=0; i<fim; i++){
    printf("#%d\n", i+1);
    printf("Chave: %d\n", l->info[i].chave);
    printf("Item: %s\n", l->info[i].nome);
  }
}


int removeFim(PLista l, TItem *item){
  int pos = l->ult-1;

  if(listaVazia(l)){
    printf("Lista vazia!\n");
    return 0;
  }
  else{
    *item = l->info[pos];
    l->ult--;
    printf("Item removido!\n");
    return 1;
  } 
}


int removeIn(PLista l, TItem *item){
  int pos = l->ult, i;

  if(listaVazia(l)){
    printf("Lista vazia!\n");
    return 0;      
  }
  else{
    *item = l->info[0];
    for(i=0; i<pos; i++){
      l->info[i] = l->info[i+1];
    }
    l->ult--;
    printf("Item removido!\n");
    return 1;
  }
}


int removePos(PLista l, TItem *item, int pos){
  int i, fim = l->ult;
  pos--;
  
  if(pos == 0){
    return removeIn(l, item);
  }
  else if(pos == fim-1){
    return removeFim(l, item);    
  }
  else if(pos<0 || pos>=fim){
    printf("Item não encontrado!\n");
    return -1;
  }
  else{
    *item = l->info[pos];
    for(i=pos; i<fim; i++){
      l->info[i] = l->info[i+1];
    }
    l->ult--;
    printf("Item removido!\n");
    return 1;
  }
}


int removeItem(PLista l, TItem *item, int chave){
  int pos = buscaItem(l, chave);
  return removePos(l, item, pos);
}


void destroiLista(PLista l){
  l->ult = 0;
}
