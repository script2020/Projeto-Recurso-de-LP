/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listas.c
 * Author: pedro
 *
 * Created on 1 de março de 2021, 10:51
 */

#include <stdio.h>
#include <stdlib.h>

#include "trabalho.h"
#include "projeto.h"
#include "input.h"

void imprimirProjetosMaisDiasCompletos(DiasTrabalho diasTrabalho){
    printf("%d %s %d", diasTrabalho.diasTrabalho->projeto.codigo, 
            diasTrabalho.diasTrabalho->projeto.nome,
            diasTrabalho.diasTrabalho->diasCompletos);
}

void imprimirProjetosMaisFaltas(DiasTrabalho diasTrabalho){
    printf("%d %s %d", diasTrabalho.diasTrabalho->projeto.codigo, 
            diasTrabalho.diasTrabalho->projeto.nome,
            diasTrabalho.diasTrabalho->diasCompletos);
}

void listarProjetosMaisDiasTrabalhadosCompletos(DiasTrabalho diasTrabalho){
    int i;
    
    for(i=0;i < diasTrabalho.diasTrabalho->data.mes; i++){
       imprimirProjetosMaisDiasCompletos(diasTrabalho.diasTrabalho[i]);
    }
}

void listarProjetosMaisFaltas(DiasTrabalho diasTrabalho){
    int i;
    
    for(i=0;i < diasTrabalho.diasTrabalho->data.mes; i++){
       imprimirProjetosMaisFaltas(diasTrabalho.diasTrabalho[i]);
    }
}

void menuListas(){
    int opcao;
    
    DiasTrabalho diasTrabalho;
    
    do {
        printf("\n--------------Gestão de Funcionários----------------");
        printf("\n1 - Listar Projeto com mais dias de trabalho completos");
        printf("\n2 - Listar Projeto com mais faltas");
        printf("\n0 - Voltar");
        printf("\n------------------------------------------------------------");

        opcao = obterInt(0,3,"\nOpção:");

        switch (opcao) {
            case 1:
                listarProjetosMaisDiasTrabalhadosCompletos(diasTrabalho);
                break;
            case 2:
                listarProjetosMaisFaltas(diasTrabalho);
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);
}