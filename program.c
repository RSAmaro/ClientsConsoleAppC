// Livrarias
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

// Cores do programa
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#define MAX 256

//Variaveis
FILE * FIL;
char info[1000];

int MaxQuantidade = 1000;
char NomePrograma[50] = "Coutaro";
char nome_ficheiro[1000];

char escolha_char[3];
int escolha;

char Cliente[100] = "Cliente";
float Nr_Clientes;

char Stock[100] = "Produto";
float Nr_Produtos;

char Venda[100] = "Venda";
float Nr_Vendas;

char Fornecedor[100] = "Fornecedor";
float Nr_Fornecedores;

#pragma region Quantidades
// Quantidades
void Quantidade_Clientes() {
    Nr_Clientes = 0;
    for (float i = MaxQuantidade; i > 0; i--) {
        sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, i);
        if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
            fclose(FIL);
            Nr_Clientes = i;
            break;
        }
    }
}

void Quantidade_Produtos() {
    Nr_Produtos = 0;
    for (float i = MaxQuantidade; i > 0; i--) {
        sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, i);
        if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
            fclose(FIL);
            Nr_Produtos = i;
            break;
        }
    }
}

void Quantidade_Vendas() {
    Nr_Vendas = 0;
    for (float i = MaxQuantidade; i > 0; i--) {
        sprintf(nome_ficheiro, "Vendas/%s%03.0f.txt", Venda, i);
        if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
            fclose(FIL);
            Nr_Vendas = i;
            break;
        }
    }
}

void Quantidade_Fornecedores() {
    Nr_Fornecedores = 0;
    for (float i = MaxQuantidade; i > 0; i--) {
        sprintf(nome_ficheiro, "Fornecedores/%s%03.0f.txt", Fornecedor, i);
        if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
            fclose(FIL);
            Nr_Fornecedores = i;
            break;
        }
    }
}
#pragma endregion

//Respostas
void Invalid() {
    printf(RED "\nEscolha Invalida!\n"
        RESET);
    Confirm();
}
void Lines() {
    printf(CYAN "===================="
        RESET);
}
void Confirm() {
    printf(MAGENTA "\n \x10 Pressione qualquer tecla para continuar\n" RESET);
    getch();
}

void make_directory(const char* name) {
   #ifdef __linux__
       mkdir(name, 777); 
   #else
       _mkdir(name);
   #endif
}

//Program
void main() {
    make_directory("Clientes");
    make_directory("Fornecedores");
    make_directory("Vendas");
    make_directory("Stock");
    Menu();
}

// MENU PRINCIPAL
void Menu() {
    do {
        system("cls");
        Lines();
        printf(YELLOW "\n%s\n\n"
            RESET, NomePrograma);
        printf("\x10 1. Vendas\n");
        printf("\x10 2. Stock\n");
        printf("\x10 3. Clientes\n");
        printf("\x10 4. Fornecedores\n");

        printf(RED "\n9. Sair\n"
            RESET);
        Lines();
        printf(GREEN "\nEscolha: "
            RESET);
        scanf("%s", escolha_char);
        escolha = atoi(escolha_char);
        getchar();

        switch (escolha) {
        case 1:
            Menu_Vendas();
            break;
        case 2:
            Menu_Stock();
            break;
        case 3:
            Menu_Clientes();
            break;
        case 4:
            Menu_Fornecedores();
            break;
        case 9:
            break;
        default:
            Invalid();
            break;
        }

    } while (escolha != 9);
}

// CLIENTES
#pragma region Clientes

void Menu_Clientes() {
    do {
        system("cls");
        Lines();
        printf(YELLOW "\n%s"
            RESET " - "
            GREEN "Clientes\n\n"
            RESET, NomePrograma);
        printf("\x10 1. Inserir\n");
        printf("\x10 2. Listar\n");
        printf("\x10 3. Alterar\n");

        printf(RED "\n9. Voltar\n"
            RESET);
        Lines();
        printf(GREEN "\nEscolha: "
            RESET);
        scanf("%s", escolha_char);
        escolha = atoi(escolha_char);
        getchar();

        switch (escolha) {
        case 1:
            Inserir_Cliente((float) 0);
            break;
        case 2:
            Listar_Clientes();
            break;
        case 3:
            Alterar_Clientes();
            break;

        case 9:
            Menu();
            break;
        default:
            Invalid();
            break;
        }

    } while (escolha != 9);
}

