/**
 * @file main.c
 * @author Ricardo Araújo (a21150@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 24-12-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "profunc.h"

int main() {
    dados_func func[TAM_FUNC];
    int op, qnt_func = 0;
    bool term = false;

    while (!term) {
        op = menu();
        switch (op) {
            case 1:
                qnt_func = ler_file_func(func, qnt_func);
                break;
            case 2:
                guardar_file_func(func, qnt_func);
                break;
            case 3:
                qnt_func = introduzir_func(func, qnt_func);
                break;
            case 4:
                listar_func(func, qnt_func);
                break;
            default:
                printf("programa terminado!\n\n");
        }

        if (op != 0) pausar();
        else term = true;
    }

    return 0;
}

int menu() {
    int op;
    bool match = false;

    while (!match) {
        system("clear");
        printf("M E N U\n");
        printf("1 - Ler dados dos funcionarios do ficheiro\n");
        printf("2 - Guardar dados dos funcionarios no ficheiro\n");
        printf("3 - Introduzir funcionario\n");
        printf("4 - Listar todos os funcionarios\n");;
        printf("0 - Sair\n");
        printf("opção? ");
        scanf("%d", &op);
        printf("\n");

        if (op >= 0 && op <= 4) match = true;
        else {
            printf("operacao invalida\n");
            pausar();
        }
    }

    return op;
}
int ler_file_func(dados_func func[TAM_FUNC], int qnt_func) {
    FILE *fp;
    fp = fopen("funcionarios.txt", "rt");

    bool match = false;
    if (fp != NULL) {
        do {
            if (qnt_func < TAM_FUNC) {
                fscanf(fp, "%d;%[^;];%d;%d\n",
                &func[qnt_func].id, func[qnt_func].nome,
                &func[qnt_func].nif, &func[qnt_func].telefone);
                if (!existe(func, qnt_func, func[qnt_func].id)) qnt_func++;
                else match = true;
            }
        } while (!feof(fp));
        fclose(fp);
    }

    if (!match) printf("dados lidos com sucesso!\n");
    else printf("ERRO: não é possivel repetir o ID\n");

    return qnt_func;
}
void guardar_file_func(dados_func func[TAM_FUNC], int qnt_func) {
    FILE *fp;
    fp = fopen("funcionarios.txt", "wt");

    if (fp != NULL) {
        for (int i = 0; i < qnt_func; i++) {
            fprintf(fp, "%d;%s;%d;%d\n",
            func[i].id, func[i].nome,
            func[i].nif, func[i].telefone);
        }
        fclose(fp);
    }

    printf("dados guardados!\n");
}
int introduzir_func(dados_func func[TAM_FUNC], int qnt_func) {
    if (qnt_func < TAM_FUNC) {
        func[qnt_func].id = lerInteiro("ID: ");
        if (!existe(func, qnt_func, func[qnt_func].id)) {
            lerString("Nome: ", func[qnt_func].nome);
            func[qnt_func].nif = lerInteiro("NIF: ");
            func[qnt_func].telefone = lerInteiro("Telefone: ");
            qnt_func++;
        }
        else printf("ERRO: não é possivel repetir o ID!\n");
    }
    else printf("Limite maximo de funcionarios atingido!\n");

    return qnt_func;
}
void listar_func(dados_func func[TAM_FUNC], int qnt_func) {
    if (qnt_func <= 0) {
        printf("ainda sem funcionarios!\n");
        return;
    }

    const int spc = 15, bar = 4;
    int p1, p2, p3;
    char str[12];

    sep(spc, bar);
    printf("| %-*s ", spc, "ID");
    printf("| %-*s ", spc, "Nome");
    printf("| %-*s ", spc, "NIF");
    printf("| %-*s |\n", spc, "Telefone");
    sep(spc, bar);
    for (int i = 0; i < qnt_func; i++) {
        printf("| %*d ", spc, func[i].id);
        printf("| %-*s ", spc, func[i].nome);

        p1 = func[i].nif / 1000000;
        p2 = (func[i].nif / 1000) % 1000;
        p3 = func[i].nif % 1000;
        snprintf(str, sizeof(str), "%d %d %d", p1, p2, p3);
        printf("| %*s ", spc, str);

        p1 = func[i].telefone / 1000000;
        p2 = (func[i].telefone / 1000) % 1000;
        p3 = func[i].telefone % 1000;
        snprintf(str, sizeof(str), "%d %d %d", p1, p2, p3);
        printf("| %*s |\n", spc, str);
    }
    sep(spc, bar);
}

