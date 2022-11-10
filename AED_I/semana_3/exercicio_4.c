//Eric Victor - 148000

// Criar um tipo abstrato de dados que represente uma pessoa, contendo nome, data de
// nascimento e CPF. Crie uma variável que é um ponteiro para este TAD (no programa
// principal). Depois crie uma função que receba este ponteiro e preencha os dados da
// estrutura e também uma uma função que receba este ponteiro e imprima os dados da
// estrutura. Finalmente, faça a chamada a esta função na função principal.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct{
    int dia, mes, ano;
}DataNascimento;


typedef struct{
    char nome[50];
    DataNascimento nasc;
    char cpf[16];
}TPessoa;


void dadosPessoa(TPessoa*);


void mostraDados(TPessoa*);


int main(){
    TPessoa *PPessoa;
    
PPessoa = (TPessoa*) malloc(sizeof(TPessoa));

    dadosPessoa(PPessoa);
    mostraDados(PPessoa);

    free(PPessoa);
    return 0;
}


void dadosPessoa(TPessoa *PPessoa){
    printf("\nNome: ");
    fgets(PPessoa->nome, sizeof(PPessoa->nome), stdin);
    PPessoa->nome[strlen(PPessoa->nome)-1] = '\0';

    printf("\nDia de Nascimento: ");
    scanf("%d", &PPessoa->nasc.dia);

    printf("\nMês de Nascimento: ");
    scanf("%d", &PPessoa->nasc.mes);

    printf("\nAno de Nascimento: ");
    scanf("%d", &PPessoa->nasc.ano);

    getchar();
    printf("\nCPF: ");
    fgets(PPessoa->cpf, sizeof(PPessoa->cpf), stdin);
    PPessoa->cpf[strlen(PPessoa->cpf)-1] = '\0';
}


void mostraDados(TPessoa *PPessoa){
    printf("\n\nNome: %s\n", PPessoa->nome);
    printf("\nData de Nascimento: %d/%d/%d\n", PPessoa->nasc.dia, PPessoa->nasc.mes, PPessoa->nasc.ano);
    printf("\nCPF: %s", PPessoa->cpf);
}
