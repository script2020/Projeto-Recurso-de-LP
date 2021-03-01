/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   structs.h
 * Author: pedro
 *
 * Created on 1 de março de 2021, 10:51
 */

#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_STR 100 // limite de caracteres para as strings.

typedef enum { JAN, FEV, MAR,ABR,MAI,JUN,JUL,AGO,SET,OUT,NOV,DEZ } Mes;

typedef struct {
    int dia,ano;
    Mes mes;}
Data;

typedef enum { false, true } Bool;

typedef struct {
    Bool eliminado; //estado do funcionario.
    int codigo; // codigo identificador do funcionario.
    char nome[MAX_STR]; // nome do funcionario.
    int codigoProjeto;
} Funcionario;

typedef struct {
    int contador; // indica a quantidade de funcionarios na base de dados.
    int tamanho; // indica a quantidade de funcionarios alocadas e que podem conter dados.
    Funcionario *funcionarios;
}Funcionarios;

typedef struct {
    int codigo; // codigo identificador do projeto.
    char nome[MAX_STR]; // nome do projeto.
}Projeto;

typedef struct {
    int contador; // indica a quantidade de projetos na base de dados.
    int tamanho; // indica a quantidade de projetos alocadas e que podem conter dados.
    Projeto *projetos; // projetos em que o funcionario participa.
}Projetos;

typedef enum { COMPLETA, MEIA, FALTA } TiposJornada;

typedef struct {
    Projeto projeto;
    Funcionario funcionario;
    Data data;
    TiposJornada jornada;
}Trabalho;
#endif /* STRUCTS_H */

