 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include <stdlib.h>

#include "trabalho.h"
#include "projeto.h"
#include "input.h"

/**
 * Guarda os dias de trabalho completo, meios e ao fim de semana e as faltas do funcionário num certo mês
 *
 * @param diasTrabalho apontador para DiasTrabalho
 * @param limiteDias
 */
void guardarDias(DiasTrabalho *diasTrabalho, int limiteDias){
    do {
         diasTrabalho->diasTrabalho->diasCompletos = obterInt(1, limiteDias, "Indique o nº de dias completos que trabalhou: ");
         diasTrabalho->diasTrabalho->diasMetade = obterInt(1, limiteDias, "Indique nº de dias meio que trabalhou: ");
         diasTrabalho->diasTrabalho->diasFaltas = obterInt(1, limiteDias, "Indique nº de faltas que teve: ");
         diasTrabalho->diasTrabalho->diasFimdeSemana = obterInt(1, limiteDias, "Indique nº de dias ao fim de semana que trabalhou: ");
    } while ( diasTrabalho->diasTrabalho->diasCompletos +  diasTrabalho->diasTrabalho->diasMetade +  diasTrabalho->diasTrabalho->diasFaltas > limiteDias);
}

/**
 * Guarda o códigos do funcionário e do projeto e o mês, do qual serão armazenados os dias de trabalho completo, meios e ao fim de semana e as faltas do funcionário
 *
 * @param diasTrabalho apontador para DiasTrabalho
 */
void registarDiasTrabalho(DiasTrabalho *diasTrabalho){
    diasTrabalho->diasTrabalho->funcionario.codigo = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Indique o codigo do funcionáio que trabalhou: ");
    diasTrabalho->diasTrabalho->projeto.codigo = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Indique o codigo do projeto em que trabalhou: ");
    diasTrabalho->diasTrabalho->data.mes = obterInt(VALOR_MINIMO_MES, VALOR_MAXIMO_MES, "Indique o mês, de 1 a 12, que pretende registar os dias de trabalho");

    switch (diasTrabalho->diasTrabalho->data.mes) {
        case JAN:
            guardarDias(&diasTrabalho, 31);
            break;
        case FEV:
            guardarDias(&diasTrabalho, 28);
            break;
        case MAR:
            guardarDias(&diasTrabalho, 31);
            break;
        case ABR:
            guardarDias(&diasTrabalho, 30);
            break;
        case MAI:
            guardarDias(&diasTrabalho, 31);
            break;
        case JUN:
            guardarDias(&diasTrabalho, 30);
            break;
        case JUL:
            guardarDias(&diasTrabalho, 31);
            break;
        case AGO:
            guardarDias(&diasTrabalho, 31);
            break;
        case SET:
            guardarDias(&diasTrabalho, 30);
            break;
        case OUT:
            guardarDias(&diasTrabalho, 31);
            break;
        case NOV:
            guardarDias(&diasTrabalho, 30);
            break;
        case DEZ:
            guardarDias(&diasTrabalho, 31);
            break;
    }

}

/**
 * Escreve o códigos do funcionario e do projeto e o mês, do qual serão armazenados os dias de trabalho completo, meios e ao fim de semana e as faltas do funcionário
 * num ficheiro para exportar
 *
 * @param diasTrabalho apontador para DiasTrabalho
 */
void escreverDados(DiasTrabalho *diasTrabalho){
    FILE *fp = fopen("relatorio.txt", "w");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    fprintf(fp,"%d,%d,%d,%d,%d",
            diasTrabalho->diasTrabalho->funcionario.codigo,
            diasTrabalho->diasTrabalho->projeto.codigo,
            diasTrabalho->diasTrabalho->diasCompletos,
            diasTrabalho->diasTrabalho->diasMetade,
            diasTrabalho->diasTrabalho->diasFaltas);
    
    fclose(fp);
}

/**
 * Exporta os nº de dias de dias de trabalho completo, meios e ao fim de semana e as faltas do funcionário de ume mês escolhido pelo utilizador
 *
 * @param diasTrabalho apontador para DiasTrabalho
 */
void exportarDados(DiasTrabalho *diasTrabalho){
    int mes = obterInt(VALOR_MINIMO_MES, VALOR_MAXIMO_MES, "Indique o numero do mês, de 1 a 12, que pretende registar os dias de trabalho: ");
    
    switch (mes) {
        case JAN:
            escreverDados(&diasTrabalho);
            break;
        case FEV:
            escreverDados(&diasTrabalho);
            break;
        case MAR:
            escreverDados(&diasTrabalho);
            break;
        case ABR:
            escreverDados(&diasTrabalho);
            break;
        case MAI:
            escreverDados(&diasTrabalho);
            break;
        case JUN:
            escreverDados(&diasTrabalho);
            break;
        case JUL:
            escreverDados(&diasTrabalho);
            break;
        case AGO:
            escreverDados(&diasTrabalho);
            break;
        case SET:
            escreverDados(&diasTrabalho);
            break;
        case OUT:
            escreverDados(&diasTrabalho);
            break;
        case NOV:
            escreverDados(&diasTrabalho);
            break;
        case DEZ:
            escreverDados(&diasTrabalho);
            break;
    }
}

/*
 * A função mostra as funcionalidades associdas à gestão de dias de trabalho
 *
 * @param diasTrabalho apontador para DiasTrabalho
 */
void menuDiasdeTrabalho(DiasTrabalho *diasTrabalho){
    int opcao;

    do {
        printf("\n-------------- Gestão dos dias de trabalho ----------------");
        printf("\n1 - Registar dias de trabalho");
        printf("\n2 - Exportar dados dos dias de trabalho");
        printf("\n0 - Voltar");
        printf("\n------------------------------------------------------------");

        opcao = obterInt(0,3,"\nOpção:");

        switch (opcao) {
            case 1:
                registarDiasTrabalho(diasTrabalho);
                break;
            case 2:
                exportarDados(diasTrabalho);
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);
}
    