float Check_Clientes() {
    for (float i = 1; i < MaxQuantidade; i++) {
        sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, i);
        if ((FIL = fopen(nome_ficheiro, "r")) == NULL) {
            fclose(FIL);
            return i;
        }
    }
}
void Inserir_Cliente(float ID) {
    system("cls");
    char name[100];
    char morada[100];

    int nif;
    float num;

    if ((int) ID == 0) {
        printf("Insercao de um cliente\n\n");
        num = Check_Clientes();
    } else {
        printf("Editando Cliente #%03.0f\n\n", ID);
        num = ID;
    }

    printf(YELLOW "Senao introduzir um valor (ou valor incorreto) ira voltar para o menu anterior\n"
        RESET);

    printf(GREEN "Nome do Cliente: "
        RESET);
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = '\0';
    trimTrailing(name);
    if (name[0] == '\0')
        return;

    printf(GREEN "Morada do Cliente: "
        RESET);
    fgets(morada, 100, stdin);
    morada[strlen(morada) - 1] = '\0';
    trimTrailing(morada);
    if (morada[0] == '\0')
        return;

    printf(GREEN "NIF do Cliente: "
        RESET);
    scanf("%d", &nif);
    if (!(int) nif || (int) nif == NULL || (int) nif < 0)
        return;

    sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, num);
    printf("\nO cliente foi guardado como: %s", nome_ficheiro);

    FIL = fopen(nome_ficheiro, "w");

    //printf("Nome: %s\n", Client_Name);
    fprintf(FIL, "%.0f\n%s\n%s\n%d\n", num, name, morada, nif);

    fclose(FIL);
    Confirm();
}

void Listar_Clientes() {
    system("cls");
    char Linha[100];
    char * result;
    boolean found = 0;
    int nr_linha = 0;

    Quantidade_Clientes();

    for (float i = 1; i <= Nr_Clientes; i++) {
        sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, i);
        if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
            found = 1;
            nr_linha = 0;
            while (!feof(FIL)) {
                result = fgets(Linha, 100, FIL);
                if (result) {
                    if (nr_linha == 0)
                        printf("ID: ");
                    if (nr_linha == 1)
                        printf("Nome: ");
                    if (nr_linha == 2)
                        printf("Morada: ");
                    if (nr_linha == 3)
                        printf("NIF: ");

                    printf(GREEN "%s"
                        RESET, Linha);
                    nr_linha++;
                }
            }
            Lines();
            printf("\n");
        }
        fclose(FIL);

    }
    if (!found) {
        printf(RED "Nao foi encontrado Clientes!"
            RESET);
        Confirm();
        return Menu_Clientes();
    }

    Confirm();
    return;
}

void Alterar_Clientes() {
    float ID;
    Listar_Clientes();

    printf(YELLOW "Escolha o ID do utilizador que pretende alterar: "
        RESET);
    scanf("%f", &ID);
    getchar();

    sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, ID);

    if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
        fclose(FIL);
        Inserir_Cliente(ID);
    }
}

#pragma endregion

#pragma region Stocks
void Menu_Stock() {
    do {
        system("cls");
        Lines();
        printf(YELLOW "\n%s"
            RESET " - "
            GREEN "Stock\n\n"
            RESET, NomePrograma);
        printf("\x10 1. Inserir\n");
        printf("\x10 2. Listar\n");
        printf("\x10 3. Editar Produtos\n");

        printf(RED "\n9. Voltar\n"
            RESET);
        Lines();
        printf(GREEN "\nEscolha: "
            RESET);
        scanf("%s", escolha_char);
        escolha = atoi(escolha_char);
        getchar();

        switch (escolha) {
        case 1:
            Inserir_Stock((float) 0);
            break;
        case 2:
            Listar_Stock();
            break;
        case 3:
            Alterar_Stock();
            break;
        case 9:
            Menu();
            break;
        default:
            Invalid();
            break;
        }

    } while (escolha != 9);
}

