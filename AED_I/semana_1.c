// Eric Victor - 148000
// Faça um programa que permita inserir, remover, visualizar e buscar elementos do registro por meio do RA
// O registro deve OBRIGATORIAMENTE conter os campos: Nome, RA, três Notas e frequência 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
  char nome[30];
  int ra;
  float notas[3];
  float freq; 
} TAluno;


typedef struct{
  TAluno aluno;
  int livre;
} TVaga;


int buscaVazio(TVaga aluno[]){
  int pos = 0, i, j;
  
  for(i = 0; i < 50; i++){
    j = aluno[i].livre;
    if(j == 1){
      return pos;
    }
    pos++;
  }
  return -1;
}


int buscaPosAluno(TVaga aluno[], int regalun){
  int pos=0;

  while(pos<50){
    if(regalun == aluno[pos].aluno.ra){
      return pos;
    }
    pos++; 
  }
  return -1;
}


void insereAluno(TVaga aluno[]){
  int i = 1;
  int pos = buscaVazio(aluno);
  int rep;
  float incomp;
  
  if(pos != -1){  
    do{
      //Limpa os caracteres caso entre no loop while
      memset(aluno[pos].aluno.nome, "\0", sizeof(aluno[pos].aluno.nome));
      rep = 0;
      getchar(); 

      // Função de inserção
      printf("\nNome: ");
      fgets(aluno[pos].aluno.nome, sizeof(aluno[pos].aluno.nome), stdin);
      aluno[pos].aluno.nome[strlen(aluno[pos].aluno.nome)-1] = '\0';
  
      printf("\nRA: ");
      scanf("%d", &rep);
    }while((1000000 < rep || rep < 100000) || buscaPosAluno(aluno, rep) != -1);
    
    aluno[pos].aluno.ra = rep;
    
    for(i=0; i<3; i++){
        printf("\nNota %d: ", i+1);
        scanf("%f", &incomp);
      while(incomp < 0 || incomp > 10){
        printf("\nNota inválida! Digite novamente.");
        printf("\nNota %d: ", i+1);
        scanf("%f", &incomp);
      }
      aluno[pos].aluno.notas[i] = incomp;
    }
    
    do{
      printf("\nFrequência: ");
      scanf("%f", &aluno[pos].aluno.freq);
    }while(aluno[pos].aluno.freq < 0 || aluno[pos].aluno.freq > 100);

    aluno[pos].livre = 0;
    printf("\nAluno cadastrado!\n");
  }
  else{
    printf("Não foi possível cadastrar o aluno!");
  }
}


void removeAluno(TVaga aluno[], int regalun){
  int i;
  int pos = buscaPosAluno(aluno, regalun);

  if(pos == -1){
    printf("\nO aluno não está cadastrado!\n");
  } 
  else{
    memset(aluno[pos].aluno.nome, "\0", sizeof(aluno[pos].aluno.nome));
    aluno[pos].aluno.ra = NULL;
    aluno[pos].aluno.freq = 0;

    for(i = 0; i < 3; i++){
      aluno[pos].aluno.notas[i] = 0;
    }

    aluno[pos].livre = 1;
    printf("\nAluno removido\n");
  } 
}


void listaAluno(TVaga aluno[]){
  int pos=0;
  int i, soma = 0;


  for(i = 0; i < 50; i++){
    if(aluno[i].livre == 0){
      soma++;
    }
  }
  
  if(soma == 0){
    printf("\nNão há alunos cadastrados!\n");
  } 
    
  else{
    while(pos < 50){
      if(aluno[pos].livre == 0){
        printf("\n\nNome: %s\n", aluno[pos].aluno.nome);
        printf("RA: %i\n", aluno[pos].aluno.ra);
        for(i = 0; i < 3; i++)
          printf("Nota %i: %.2f\n", i + 1, aluno[pos].aluno.notas[i]);
        printf("Frequencia: %f\n", aluno[pos].aluno.freq);
      }
      pos++;
    }
  }
}


void buscaAluno(TVaga aluno[], int regalun){
  int i, pos = 0;

  while(pos < 50){
    if(regalun == aluno[pos].aluno.ra){
      printf("\n\nNome: %s\n", aluno[pos].aluno.nome);
      printf("RA: %i\n", aluno[pos].aluno.ra);
      for(i = 0; i < 3; i++)
        printf("Nota %i: %.2f\n", i + 1, aluno[pos].aluno.notas[i]);
      printf("Frequencia: %f\n", aluno[pos].aluno.freq);
      break;
    }
    pos++;
  }
  if(pos == 50){
    printf("\nO aluno não está cadastrado!\n");
  }
}


int main(){
  TVaga aluno[50];
  int opcao=0;
  int ra, i, soma;

  for(i = 0; i < 50; i++){
    aluno[i].livre = 1;
  }
  
  while(opcao!=5){
    soma = 0;
    printf("\n1 - Inserir Aluno");
    printf("\n2 - Remover Aluno");
    printf("\n3 - Visualizar Alunos");
    printf("\n4 - Buscar Aluno");
    printf("\n5 - Sair");

    printf("\nEscolha: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        insereAluno(aluno);
        break;
      
      case 2:
        for(i = 0; i < 50; i++){
          if(aluno[i].livre == 0){
            soma++;
          }
        }
  
        if(soma == 0){
          printf("\nNão há alunos cadastrados!\n");
          break;
        }
        
        printf("\nInsira o RA: ");
        scanf("%d", &ra);
        removeAluno(aluno, ra);
        break;

      case 3:
        listaAluno(aluno);
        break;

      case 4:
        for(i = 0; i < 50; i++){
          if(aluno[i].livre == 0){
            soma++;
          }
        }
  
        if(soma == 0){
          printf("\nNão há alunos cadastrados!\n");
          break;
        } 
        printf("\nInsira o RA: ");
        scanf("%d", &ra);
        buscaAluno(aluno, ra);
        break;

      case 5:
        printf("\nObrigado por utilizar nosso sistema!");
        break;

      default:
        printf("\nOpção Inválida.");
        break;
    }
  }
 return 0;   
}
