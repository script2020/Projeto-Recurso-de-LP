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
/*
 * 
 */
int main() {

    int opcao;
    Funcionarios funcionarios;

    do {
        printf("Gestão de Projetos------------------------------------------------------");
        printf("\n1 - Carregar base de dados");
        printf("\n2 - Gestão de Funcionários");
        printf("\n3 - Listas");
        printf("\n0 - Sair");
        printf("\n------------------------------------------------------------");

        puts("\nOpção:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                carregarFuncionarios(&funcionarios);
                break;
            case 2:
                menuFuncinonarios();
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);

    libertarFuncionarios(&funcionarios);

    return 0;
}

