#include <stdio.h>
#include <stdlib.h>
#include "ListaSeqE.h"

int main(){
  TLista lista;
  PLista l = &lista;
  TItem item;
  int chave, pos, n;

  inicializaLista(l);
  printf("\n------ LISTA DE COMPRAS ------\n");
  printf("[1] Inserir produto\n");
  printf("[2] Remover produto\n");
  printf("[3] Buscar produto\n");
  printf("[4] Visualizar lista\n");
  printf("[5] Destruir lista\n");
  printf("\nOpção: ");
  scanf("%d", &n);
  switch(n){
    case 1:
        do{
            printf("Em qual posição deseja inserir: ");
            scanf("%d", &pos);
        }while(pos < 1 && pos > 1001);
        
        printf("Chave: ");
        scanf("%d", &item.chave);
        getchar();
        printf("Nome: ");
        fgets(item.nome, sizeof(item.nome), stdin);
        item.nome[strlen(item.nome)-1] = '\0';
        
        insereListaPos(l, item, pos);

        break;

    case 2:
        do{
            printf("De qual posição deseja remover: ");
            scanf("%d", &pos);
        }while(pos < 1 && pos > 1001);

        removePos(l, &item, pos);
        
        printf("Chave: %d\n", item.chave);
        printf("Item: %s\n", item.nome);

        break;
    
    case 3:
        printf("Insira a chave do produto: ");
        scanf("%d", &chave);

        imprimeItem(l, chave);

        break;

    case 4:
        imprimeLista(l);

        break;

    case 5:
        destroiLista(l);

        break;

    default:
        break;
  }
  destroiLista(l);  
  return 0;
}
