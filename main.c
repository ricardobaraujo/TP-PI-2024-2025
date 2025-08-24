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
    dados_senha senha[TAM_SENHA];
    int qnt_func = 0, qnt_ementa = 0, qnt_senha = 0;
    int op, op_aux;
    bool term = false, term_aux;

    while (!term) {
        term_aux = false;
        op = menu();

        if (op == 1) {
            while (!term_aux) {
                op_aux = menu_func();
                switch (op_aux) {
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
                        term_aux = true;
                }
                if (op_aux != 0) pausar();
            }
        }
        else if (op == 2) {
            while (!term_aux) {
                op_aux = menu_ementa();
                switch (op_aux) {
                    case 1:
                        qnt_ementa = ler_file_ementa(ementa, qnt_ementa);
                        break;
                    case 2:
                        guardar_file_ementa(ementa, qnt_ementa);
                        break;
                    case 3:
                        qnt_ementa = introduzir_ementa(ementa, qnt_ementa);
                        break;
                    case 4:
                        listar_ementa(ementa, qnt_ementa);
                        break;
                    default:
                        term_aux = true;
                }
                if (op_aux != 0) pausar();
            }
        }
        else if (op == 3) {
            while (!term_aux) {
                op_aux = menu_senha();
                switch (op_aux) {
                    case 1:
                        qnt_ementa = ler_file_ementa(ementa, qnt_ementa);
                        break;
                    case 2:
                        guardar_file_ementa(ementa, qnt_ementa);
                        break;
                    case 3:
                        qnt_ementa = introduzir_ementa(ementa, qnt_ementa);
                        break;
                    case 4:
                        listar_ementa(ementa, qnt_ementa);
                        break;
                    default:
                        term_aux = true;
                }
                if (op_aux != 0) pausar();
            }
        }
        else {
            printf("programa terminado!\n\n");
            term = true;
        }
        
    }

    return 0;
}

int menu() {
    int op;
    bool match = false;

    while (!match) {
        system("clear");
        printf("M E N U\n");

        printf(" 1 - Funcionarios\n");
        printf(" 2 - Ementas\n");
        printf(" 3 - Senhas\n");
        printf(" 0 - Sair\n");

        printf(" opção: ");
        scanf("%d", &op);
        printf("\n");

        if (op >= 0 && op <= 3) match = true;
        else {
            printf("operacao invalida");
            pausar();
        }
    }

    return op;
}
int menu_func() {
    int op;
    bool match = false;

    while (!match) {
        system("clear");
        printf("FUNCIONARIOS\n");

        printf(" 1 - Ler dados dos funcionarios do ficheiro\n");
        printf(" 2 - Guardar dados dos funcionarios no ficheiro\n");
        printf(" 3 - Introduzir funcionario\n");
        printf(" 4 - Listar todos os funcionarios\n");
        printf(" 0 - Voltar atras\n");

        printf(" opção: ");
        scanf("%d", &op);
        printf("\n");

        if (op >= 0 && op <= 4) match = true;
        else {
            printf("operacao invalida");
            pausar();
        }
    }

    return op;
}
int menu_ementa() {
    int op;
    bool match = false;

    while (!match) {
        system("clear");
        printf("EMENTAS\n");

        printf(" 1 - Ler dados das ementas do ficheiro\n");
        printf(" 2 - Guardar dados das ementas no ficheiro\n");
        printf(" 3 - Introduzir ementa\n");
        printf(" 4 - Listar todas as ementas\n");
        printf(" 0 - Voltar atras\n");

        printf(" opção: ");
        scanf("%d", &op);
        printf("\n");

        if (op >= 0 && op <= 4) match = true;
        else {
            printf("operacao invalida");
            pausar();
        }
    }

    return op;
}
int menu_senha() {
    int op;
    bool match = false;

    while (!match) {
        system("clear");
        printf("SENHAS\n");

        printf(" 1 - Ler dados das senhas do ficheiro\n");
        printf(" 2 - Guardar dados das senhas no ficheiro\n");
        printf(" 3 - Introduzir senha\n");
        printf(" 4 - Listar todas as senhas\n");
        printf(" 0 - Voltar atras\n");

        printf(" opção: ");
        scanf("%d", &op);
        printf("\n");

        if (op >= 0 && op <= 4) match = true;
        else {
            printf("operacao invalida");
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
                if (!existe_func(func, qnt_func, func[qnt_func].id)) qnt_func++;
                else match = true;
            }
        } while (!feof(fp));
        fclose(fp);
    }

    if (!match) printf("dados lidos com sucesso!");
    else printf("ERRO: não é possivel repetir o ID");

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

    printf("dados guardados!");
}
int introduzir_func(dados_func func[TAM_FUNC], int qnt_func) {
    if (qnt_func < TAM_FUNC) {
        func[qnt_func].id = lerInteiro("ID: ");
        if (!existe_func(func, qnt_func, func[qnt_func].id)) {
            lerString("Nome: ", func[qnt_func].nome);
            func[qnt_func].nif = lerInteiro("NIF: ");
            func[qnt_func].telefone = lerInteiro("Telefone: ");
            qnt_func++;
        }
        else printf("\nERRO: não é possivel repetir o ID!");
    }
    else printf("Limite maximo de funcionarios atingido!");

    return qnt_func;
}
void listar_func(dados_func func[TAM_FUNC], int qnt_func) {
    if (qnt_func <= 0) {
        printf("ainda sem funcionarios!");
        return;
    }

    int spc[3] = { 5, 25, 12 };
    int bar[3] = { 1, 1, 2 };
    int rep = 0;

    for (int i = 0; i < 3; i++)
        rep += ((spc[i] + 2) * bar[i]) + bar[i];
    rep--;

    int p1, p2, p3;
    char str[12];

    sep(rep);
    printf("| %-*s ", spc[0], "ID");
    printf("| %-*s ", spc[1], "Nome");
    printf("| %-*s ", spc[2], "NIF");
    printf("| %-*s |\n", spc[2], "Telefone");
    sep(rep);
    for (int i = 0; i < qnt_func; i++) {
        printf("| %*d ", spc[0], func[i].id);
        printf("| %-*s ", spc[1], func[i].nome);

        p1 = func[i].nif / 1000000;
        p2 = (func[i].nif / 1000) % 1000;
        p3 = func[i].nif % 1000;
        snprintf(str, sizeof(str), "%d %d %d", p1, p2, p3);
        printf("| %*s ", spc[2], str);

        p1 = func[i].telefone / 1000000;
        p2 = (func[i].telefone / 1000) % 1000;
        p3 = func[i].telefone % 1000;
        snprintf(str, sizeof(str), "%d %d %d", p1, p2, p3);
        printf("| %*s |\n", spc[2], str);
    }
    sep(rep);
}

