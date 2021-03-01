/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   projeto.h
 * Author: pedro
 *
 * Created on 1 de março de 2021, 01:45
 */

#ifndef PROJETO_H
#define PROJETO_H

#include "funcionario.h"

#define PROJETOS_DB_FILE  "projetos.bin"

#define MAX_STR 100 // limite de caracteres para as strings.
#define TAM_INICIAL_PROJETOS 2 // quantidade inicial de projetos a alocar.
#define TAMANHO_AUMENTA_REALLOC 2 // quantidade de projetos a realocar.

#define VALOR_CODIGO_MINIMO 1 // valor minimo para o codigo do funcionario.
#define VALOR_CODIGO_MAXIMO 5000 // valor máximo para o codigo do funcionario.

typedef struct {
    int codigo; // codigo identificador do projeto.
    char nome[MAX_STR]; // nome do projeto.
}Projeto;

typedef struct {
    int contador; // indica a quantidade de projetos na base de dados.
    int tamanho; // indica a quantidade de projetos alocadas e que podem conter dados.
    Projeto *projetos; // projetos em que o funcionario participa.
}Projetos;

void carregarProjetos(Projetos *projetos);

void menuProjetos();
int inserirProjeto(Projetos *projetos);
void designarProjeto(Projetos *projetos,Funcionarios *funcionarios);
void guardarProjetosFILE(Projetos *projetos);
void libertarProjetos(Projetos *Projetos);

#endif /* PROJETO_H */

