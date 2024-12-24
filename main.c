/**
 * @file main.c
 * @author Ricardo Araújo (a21150@alunos.ipca.pt)
 * @brief projeto de gestão de senhas e funcionarios
 * @version 0.2
 * @date 24-12-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "profunc.h"

int main() {
    dados_func func[TAM_FUNC];
    dados_ementa ementa[TAM_EMENTA];
    int op, qnt_func = 0, qnt_ementa = 0;
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
            case 5:
                qnt_ementa = ler_file_ementa(ementa, qnt_ementa);
                break;
            case 6:
                guardar_file_ementa(ementa, qnt_ementa);
                break;
            case 7:
                qnt_ementa = introduzir_ementa(ementa, qnt_ementa);
                break;
            case 8:
                listar_ementas(ementa, qnt_ementa);
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
        printf("4 - Listar todos os funcionarios\n");
        printf("5 - Ler dados das ementas do ficheiro\n");
        printf("6 - Guardar dados das ementas no ficheiro\n");
        printf("7 - Introduzir ementa\n");
        printf("8 - Listar todas as ementas\n");
        printf("0 - Sair\n");
        printf("opção? ");
        scanf("%d", &op);
        printf("\n");

        if (op >= 0 && op <= 8) match = true;
        else {
            printf("operacao invalida\n");
            pausar();
        }
    }

    return op;
}

// FUNCIONARIOS
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

// EMENTAS
int ler_file_ementa(dados_ementa ementa[TAM_EMENTA], int qnt_ementa) {
    FILE *fp;
    fp = fopen("ementas.txt", "rt");

    if (fp != NULL) {
        do {
            if (qnt_ementa < TAM_EMENTA) {
                fscanf(fp, "%[^;];%d.%d.%d;%[^;];%d;%[^;];%d;%[^;];%d;%[^;];%d\n",
                ementa[qnt_ementa].dia_semana,
                &ementa[qnt_ementa].dia, &ementa[qnt_ementa].mes, &ementa[qnt_ementa].ano,
                ementa[qnt_ementa].peixe, &ementa[qnt_ementa].peixe_cal,
                ementa[qnt_ementa].carne, &ementa[qnt_ementa].carne_cal,
                ementa[qnt_ementa].dieta, &ementa[qnt_ementa].dieta_cal,
                ementa[qnt_ementa].vegetariano, &ementa[qnt_ementa].vegetariano_cal);

                qnt_ementa++;
            }
        } while (!feof(fp));
        fclose(fp);
        printf("dados lidos com sucesso!\n");
    }

    return qnt_ementa;
}
void guardar_file_ementa(dados_ementa ementa[TAM_EMENTA], int qnt_ementa) {
    FILE *fp;
    fp = fopen("ementas.txt", "wt");

    if (fp != NULL) {
        for (int i = 0; i < qnt_ementa; i++) {
            fprintf(fp, "%s;%d.%d.%d;%s;%d;%s;%d;%s;%d;%s;%d\n",
            ementa[i].dia_semana,
            ementa[i].dia, ementa[i].mes, ementa[i].ano,
            ementa[i].peixe, ementa[i].peixe_cal,
            ementa[i].carne, ementa[i].carne_cal,
            ementa[i].dieta, ementa[i].dieta_cal,
            ementa[i].vegetariano, ementa[i].vegetariano_cal);
        }
        fclose(fp);
    }

    printf("dados guardados!\n");
}
int introduzir_ementa(dados_ementa ementa[TAM_EMENTA], int qnt_ementa) {
    if (qnt_ementa < TAM_EMENTA) {
        int dmes[TAM_EMENTA] = { 6, 7, 8, 9, 10, 11, 12 };
        char dsem[TAM_EMENTA][QTC] = {
            "2feira", "3feira", "4feira", "5feira", "6feira", "sabado", "domingo"
        };

        strcpy(ementa[qnt_ementa].dia_semana, dsem[qnt_ementa]);
        printf("%s ", ementa[qnt_ementa].dia_semana);

        ementa[qnt_ementa].dia = dmes[qnt_ementa];
        ementa[qnt_ementa].mes = 1;
        ementa[qnt_ementa].ano = 2025;
        printf("( %d.%d.%d )\n", ementa[qnt_ementa].dia,
        ementa[qnt_ementa].mes, ementa[qnt_ementa].ano);

        lerString("\n  prato peixe: ", ementa[qnt_ementa].peixe);
        ementa[qnt_ementa].peixe_cal = lerInteiro("  calorias: ");

        lerString("\n  prato carne: ", ementa[qnt_ementa].carne);
        ementa[qnt_ementa].carne_cal = lerInteiro("  calorias: ");

        lerString("\n  prato dieta: ", ementa[qnt_ementa].dieta);
        ementa[qnt_ementa].dieta_cal = lerInteiro("  calorias: ");

        lerString("\n  prato vegetariano: ", ementa[qnt_ementa].vegetariano);
        ementa[qnt_ementa].vegetariano_cal = lerInteiro("  calorias: ");

        qnt_ementa++;
    }
    else printf("Ementas para a semana completas!\n");

    return qnt_ementa;
}
void listar_ementas(dados_ementa ementa[TAM_EMENTA], int qnt_ementa) {
    if (qnt_ementa <= 0) {
        printf("ainda sem ementas para a semana!\n");
        return;
    }

    const int spc = 12, bar = 10;
    char str[12];

    sep(spc, bar);
    printf("| %-*s ", spc, "dia semana");
    printf("| %-*s ", spc, "dia");
    printf("| %-*s ", spc, "peixe");
    printf("| %-*s ", spc, "cal");
    printf("| %-*s ", spc, "carne");
    printf("| %-*s ", spc, "cal");
    printf("| %-*s ", spc, "dieta");
    printf("| %-*s ", spc, "cal");
    printf("| %-*s ", spc, "vegetariano");
    printf("| %-*s |\n", spc, "cal");
    sep(spc, bar);
    for (int i = 0; i < qnt_ementa; i++) {
        printf("| %-*s ", spc, ementa[i].dia_semana);

        snprintf(str, sizeof(str), "%d.%d.%d", ementa[i].dia, ementa[i].mes, ementa[i].ano);
        printf("| %*s ", spc, str);

        printf("| %-*s ", spc, ementa[i].peixe);
        printf("| %*d ", spc, ementa[i].peixe_cal);

        printf("| %-*s ", spc, ementa[i].carne);
        printf("| %*d ", spc, ementa[i].carne_cal);

        printf("| %-*s ", spc, ementa[i].dieta);
        printf("| %*d ", spc, ementa[i].dieta_cal);

        printf("| %-*s ", spc, ementa[i].vegetariano);
        printf("| %*d |\n", spc, ementa[i].vegetariano_cal);
    }
    sep(spc, bar);
}

