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

#include "trabalho.h"
#include "projeto.h"
#include "input.h"



void guardarDias(Trabalho *trabalho, int limiteDias){
     do {
        trabalho->diasCompletos = obterInt(1, limiteDias, "Indique o nº de dias completos que trabalhou: ");
        trabalho->diasMetade = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Indique o codigo do projeto em que trabalhou: ");
        trabalho->diasFaltas = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Indique o codigo do projeto em que trabalhou: ");
    } while (trabalho->diasCompletos + trabalho->diasMetade + trabalho->diasFaltas > 31);
}

void registarDiasTrabalho(Trabalho *trabalho){ 
    trabalho->projeto.codigo = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Indique o codigo do projeto em que trabalhou: ");
    trabalho->data.mes = obterInt(VALOR_MINIMO_MES, VALOR_MAXIMO_MES, "Indique o mês, de 1 a 12, que pretende registar os dias de trabalho");

    switch (trabalho->data.mes) {
        case JAN:
            guardarDias(&trabalho, 31);
            break;
        case FEV:
            guardarDias(&trabalho, 31);
            break;
        case MAR:
            guardarDias(&trabalho, 31);
            break;
        case ABR:
            guardarDias(&trabalho, 30);
            break;
        case MAI:
            guardarDias(&trabalho, 31);
            break;
        case JUN:
            guardarDias(&trabalho, 30);
            break;
        case JUL:
            guardarDias(&trabalho, 31);
            break;
        case AGO:
            guardarDias(&trabalho, 31);
            break;
        case SET:
            guardarDias(&trabalho, 30);
            break;
        case OUT:
            guardarDias(&trabalho, 31);
            break;
        case NOV:
            guardarDias(&trabalho, 30);
            break;
        case DEZ:
            guardarDias(&trabalho, 31);
            break;
    }

}

void escreverDados(Trabalho *trabalho){ 
    FILE *fp = fopen("relatorio.txt", "w");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    fprintf(fp,"%d,%d,%d,%d,%d",
            trabalho->funcionario.codigo,
            trabalho->projeto.codigo,
            trabalho->diasCompletos,
            trabalho->diasMetade,
            trabalho->diasFaltas);
    
    fclose(fp);
}

void exportarDados(Trabalho *trabalho){
    obterInt(VALOR_MINIMO_MES, VALOR_MAXIMO_MES, "Indique o numero do mês, de 1 a 12, que pretende registar os dias de trabalho: ");
    
    switch (trabalho->data.mes) {
        case JAN:
            escreverDados(&trabalho);
            break;
        case FEV:
            escreverDados(&trabalho);
            break;
        case MAR:
            escreverDados(&trabalho);
            break;
        case ABR:
            escreverDados(&trabalho);
            break;
        case MAI:
            escreverDados(&trabalho);
            break;
        case JUN:
            escreverDados(&trabalho);
            break;
        case JUL:
            escreverDados(&trabalho);
            break;
        case AGO:
            escreverDados(&trabalho);
            break;
        case SET:
            escreverDados(&trabalho);
            break;
        case OUT:
            escreverDados(&trabalho);
            break;
        case NOV:
            escreverDados(&trabalho);
            break;
        case DEZ:
            escreverDados(&trabalho);
            break;
    }
}  
    