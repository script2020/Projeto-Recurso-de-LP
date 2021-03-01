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

#include "projeto.h"
#include "funcionario.h"
#include "input.h"

/**
 * Carrega os projetos do ficheiro binário (nome obtido através da constante PROJETOS_DB_FILE).
 * Se o ficheiro existir, carrega a estrutura de dados a partir do ficheiro.
 * Se o ficheiro não existir, aloca a memória inicial com TAM_INICIAL_PROJETOS projetos e inicializar os restantes campos da struct Projetos
 *
 * @param projetos apontador para Projetos
 */
void carregarProjetos(Projetos *projetos){
    int i, sucesso = 0;

    FILE *fp = fopen(PROJETOS_DB_FILE, "rb");
    if (fp != NULL){

        fread(&projetos->contador, sizeof (int), 1, fp);

        if (projetos->contador > 0) {
            projetos->tamanho = projetos->contador;
            projetos->projetos = (Projetos*) malloc(projetos->contador * sizeof (Projetos));
            for (i = 0; i < projetos->contador; i++) {
                fread(&projetos->projetos[i], sizeof (Projetos), 1, fp);
            }
            sucesso = 1;
        }

        fclose(fp);
    }
    
    if (!sucesso) {
        fp = fopen(PROJETOS_DB_FILE, "wb");
        if (fp != NULL) {
            projetos->projetos = (Projetos*) malloc(TAM_INICIAL_PROJETOS * sizeof (Projetos));
            projetos->contador = 0;
            projetos->tamanho = TAM_INICIAL_PROJETOS;

            fclose(fp);
        }
    }
}


/**
 * A função armazena a informação constante em projetos num ficheiro binário (nome obtido através da constante PROJETOS_DB_FILE).
 *
 * @param funcionarios estrutura de Funcionarios
 */
void guardarProjetosFILE(Projetos *projetos){
    int i;

    FILE *fp = fopen(PROJETOS_DB_FILE, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&projetos->contador, sizeof (int), 1, fp);

    for (i = 0; i < projetos->contador; i++) {
        fwrite(&projetos->projetos[i], sizeof (Projetos), 1, fp);
    }

    fclose(fp);
}

int procurarProjeto(Projetos projetos, int codigoProcurar) {
    int i;
    for (i = 0; i < projetos.contador; i++) {
        if (projetos.projetos[i].codigo == codigoProcurar) {
            return i;
        }
    }

    return -1;
}

/**
 * A função deve pedir os dados ao utilizador e inserir um funcionario em funcionarios.
 * Caso o útilizador insira os dados de um funcionario duplicado, informa o utilizdor de que não foi inserido.
 *
 * @param funcionarios apontador para Funcionarios
 */
int criarProjeto(Projetos *projetos){   
    int codigoProcurar;
    
    if(projetos->contador == projetos->tamanho){
        puts("MEMORIA CHEIA");
        Projetos *apontadorTemp = (Projetos*) realloc((projetos->projetos),sizeof(Projetos) * (projetos->tamanho) + TAM_INICIAL_PROJETOS);

        if (apontadorTemp != NULL) {
            projetos->tamanho *= TAMANHO_AUMENTA_REALLOC;
            projetos->projetos = apontadorTemp;
            puts("MEMORIA REALOCADA COM SUCESSO");
        } else {
            puts("ERRO A REALOCAR MEMORIA");
        }
    }else{
        codigoProcurar = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Codigo do projeto que deseja inserir: ");
        if (procurarProjeto(*projetos, codigoProcurar) == -1){
            projetos->projetos->codigo = codigoProcurar;
            lerString(projetos->projetos[projetos->contador].nome, MAX_STR, "Nome do projeto: ");
        }

        return projetos->contador++; 
    }
    
    return -1;
}

void designarProjeto(Projetos *projetos,Funcionarios *funcionarios){
    int codigoProcurar;
    
    codigoProcurar = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Codigo do projeto que pretende designar um funcionário: ");

    if (procurarProjeto(*projetos, codigoProcurar) == -1) {
        funcionarios->funcionarios->codigoProjeto = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Codigo do funcionário que pretende designar ao projeto: ");
    }
}


void imprimirProjeto(Projeto projeto,Funcionario funcionario){
    printf("\nCodigo do projeto: %d Nome do projeto: %s Codigo do funcionario: %d Nome do funcionario: %s",projeto.codigo,projeto.nome, funcionario.codigo, funcionario.nome);
}

void listarProjetos(Projetos *projetos,Funcionarios *funcionarios){
    int i;
    
    for(i=0;i < projetos->contador; i++){
       imprimirProjeto(projetos->projetos[i],funcionarios->funcionarios[i]);
    }
}

/**
 * A função deve libertar a memória alocada.
 *
 * @param funcionarios apontador para Funcionarios
 */
void libertarProjetos(Projetos *projetos)
{
    if (projetos->projetos) {
        free(projetos->projetos);
        projetos->projetos = NULL;
    }

    projetos = NULL;
}

void menuProjetos(Projetos *projetos,Funcionarios *funcionarios){
    int opcao;

    do {
        printf("\n--------- Gestão de Projetos -----------------");
        printf("\n1 - Criar Projeto");
        printf("\n2 - Designar Projeto a funcionario");
        printf("\n3 - Listar Projetos");
        printf("\n0 - Sair");
        printf("\n------------------------------------------------------------");
        printf("\nProjetos: %d/%d", projetos->contador, projetos->tamanho);

        opcao = obterInt(1,3,"\nOpção:");

        switch (opcao) {
            case 0:
                break;
            case 1:
                criarProjeto(&projetos);
                break;
            case 2:
                designarProjeto(&projetos,&funcionarios);
                break;
            case 3:
                listarProjetos(&projetos,&funcionarios);
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);
}
