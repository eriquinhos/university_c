#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filaSeqDin.h"


/*GERADOR DE SENHAS*/

TSenha* geradorSenhas(TSenha *s, int tam){
    int i, prob, cp = 1, sp = 1;
    
    srand(time(NULL));

    for(i = 0; i < tam; i++){
        prob = (rand()%10)+1;
        if(prob > 5){
            s[i].senha = cp;
            s[i].prioridade = 1;
            cp++;
        }
        else{
            s[i].senha = sp;
            s[i].prioridade = 0;
            sp++;
        }
    }
    return s;
}


/*Para este programa, utilizaremos uma Fila Sequencial Dinâmica Circular Simplesmente Encadeada*/

PFila inicializaFila_circ(PFila f){
    return NULL;
}



/*Insere no final da fila e sempre retorna o ponteiro para o "final" da fila*/ 
PFila insereFila_circ(PFila f, TSenha senha){
    PFila p;
    PFila nova = (PFila) malloc(sizeof(TFila));

    nova->info = senha;
    if(f == NULL){
        nova->prox = nova;
        return nova;
    }
    else{
        p = f->prox;
        if(senha.prioridade == 0){
            nova->prox = f->prox;
            f->prox = nova;
            return nova;
        }
        else{
            while(p != f && p->prox->info.prioridade != 0){
                p = p->prox;
            }

          
            if(p->info.prioridade == 0){
              nova->prox = f->prox;
              f->prox = nova;
            }
            else{
                nova->prox = p->prox;
                p->prox = nova;
            }
            
            if(f->info.prioridade == 0){
                return f;
            }
            else{
                return nova;
            }
        }
    }
}


/*Agora criaremos funções para a retirada geral*/


PFila removeFila_circ(PFila f, TSenha *senha){
    int prob, i;
    PFila p, aux;
  
    for(i = 0; i < 3; i++){
        prob = (rand()%100)+1;
    }
    p = f->prox;
    
    if(f == NULL){
      senha = NULL;
      return f;
    }
    else{
        if(prob < 70){ /*REMOVER OS PREFERENCIAIS*/
            if(p->info.prioridade == 1){ /*IF/ELSE APENAS PARA SEPARAR CASOS, APESAR DE TEREM O MESMO COMPORTAMENTO*/
                f->prox = p->prox;
                *senha = p->info;
                if(p == f){
                    free(p);
                    return NULL;
                }
                else{
                    free(p);
                    return f;
                }
                
            }
            else{ /*CASO NÃO TENHA PREFERENCIAL REMOVER O PRIMEIRO*/
                f->prox = p->prox;
                *senha = p->info;
                if(p == f){
                    free(p);
                    return NULL;
                }
                else{
                    free(p);
                    return f;
                }
            }
        }
        else{ /*REMOVER AS SENHAS COMUNS*/
            if(p->info.prioridade == 0){ /*CASO SEJAM APENAS SENHAS COMUNS*/
                f->prox = p->prox;
                *senha = p->info;
                if(p == f){
                    free(p);
                    return NULL;
                }
                else{
                    free(p);
                    return f;
                }
            }
            else{
               if(f->info.prioridade == 1){ /*CASO SEJAM APENAS SENHAS PREFERENCIAIS*/
                    f->prox = p->prox;
                    *senha = p->info;
                    if(p == f){
                      free(p);
                      return NULL;
                    }
                    else{
                        free(p);
                        return f;
                    }
                }
                else{ /*PELO MENOS UMA SENHA PRIORITÁRIA E UMA COMUM*/
                    do{
                      if(p->prox->info.prioridade == 0){
                          aux = p;
                      }
                      p = p->prox; 
                    }while(p->info.prioridade != 0 && p != f->prox);
                    aux->prox = p->prox;
                    *senha = p->info;
                    if(p == f){
                        if(f->prox != NULL){
                            free(p);
                            return aux;
                        }
                        else{
                            free(p);
                          return NULL;
                        }
                    }
                    else{
                      free(p);
                      return f;
                    }
                }
            }
        }
    }  
}


void imprimeFila_circ(PFila f){
    PFila p = f->prox;

   do{
        printf("\nSenha: %d", p->info.senha);
        if(p->info.prioridade == 0){
            printf("\nSEM PRIORIDADE\n");
        }
        else{
            printf("\nPREFERENCIAL\n");
        }
        p = p->prox;
    }while(p != f->prox);
}
