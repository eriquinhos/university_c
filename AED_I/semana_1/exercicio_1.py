# Este programa é uma comparação de simplificação de CRUD em linguagem C para um em linguagem Python
# Faça um programa que permita inserir, remover, visualizar e buscar elementos do registro por meio do RA
# O registro deve OBRIGATORIAMENTE conter os campos: Nome, RA, três Notas e frequência


def isnumber(string):
    try:
        float(string)
        return True
    except ValueError:
        return False
    except TypeError:
        return False


def insere_Aluno():
    aluno = {}
    ra = ''
    aluno['Nome'] = str(input('Nome: '))


    aluno['RA'] = ra
    for i in range(1, 4):
        aluno[f'Nota {i}'] = input(f'Nota {i}: ')
    aluno['Frequência'] = input('Frequêcia: ')

    return aluno


def remove_Aluno(turma, RA):
    for i in range(len(turma)):
        if turma[i]['RA'] == RA:
            del turma[i]
            return turma
    print('O aluno não consta nos registros!')
    return turma


def mostra_Alunos(turma):
    for i in range(len(turma)):
        for k, v in aluno.items():
            print(f'{k}: {v}')
        print('-'*20)


def busca_Aluno(turma, RA):
    for i in range(len(turma)):
        if turma[i]['RA'] == RA:
            for k, v in turma[i].items():
                print(f'{k}: {v}')
            return


if __name__ == '__main__':
    turma = list()
    op = 'a'


    while op != 5:
        print("1 - Inserir Aluno")
        print("2 - Remover Aluno")
        print("3 - Visualizar Alunos")
        print("4 - Buscar Aluno")
        print("5 - Sair")

        while not op.isnumeric():
            op = str(input('Escolha: '))
        op = int(op)

        if op == 1:
            turma.append(insere_Aluno())

        elif op == 2:
            if len(turma) == 0:
                print('Não há alunos cadastrados')
            else:
                ra = int(input('Digite o RA: '))
                remove_Aluno(turma, ra)

        elif op == 3:
            if len(turma) == 0:
                print('Não há alunos cadastrados')
            else:
                mostra_Alunos(turma)

        elif op == 4:
            if len(turma) == 0:
                print('Não há alunos cadastrados')
            else:
                ra = int(input('Digite o RA: '))
                busca_Aluno(turma, ra)

        elif op == 5:
            print('Obrigado por usar nosso programa!')
            break
        else:
            print('Opção inválida! Tente Novamente.')

