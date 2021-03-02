/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pedro
 *
 * Created on 22 de fevereiro de 2021, 15:28
 */

#include <stdio.h>
#include <stdlib.h>

#include "funcionario.h"
#include "projeto.h"
/*
 * 
 */
int main() {
    int opcao;
    Funcionarios funcionarios;
    Projetos projetos;
    DiasTrabalho diasTrabalho;
    
    do{
        printf("------------- Sistema de gestão --------------------------");
        printf("\n1 - Carregar base de dados");
        printf("\n2 - Gestão de Funcionários");
        printf("\n3 - Gestão de Projetos");
        printf("\n4 - Gestão de dias dos Projetos");
        printf("\n5 - Listas");
        printf("\n0 - Sair");
        printf("\n--------------------------------------------------------");

        opcao = obterInt(0,6,"\nOpção:");

        switch (opcao) {
            case 0:
                break;
            case 1:
                carregarFuncionarios(&funcionarios);
                carregarProjetos(&projetos);
                break;
            case 2:
                funcionarios.funcionarios = (Funcionarios*) malloc(TAM_INICIAL_FUNCIONARIOS * sizeof (Funcionarios));
                funcionarios.contador = 0;
                funcionarios.tamanho = TAM_INICIAL_FUNCIONARIOS;
                
                menuFuncinonarios(&funcionarios);
                break;
            case 3:
                projetos.projetos = (Projetos*) malloc(TAM_INICIAL_PROJETOS * sizeof (Projetos));
                projetos.contador = 0;
                projetos.tamanho = TAM_INICIAL_PROJETOS; 
                
                menuProjetos(&funcionarios,&projetos);
                break;
            case 4:
                menuDiasdeTrabalho(&diasTrabalho);
                break;
            case 5:
                menuListas();
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);

    libertarFuncionarios(&funcionarios);
    libertarProjetos(&projetos);

    return 0;
}

