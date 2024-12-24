/**
 * @file profunc.h
 * @author Ricardo Araújo (a21150@alunos.ipca.pt)
 * @brief 
 * @version 0.1
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

typedef struct {
    int id;
    char nome[QTC];
    int nif;
    int telefone;
} dados_func;

// funções "main.c"
int menu();
int ler_file_func(dados_func func[TAM_FUNC], int qnt_func);
void guardar_file_func(dados_func func[TAM_FUNC], int qnt_func);
int introduzir_func(dados_func func[TAM_FUNC], int qnt_func);
void listar_func(dados_func func[TAM_FUNC], int qnt_func);

// funções "profunc.c"
int lerInteiro(char questao[]);
float lerReal(char questao[]);
void lerString(char questao[], char resposta[]);
bool existe(dados_func func[TAM_FUNC], int qnt_func, int codigo);
void pausar();
void sep(int spc, int bar);