float Check_Stock() {
    for (float i = 1; i < MaxQuantidade; i++) {
        sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, i);
        if ((FIL = fopen(nome_ficheiro, "r")) == NULL) {
            fclose(FIL);
            return i;
        }
    }
}

void Inserir_Stock(float ID) {
    system("cls");
    char Texto_Stock[1000] = {};
    char produto[100];
    int quantidade = 0;
    float preco;
    float num;

    if ((int) ID == 0) {
        printf("Insercao de um Produto\n\n");
        num = Check_Stock();
    } else {
        printf("Editando Produto #%03.0f\n\n", ID);
        num = ID;
    }

    printf(YELLOW "Senao introduzir um valor ira voltar para o menu anterior\n" RESET);
    printf(GREEN "Nome do Produto: " RESET);
    fgets(produto, 100, stdin);
    produto[strlen(produto) - 1] = '\0';
    trimTrailing(produto);
    if (produto[0] == '\0')
        return;

    printf(GREEN "Quantidade: "
        RESET);
    scanf("%d", &quantidade);
    if (!(int) quantidade || (int) quantidade == NULL || (int) quantidade < 0)
        return;

    printf(GREEN "Preco do Produto: " RESET);
    scanf("%f", &preco);
    if (!(float) preco || (int) preco == NULL || (float) preco < 0)
        return;

    Listar_Fornecedores();
    printf(GREEN "\nColoque o ID do Fornecedor: " RESET);
    scanf("%f", &ID);
    getchar();

    // Ver Fornecedores
    sprintf(nome_ficheiro, "Fornecedores/%s%03.0f.txt", Fornecedor, ID);

    if ((FIL = fopen(nome_ficheiro, "r")) == NULL) {
        Invalid();
        return Menu_Stock();
    }
    fclose(FIL);

    Buscar_Info(1);
    strcat(Texto_Stock, info);
    Confirm();

    sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, num);
    printf("\nO produto foi guardado como: %s", nome_ficheiro);

    FIL = fopen(nome_ficheiro, "w");

    //printf("Nome: %s\n", Client_Name);
    fprintf(FIL, "%.0f\n%s\n%d\n%.2f$\n%s\n", num, produto, quantidade, preco, Texto_Stock);

    fclose(FIL);
    Confirm();
}

void Listar_Stock() {
    system("cls");
    char Linha[100];
    char *result;
    boolean found = 0;
    int nr_linha = 0;

    Quantidade_Produtos();

    for (float i = 1; i <= Nr_Produtos; i++) {
        sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, i);
        if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
            found = 1;
            nr_linha = 0;
            while (!feof(FIL)) {
                result = fgets(Linha, 100, FIL);
                if (result) {
                    if (nr_linha == 0)
                        printf("ID: ");
                    if (nr_linha == 1)
                        printf("Produto: ");
                    if (nr_linha == 2)
                        printf("Quantidade: ");
                    if (nr_linha == 3)
                        printf("Preco: ");
                    if (nr_linha == 4)
                        printf("Fornecedor: ");

                    printf(GREEN "%s"
                        RESET, Linha);
                    nr_linha++;
                }
            }
            Lines();
            printf("\n");
        }
        fclose(FIL);

    }
    if (!found) {
        printf(RED "Nao ha produtos!"
            RESET);
        Confirm();
        return Menu_Stock();
    }

    Confirm();
    return;
}

void Alterar_Stock() {
    do {
        system("cls");
        Lines();
        printf(YELLOW "\n%s"
                RESET " - "
                GREEN "Stock"
                RESET " - "
                GREEN "Editar Produtos\n\n"
                RESET, NomePrograma);

        printf("\x10 1. Adicionar Stock\n");
        printf("\x10 2. Editar Produto\n");
        printf(RED "\n9. Voltar\n"
            RESET);
        Lines();
        printf(GREEN "\nEscolha: "
            RESET);
        scanf("%s", escolha_char);
        escolha = atoi(escolha_char);
        getchar();

        switch (escolha) {
        case 1:
            Adicionar_Stock();
            break;
        case 2:
            Editar_Produto();
            break;
        case 3:
            break;
        case 9:
            Menu_Stock();
            break;
        default:
            Invalid();
            break;
        }

    } while (escolha != 9);

}

