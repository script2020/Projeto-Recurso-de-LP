/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionario.h
 * Author: pedro
 *
 * Created on 22 de fevereiro de 2021, 15:36
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "structs.h"

#define FUNCIONARIOS_DB_FILE  "funcionarios.bin" // nome do ficheiro que deverá guardar a base de dados de funcionarios.

#define MAX_STR 100 // limite de caracteres para as strings.
#define TAM_INICIAL_FUNCIONARIOS 2 // quantidade inicial de funcionarios a alocar.
#define TAMANHO_AUMENTA_REALLOC 2 // quantidade de funcionarios a realocar.

#define VALOR_CODIGO_MINIMO 1 // valor minimo para o codigo do funcionario.
#define VALOR_CODIGO_MAXIMO 5000 // valor máximo para o codigo do funcionario.


void carregarFuncionarios(Funcionarios *funcionarios);

void menuFuncinonarios(Funcionarios *funcionarios);

int procurarFuncionario(Funcionarios *funcionarios, int codigoProcurar);
void editarFuncionario(Funcionarios *funcionarios);
int inserirFuncionario(Funcionarios *funcionarios);
void removerFuncionario(Funcionarios *funcionarios);
void guardarFuncionariosFILE(Funcionarios *funcionarios);

void imprimirFuncionario(Funcionario funcionario);
void listarFuncionarios(Funcionarios *funcionarios);

void libertarFuncionarios(Funcionarios *funcionarios);

#endif /* FUNCIONARIO_H */

