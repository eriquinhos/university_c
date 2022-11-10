#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filaSeqDin.h"


int main(){
    PFila f;
    TSenha senhas[20], *s = senhas, senha;
    int i;
  
    s = geradorSenhas(s, 20);
    f = inicializaFila_circ(f);

    for(i = 0; i < 20; i++){
        f = insereFila_circ(f, s[i]);
    }
    imprimeFila_circ(f);
    printf("\n----------------\n");

    s = &senha;
    
    do{
        f = removeFila_circ(f, s);
        printf("\nCHAMANDO A SENHA:\n");
        printf("Senha: %d", senha.senha);
        if(senha.prioridade == 0){
            printf("\nSEM PRIORIDADE\n");
        }
        else{
            printf("\nPREFERENCIAL\n");
        }
        printf("\n*********************\n");
    }while(f != NULL);
  
    return 0;
}