// EMENTAS
int ler_file_ementa(dados_ementa ementa[TAM_EMENTA], int qnt_ementa) {
    FILE *fp;
    fp = fopen("ementas.txt", "rt");

    qnt_ementa = 0;
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
    }

    printf("dados lidos com sucesso!");

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

    printf("dados guardados!");
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
    else printf("Ementas para a semana completas!");

    return qnt_ementa;
}
void listar_ementa(dados_ementa ementa[TAM_EMENTA], int qnt_ementa) {
    if (qnt_ementa <= 0) {
        printf("ainda sem ementas para a semana!");
        return;
    }

    int spc[3] = { 10, 19, 5 };
    int bar[3] = { 2, 4, 4 };
    int rep = 0;

    for (int i = 0; i < 3; i++)
        rep += ((spc[i] + 2) * bar[i]) + bar[i];
    rep--;

    char str[12];

    sep(rep);
    printf("| %-*s ", spc[0], "dia semana");
    printf("| %-*s ", spc[0], "dia");
    printf("| %-*s ", spc[1], "peixe");
    printf("| %-*s ", spc[2], "cal");
    printf("| %-*s ", spc[1], "carne");
    printf("| %-*s ", spc[2], "cal");
    printf("| %-*s ", spc[1], "dieta");
    printf("| %-*s ", spc[2], "cal");
    printf("| %-*s ", spc[1], "vegetariano");
    printf("| %-*s |\n", spc[2], "cal");
    sep(rep);
    for (int i = 0; i < qnt_ementa; i++) {
        printf("| %-*s ", spc[0], ementa[i].dia_semana);

        snprintf(str, sizeof(str), "%d.%d.%d", ementa[i].dia, ementa[i].mes, ementa[i].ano);
        printf("| %*s ", spc[0], str);

        printf("| %-*s ", spc[1], ementa[i].peixe);
        printf("| %*d ", spc[2], ementa[i].peixe_cal);

        printf("| %-*s ", spc[1], ementa[i].carne);
        printf("| %*d ", spc[2], ementa[i].carne_cal);

        printf("| %-*s ", spc[1], ementa[i].dieta);
        printf("| %*d ", spc[2], ementa[i].dieta_cal);

        printf("| %-*s ", spc[1], ementa[i].vegetariano);
        printf("| %*d |\n", spc[2], ementa[i].vegetariano_cal);
    }
    sep(rep);
}