void Adicionar_Stock(){
    Listar_Stock();
        
    float ID;
    printf(YELLOW "Escolha o ID do Produto que pretende alterar: " RESET);
    scanf("%f", &ID);
    getchar();

    sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, ID);
    if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
        fclose(FIL);
        int quantia = 0;
        printf(GREEN "Quantidade Stock: " RESET);
        scanf("%d", &quantia);
        if (!(int) quantia || (int) quantia == NULL || (int) quantia < 0)
            return;
        //printf("%d", quantia);
        Modificar_Stock(quantia, 2);
    }
}

void Editar_Produto(){
    Listar_Stock();
        
    float ID;
    printf(YELLOW "Escolha o ID do Produto que pretende alterar: " RESET);
    scanf("%f", &ID);
    getchar();

    sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, ID);
    if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
        fclose(FIL);
        Inserir_Stock(ID);
    }
}

#pragma endregion

#pragma region Vendas

void Menu_Vendas() {
    do {
        system("cls");
        Lines();
        printf(YELLOW "\n%s"
            RESET " - "
            GREEN "Vendas\n\n"
            RESET, NomePrograma);
        printf("\x10 1. Inserir\n");
        printf("\x10 2. Listar\n");

        printf(RED "\n9. Voltar\n"
            RESET);
        Lines();
        printf(GREEN "\nEscolha: "
            RESET);
        scanf("%s", escolha_char);
        escolha = atoi(escolha_char);
        getchar();

        switch (escolha) {
        case 1:
            Inserir_Vendas();
            break;
        case 2:
            Listar_Vendas();
            break;
        case 9:
            Menu();
            break;
        default:
            Invalid();
            break;
        }

    } while (escolha != 9);
}

float Check_Vendas() {
    for (float i = 1; i < MaxQuantidade; i++) {
        sprintf(nome_ficheiro, "Vendas/%s%03.0f.txt", Venda, i);
        if ((FIL = fopen(nome_ficheiro, "r")) == NULL) {
            fclose(FIL);
            return i;
        }
    }
}

void Inserir_Vendas() {
    system("cls");
    char venda[100];

    float ID;
    float num;

    char Texto_Cliente[1000] = {};
    char Texto_Stock[1000] = {};

    printf("Insercao de uma Venda\n\n");

    printf(YELLOW "Senao introduzir um valor ira voltar para o menu anterior\n"
        RESET);
    Confirm();

    Listar_Clientes();
    printf(GREEN "Coloque o ID do cliente que comprou: "
        RESET);
    scanf("%f", &ID);
    getchar();

    // Ver Clientes
    sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, ID);

    if ((FIL = fopen(nome_ficheiro, "r")) == NULL) {
        Invalid();
        return Menu_Vendas();
    }
    fclose(FIL);

    Buscar_Info(1);
    strcat(Texto_Cliente, info);
    Buscar_Info(2);
    strcat(Texto_Cliente, info);
    Buscar_Info(3);
    strcat(Texto_Cliente, info);
    Confirm();

    Listar_Stock();
    int TemStock = 0;
    int quantia = 0;
    printf(GREEN "Coloque o ID do produto que comprou\n"
        RESET);

    while (!TemStock) {
        printf(YELLOW "ID: "
            RESET);
        scanf("%f", &ID);
        getchar();

        sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, ID);

        if ((FIL = fopen(nome_ficheiro, "r")) == NULL) {
            Invalid();
            return Menu_Vendas();
        }
        fclose(FIL);

        // Ver se tem Stock?
        Buscar_Info(2);
        quantia = atoi(info);
        if (quantia > 0)
            TemStock = 1;
        else
            printf(RED "Esse produto nao tem Stock!\n" RESET);
    }

    quantia--;
    //printf("%d", quantia);
    Modificar_Stock(quantia, 2);

    Buscar_Info(1);
    strcat(Texto_Stock, info);
    Buscar_Info(3);
    strcat(Texto_Stock, info);
    Confirm();

    num = Check_Vendas();

    sprintf(nome_ficheiro, "Vendas/%s%03.0f.txt", Venda, num);
    printf("\nO produto foi guardado como: %s", nome_ficheiro);

    FIL = fopen(nome_ficheiro, "w");

    fprintf(FIL, "%.0f\n%s%s", num, Texto_Cliente, Texto_Stock);

    fclose(FIL);
    Confirm();
}

