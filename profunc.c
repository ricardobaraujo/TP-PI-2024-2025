/**
 * @file profunc.c
 * @author Ricardo Araújo (a21150@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 24-12-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "profunc.h"

int lerInteiro(char questao[]) {
    int res, dado;

    while (getchar() != '\n');
    do {
        printf("%s", questao);
        res = scanf("%d", &dado);
    } while(res == 0);

    return dado;
}
float lerReal(char questao[]) {
    int res;
    float dado;

    while (getchar() != '\n');
    do {
        printf("%s", questao);
        res = scanf("%f", &dado);
    } while (res == 0);

    return dado;
}
void lerString(char questao[], char resposta[]) {
    int res;

    while (getchar() != '\n');
    do {
        printf("%s", questao);
        res = scanf("%[^\n]", resposta);
    } while (res == 0);
}
bool existe(dados_func func[TAM_FUNC], int qnt_func, int codigo) {
    bool match = false;
    for (int i = 0; i < qnt_func; i++)
        if (func[i].id == codigo) match = true;

    return match;
}
void pausar() {
    while (getchar() != '\n');
    printf("\nENTER para continuar...");
    getchar();
}
void sep(int spc, int bar) {
    int rep = ((spc + 2) * bar) + bar - 1;
    printf("+");
    for (int i = 0; i < rep; i++)
        printf("-");
    printf("+\n");
}

