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
#include "input.h"

void registarDiasTrabalho(Trabalho *trabalho){
    
    trabalho->data.mes = obterInt(VALOR_MINIMO_MES,VALOR_MAXIMO_MES,"Indique o mês, de 1 a 12, que pretende registar os dias de trabalho");
    
    switch(trabalho->data.mes){
        case JAN:
            break;
        case JAN:
            break;
    }

}


void exportarDados(Trabalho *trabalho){
    
    
}