void Listar_Vendas() {
    system("cls");
    char Linha[100];
    char * result;
    boolean found = 0;
    int nr_linha = 0;

    Quantidade_Vendas();

    for (float i = 1; i <= Nr_Vendas; i++) {
        sprintf(nome_ficheiro, "Vendas/%s%03.0f.txt", Venda, i);
        if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
            found = 1;
            nr_linha = 0;
            while (!feof(FIL)) {
                result = fgets(Linha, 100, FIL);
                if (result) {
                    if (nr_linha == 0)
                        printf(YELLOW "Venda #");
                    if (nr_linha == 1)
                        printf(RESET "Nome Cliente: ");
                    if (nr_linha == 2)
                        printf("Morada: ");
                    if (nr_linha == 3)
                        printf("NIF: ");

                    if (nr_linha == 4)
                        printf("\nProduto Comprado: ");
                    if (nr_linha == 5)
                        printf("Preco Produto: ");

                    printf(GREEN "%s"
                        RESET, Linha);
                    nr_linha++;
                }
            }
            printf("\n");
            Lines();
            printf("\n");
        }
        fclose(FIL);
    }
    if (!found) {
        printf(RED "Nao ha vendas!"
            RESET);
        Confirm();
        return Menu_Vendas();
    }

    Confirm();
    return;
}


#pragma endregion

#pragma region Fornecedores

void Menu_Fornecedores() {
    do {
        system("cls");
        Lines();
        printf(YELLOW "\n%s"
            RESET " - "
            GREEN "Fornecedores\n\n"
            RESET, NomePrograma);
        printf("\x10 1. Inserir\n");
        printf("\x10 2. Listar\n");
        printf("\x10 3. Alterar\n");

        printf(RED "\n9. Voltar\n"
            RESET);
        Lines();
        printf(GREEN "\nEscolha: "
            RESET);
        scanf("%s", escolha_char);
        escolha = atoi(escolha_char);
        getchar();

        switch (escolha) {
        case 1:
            Inserir_Fornecedor((float) 0);
            break;
        case 2:
            Listar_Fornecedores();
            break;
        case 3:
            Alterar_Fornecedores();
            break;
        case 9:
            Menu();
            break;
        default:
            Invalid();
            break;
        }

    } while (escolha != 9);
}

float Check_Fornecedores() {
    for (float i = 1; i < MaxQuantidade; i++) {
        sprintf(nome_ficheiro, "Fornecedores/%s%03.0f.txt", Fornecedor, i);
        if ((FIL = fopen(nome_ficheiro, "r")) == NULL) {
            fclose(FIL);
            return i;
        }
    }
}
void Inserir_Fornecedor(float ID) {
    system("cls");
    char name[100];

    int contato;
    float num;

    if ((int) ID == 0) {
        printf("Insercao de um Fornecedor\n\n");
        num = Check_Fornecedores();
    } else {
        printf("Editando Fornecedor #%03.0f\n\n", ID);
        num = ID;
    }

    printf(YELLOW "Senao introduzir um valor (ou valor incorreto) ira voltar para o menu anterior\n"
        RESET);

    printf(GREEN "Nome do Fornecedor: " RESET);
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = '\0';
    trimTrailing(name);
    if (name[0] == '\0')
        return;

    printf(GREEN "Contato do Fornecedor: " RESET);
    scanf("%d", &contato);
    if (!(int) contato || (int) contato == NULL || (int) contato < 0)
        return;

    sprintf(nome_ficheiro, "Fornecedores/%s%03.0f.txt", Fornecedor, num);
    printf("\nO Fornecedor foi guardado como: %s", nome_ficheiro);

    FIL = fopen(nome_ficheiro, "w");

    fprintf(FIL, "%.0f\n%s\n%d\n", num, name, contato);

    fclose(FIL);
    Confirm();
}

