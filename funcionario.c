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
#include "input.h"

/**
 * Carrega os funcionários do ficheiro binário (nome obtido através da constante FUNCIONARIOS_DB_FILE).
 * Se o ficheiro existir, carrega a estrutura de dados a partir do ficheiro.
 * Se o ficheiro não existir, aloca a memória inicial com TAM_INICIAL_FUNCIONARIOS funcionarios e inicializar os restantes campos da struct Funcionarios
 *
 * @param funcionarios apontador para Funcionarios
 */
void carregarFuncionarios(Funcionarios *funcionarios){
    int i, sucesso = 0;

    FILE *fp = fopen(FUNCIONARIOS_DB_FILE, "rb");
    if (fp != NULL) {

        fread(&funcionarios->contador, sizeof (int), 1, fp);

        if (funcionarios->contador > 0) {
            funcionarios->tamanho = funcionarios->contador;
            funcionarios->funcionarios = (Funcionarios*) malloc(funcionarios->contador * sizeof (Funcionarios));
            for (i = 0; i < funcionarios->contador; i++) {
                fread(&funcionarios->funcionarios[i], sizeof (Funcionarios), 1, fp);
            }
            sucesso = 1;
        }

        fclose(fp);
    }
    
    if (!sucesso) {
        fp = fopen(FUNCIONARIOS_DB_FILE, "wb");
        if (fp != NULL) {
            funcionarios->funcionarios = (Funcionarios*) malloc(TAM_INICIAL_FUNCIONARIOS * sizeof (Funcionarios));
            funcionarios->contador = 0;
            funcionarios->tamanho = TAM_INICIAL_FUNCIONARIOS;

            fclose(fp);
        }
    }
}


/**
 * A função armazena a informação constante em funcionarios num ficheiro binário (nome obtido através da constante FUNCIONARIOS_DB_FILE).
 *
 * @param funcionarios estrutura de Funcionarios
 */
void guardarFuncionariosFILE(Funcionarios *funcionarios){
    int i;

    FILE *fp = fopen(FUNCIONARIOS_DB_FILE, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&funcionarios->contador, sizeof (int), 1, fp);

    for (i = 0; i < funcionarios->contador; i++) {
        fwrite(&funcionarios->funcionarios[i], sizeof (Funcionarios), 1, fp);
    }

    fclose(fp);
}

int procurarFuncionario(Funcionarios funcionarios, int codigoProcurar) {
    int i;
    for (i = 0; i < funcionarios.contador; i++) {
        if (funcionarios.funcionarios[i].codigo == codigoProcurar) {
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
int inserirFuncionario(Funcionarios *funcionarios) {
    Funcionarios *apontadorTemp;
    
    if(funcionarios->contador == funcionarios->tamanho){
        puts("MEMORIA CHEIA");
        apontadorTemp = (Funcionarios*) realloc((funcionarios),sizeof(Funcionarios) * ((funcionarios->tamanho) + TAM_INICIAL_FUNCIONARIOS));

        if (apontadorTemp != NULL) {
            funcionarios->tamanho *= TAMANHO_AUMENTA_REALLOC;
            funcionarios->funcionarios = apontadorTemp;
            puts("MEMORIA REALOCADA COM SUCESSO");
        } else {
            puts("ERRO A REALOCAR MEMORIA");
        }
    }else{
        int codigoProcurar;
        codigoProcurar = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Codigo do funcionario que deseja inserir: ");
        
        if(procurarFuncionario(*funcionarios,codigoProcurar) == -1){
            codigoProcurar = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Codigo do funcionario que deseja inserir: ");
            lerString(funcionarios->funcionarios[funcionarios->contador].nome, MAX_STR, "Nome do funcionario: ");
            
            return funcionarios->contador++; 
        }else{
            puts("O funcionario que prentede inserir já se encontra registado na base de dados");
        }
    }
    
    return -1;
}

void imprimirFuncionario(Funcionario funcionario){
    printf("\nCodigo: %d Nome: %s ", funcionario.codigo, funcionario.nome);
}

void listarFuncionarios(Funcionarios *funcionarios){
    int i;
    
    for(i=0;i < funcionarios->contador; i++){
       imprimirFuncionario(funcionarios.funcionarios[i]);
    }
}

void editarFuncionario(Funcionarios *funcionarios){
    
    int campoEditar,codigoProcurar;
    char escolha;
    
    codigoProcurar = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Codigo do funcionario que deseja editar: ");

    if (procurarFuncionario(*funcionarios, codigoProcurar) == -1) {
        while (escolha != "n" || escolha != "N") {

            campoEditar = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Que campo deseja editar? \n"
                    "1 - Codigo\n"
                    "2 - Nome\n"
                    "3 - Projeto em que está a trabalhar");

            switch (escolha) {
                case 0:
                    return;
                case 1:
                    lerString(funcionarios->funcionarios[codigoProcurar].nome, MAX_STR, "Nome do funcionario: ");
                    break;
                case 2:
                    funcionarios->funcionarios->codigo = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Código: ");
                    break;
                case 3:
                    funcionarios->funcionarios->codigo = obterInt(VALOR_CODIGO_MINIMO, VALOR_CODIGO_MAXIMO, "Código: ");
                    break;
                default:
                    printf("Opção inválida.");
            }

            escolha = obterChar("Prentede editar mais algum campo?"
                    "S ou s - sim / N ou n - não");
        }
    }

}

/**
 * A função "eliminara" o funcionario marcando-o como removido
 *
 * @param funcionarios apontador para Funcionarios
 */
void removerFuncionario(Funcionarios *funcionarios){
    funcionarios->funcionarios->eliminado = true;
}

/**
 * A função deve libertar a memória alocada.
 *
 * @param funcionarios apontador para Funcionarios
 */
void libertarFuncionarios(Funcionarios *funcionarios)
{
    if (funcionarios->funcionarios) {
        free(funcionarios->funcionarios);
        funcionarios->funcionarios = NULL;
    }

    funcionarios = NULL;
}

/*
 * 
 */
void menuFuncinonarios(){
    int opcao;
    Funcionarios funcionarios;

    do {
        printf("\nGestão de Projetos------------------------------------------------------");
        printf("\n1 - Inserir Funcionario");
        printf("\n2 - Alterar/Editar Funcinonário");
        printf("\n2 - Remover/Eliminar Funcinonário");
        printf("\n0 - Sair");
        printf("\n------------------------------------------------------------");
        printf("\nFuncionarios: %d/%d", funcionarios.contador, funcionarios.tamanho);

        puts("\nOpção:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                inserirFuncionario(&funcionarios);
                break;
            case 2:
                editarFuncionario(&funcionarios);
                break;
            case 3:
                removerFuncionario(&funcionarios);
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);

    return 0;
}
