/**
 * @file profunc.h
 * @author Ricardo Araújo (a21150@alunos.ipca.pt)
 * @brief cabeçalho do projeto
 * @version 0.2
 * @date 24-12-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QTC 50
#define TAM_FUNC 100
#define TAM_EMENTA 7

typedef struct {
    int id;
    char nome[QTC];
    int nif;
    int telefone;
} dados_func;

typedef struct {
    char dia_semana[QTC];
    int dia;
    int mes;
    int ano;
    char peixe[QTC];
    int peixe_cal;
    char carne[QTC];
    int carne_cal;
    char dieta[QTC];
    int dieta_cal;
    char vegetariano[QTC];
    int vegetariano_cal;
} dados_ementa;

// funções "main.c"
int menu();
int menu_func();
int menu_ementa();

// FUNCIONARIOS
int ler_file_func(dados_func func[TAM_FUNC], int qnt_func);
void guardar_file_func(dados_func func[TAM_FUNC], int qnt_func);
int introduzir_func(dados_func func[TAM_FUNC], int qnt_func);
void listar_func(dados_func func[TAM_FUNC], int qnt_func);

// EMENTAS
int ler_file_ementa(dados_ementa ementa[TAM_EMENTA], int qnt_ementa);
void guardar_file_ementa(dados_ementa ementa[TAM_EMENTA], int qnt_ementa);
int introduzir_ementa(dados_ementa ementa[TAM_EMENTA], int qnt_ementa);
void listar_ementa(dados_ementa ementa[TAM_EMENTA], int qnt_ementa);

// funções "profunc.c"
int lerInteiro(char questao[]);
float lerReal(char questao[]);
void lerString(char questao[], char resposta[]);
bool existe_func(dados_func func[TAM_FUNC], int qnt_func, int codigo);
void pausar();
void sep(int rep);