void Listar_Fornecedores() {
    system("cls");
    char Linha[100];
    char *result;
    boolean found = 0;
    int nr_linha = 0;

    Quantidade_Fornecedores();

    for (float i = 1; i <= Nr_Fornecedores; i++) {
        sprintf(nome_ficheiro, "Fornecedores/%s%03.0f.txt", Fornecedor, i);
        if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
            found = 1;
            nr_linha = 0;
            while (!feof(FIL)) {
                result = fgets(Linha, 100, FIL);
                if (result) {
                    if (nr_linha == 0)
                        printf("ID: ");
                    if (nr_linha == 1)
                        printf("Fornecedor: ");
                    if (nr_linha == 2)
                        printf("Contato: ");

                    printf(GREEN "%s"
                        RESET, Linha);
                    nr_linha++;
                }
            }
            Lines();
            printf("\n");
        }
        fclose(FIL);
    }
    if (!found) {
        printf(RED "Nao foi encontrado Fornecedores!"
            RESET);
        Confirm();
        return Menu_Fornecedores();
    }

    Confirm();
    return;
}

void Alterar_Fornecedores() {
    float ID;

    Listar_Fornecedores();

    printf(YELLOW "Escolha o ID do Fornecedor que pretende alterar: "
        RESET);
    scanf("%f", &ID);
    getchar();

    sprintf(nome_ficheiro, "Fornecedores/%s%03.0f.txt", Fornecedor, ID);

    if ((FIL = fopen(nome_ficheiro, "r")) != NULL) {
        fclose(FIL);
        Inserir_Fornecedor(ID);
    }
}

#pragma endregion



#pragma region Useful Functions

void Buscar_Info(int line_nr) {
    info[0] = '\0';
    memset(info, 0, sizeof info);
    FILE * file = fopen(nome_ficheiro, "r");
    int count = 0;
    if (file != NULL) {
        char line[MAX];
        while (fgets(line, sizeof line, file) != NULL) {
            if (count == line_nr) {
                return strcpy(info, line);
            } else {
                count++;
            }
        }
        fclose(file);
    }
}

void Modificar_Stock(int quantia, int line_nr) {
    FILE * fptr1, * fptr2;
    int lno, linectr = 0;
    char str[MAX], fname[MAX];
    char newln[MAX], temp[] = "temp.txt";

    strcpy(fname, nome_ficheiro);
    fptr1 = fopen(fname, "r");
    fptr2 = fopen(temp, "w");
    /* Obter a nova linha do utilizador */
    sprintf(newln, "%d", quantia);
    /* Obter o número da linha para apagar a linha específica */
    lno = line_nr;
    lno++;
    // Copiar todo o conteúdo para o ficheiro temporário outro excepto linha específica
    while (!feof(fptr1)) {
        strcpy(str, "\0");
        fgets(str, MAX, fptr1);
        if (!feof(fptr1)) {
            linectr++;
            if (linectr != lno) {
                fprintf(fptr2, "%s", str);
            } else {
                fprintf(fptr2, "%s\n", newln);
            }
        }
    }
    fclose(fptr1);
    fclose(fptr2);

    ChangeFileNames();
}

void ChangeFileNames() {
    FILE * fp1, * fp2;
    char ch;

    fp1 = fopen("temp.txt", "r");
    fp2 = fopen(nome_ficheiro, "w");

    while (1) {
        ch = fgetc(fp1);

        if (ch == EOF)
            break;
        else
            putc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);
}

void trimTrailing(char * str) {
    int index, i;

    /* Default */
    index = -1;

    /* Encontrar o último carácter de espaço "não-branco" */
    i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            index = i;

        i++;
    }

    /*  Marcar o próximo carácter para o último carácter de espaço não-branco como NULL */
    str[index + 1] = '\0';
}

#pragma endregion