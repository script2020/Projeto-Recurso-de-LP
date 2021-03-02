/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   trabalho.h
 * Author: pedro
 *
 * Created on 1 de março de 2021, 23:29
 */

#ifndef TRABALHO_H
#define TRABALHO_H

#include "structs.h"

#define VALOR_MINIMO_MES 1
#define VALOR_MAXIMO_MES 12

void guardarDias(DiasTrabalho *diasTrabalho, int limiteDias);
void registarDiasTrabalho(DiasTrabalho *diasTrabalho);
void escreverDados(DiasTrabalho *diasTrabalho);
void exportarDados(DiasTrabalho *diasTrabalho);
void menuDiasdeTrabalho(DiasTrabalho *diasTrabalho);

#endif /* TRABALHO_H */

