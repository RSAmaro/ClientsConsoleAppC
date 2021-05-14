// Librarias
#include <stdio.h>
#include <windows.h>

// Cores do programa
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

//Variaveis
FILE *FIL;
int MaxQuantidade = 1000;
char NomePrograma[50] = "Coutaro";
char nome_ficheiro[100];

char escolha_char[3];
int escolha;

char Cliente[100] = "Cliente";
float Nr_Clientes;

char Stock[100] = "Produto";
float Nr_Produtos;

#pragma region Quantidades
// Quantidades
void Quantidade_Clientes() {
    Nr_Clientes = 0;
    for (float i = MaxQuantidade; i > 0; i--)
        {
            sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, i);
            if ((FIL = fopen(nome_ficheiro,"r")) != NULL){
                fclose(FIL);
                Nr_Clientes = i;
                break;
            }
        }
}

void Quantidade_Produtos() {
    Nr_Produtos = 0;
    for (float i = MaxQuantidade; i > 0; i--)
        {
            sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, i);
            if ((FIL = fopen(nome_ficheiro,"r")) != NULL){
                fclose(FIL);
                Nr_Produtos = i;
                break;
            }
        }
}
#pragma endregion

//Respostas
void Invalid() {printf(RED "\nEscolha Invalida!\n" RESET); Confirm(); }
void Lines() { printf(CYAN "====================" RESET);}
void Confirm() {printf("\nPressiona ENTER para continuar\n"); getch(); }

//Program
void main() {
    Menu();
}

// MENU PRINCIPAL
void Menu() {
    do
        {   
         system("cls");
         Lines();
         printf(YELLOW "\n%s\n\n" RESET, NomePrograma);
         printf("\x10 1. Vendas\n");
         printf("\x10 2. Stock\n");
         printf("\x10 3. Clientes\n");
         printf("\x10 4. Fornecedores\n");

         printf(RED "\n9. Sair\n" RESET);
         Lines();
         printf(GREEN "\nEscolha: " RESET);
         scanf("%s",escolha_char);
         escolha = atoi(escolha_char);
         getchar();

         switch (escolha)
         {
            case 1: break;
            case 2: Menu_Stock(); break;
            case 3: Menu_Clientes(); break;
            case 9: break;
            default: Invalid(); break;
         }

        } while (escolha != 9);
}

// CLIENTES
#pragma region Clientes

void Menu_Clientes() {
    do
        {  
         system("cls");
         Lines();
         printf(YELLOW "\n%s" RESET " - " GREEN "Clientes\n\n" RESET, NomePrograma);
         printf("\x10 1. Inserir\n");
         printf("\x10 2. Listar\n");
         printf("\x10 3. Alterar\n");

         printf(RED "\n9. Voltar\n" RESET);
         Lines();
         printf(GREEN "\nEscolha: " RESET);
         scanf("%s",escolha_char);
         escolha = atoi(escolha_char);
         getchar();

         switch (escolha)
         {
             case 1: Inserir_Cliente(0); break;
             case 2: Listar_Clientes(); break;
             case 3: Alterar_Clientes(); break;

             case 9: Menu(); break;
             default: Invalid(); break;
         }

        } while (escolha != 9);
}

float Check_Clientes() {
    for (float i = 1; i < MaxQuantidade; i++)
    {
        sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, i);
        if ((FIL = fopen(nome_ficheiro,"r")) == NULL){
            fclose(FIL);
            return i;
        }
    }
}
void Inserir_Cliente(float ID) {
    system("cls");
    char name[100];
    char morada[100];
    
    float num;

    if(ID == 0){
        printf("Insercao de um cliente\n\n");
        num = Check_Clientes();
    }    
    else{
        printf("Editando Cliente #%03.0f\n\n", ID);
        num = ID;
    }
    
    printf(YELLOW "Senao introduzir um valor ira voltar para o menu anterior\n" RESET);
    printf(GREEN "Nome do Cliente: " RESET);
    fgets(name, 100, stdin);
    name[strlen(name)-1]='\0';
    if(name[0] == '\0')
        return;

    printf(GREEN "Morada do Cliente: " RESET);    
    fgets(morada, 100, stdin);
    morada[strlen(morada)-1]='\0';
    if(morada[0] == '\0')
        return;

    sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, num);
    printf("\nO cliente foi guardado como: %s", nome_ficheiro);
      
    FIL = fopen(nome_ficheiro, "w");

    //printf("Nome: %s\n", Client_Name);
    fprintf(FIL, "ID:%.0f\nNome:%s\nMorada:%s\n", num, name, morada);

    fclose(FIL);
    Confirm();
}

void Listar_Clientes() {
    system("cls");
    char Linha[100];
    char *result;
    boolean found = 0;

    Quantidade_Clientes();

    for (float i = 1; i <= Nr_Clientes; i++)
    {
        sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, i);
        if ((FIL = fopen(nome_ficheiro,"r")) != NULL) {
            found = 1;
            while (!feof(FIL))
            {
                result = fgets(Linha, 100, FIL);
                    if(result)
                        printf(GREEN "%s" RESET, Linha);
            }
            printf("\n");
        }
        fclose(FIL);

        if ((int)i % 10 == 0)
            Confirm();
    }
     if(!found)
        printf(RED "Nao foi encontrado Clientes!" RESET);

    Confirm();
    return;
}

void Remover_Clientes(float ID) {
    system("cls");
    sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, ID);
    remove(nome_ficheiro);
    printf("Apagado com Sucesso!");
    Confirm();
}

void Alterar_Clientes() {
    float ID;
    Listar_Clientes();

    printf(YELLOW "Escolha o ID do utilizador que pretende alterar: " RESET);
    scanf("%f",&ID);
    getchar();

    sprintf(nome_ficheiro, "Clientes/%s%03.0f.txt", Cliente, ID);

    if ((FIL = fopen(nome_ficheiro,"r")) != NULL){
        Lines();
        printf("\n\x10 1. Editar");
        printf("\n\x10 2. Apagar");
        printf(RED "\n\x10 3. Cancelar" RESET);
        printf(GREEN "\nEscolha: " RESET);
        scanf("%s",escolha_char);
        escolha = atoi(escolha_char);
        getchar();
        fclose(FIL);
        
         switch (escolha)
         {
             case 1: Inserir_Cliente(ID); break;
             case 2: Remover_Clientes(ID); break;
             default: return;
         }        
    }

}

#pragma endregion

#pragma region Stocks
void Menu_Stock() {
    do
        {
         system("cls");
         Lines();
         printf(YELLOW "\n%s" RESET " - " GREEN "Stock\n\n" RESET, NomePrograma);
         printf("1. Inserir\n");
         printf("2. Listar\n");
         printf("3. Alterar\n");

         printf(RED "\n9. Voltar\n" RESET);
         Lines();
         printf(GREEN "\nEscolha: " RESET);
         scanf("%s",escolha_char);
         escolha = atoi(escolha_char);
         getchar();

         switch (escolha)
         {
             case 1: Inserir_Stock(0); break;
             case 2: Listar_Stock(); break;
             case 3: break;
             case 4: break;
             case 9: Menu(); break;
             default: Invalid(); break;
         }

        } while (escolha != 9);
}

float Check_Stock() {
    for (float i = 1; i < MaxQuantidade; i++)
    {
        sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, i);
        if ((FIL = fopen(nome_ficheiro,"r")) == NULL){
            fclose(FIL);
            return i;
        }
    }
}

void Inserir_Stock(float ID) {
    system("cls");
    char produto[100];
    int quantidade = 0;
    float preco;
    float num;

    if(ID == 0){
        printf("Insercao de um Produto\n\n");
        num = Check_Stock();
    }    
    else{
        printf("Editando Produto #%03.0f\n\n", ID);
        num = ID;
    }
    
    printf(YELLOW "Senao introduzir um valor ira voltar para o menu anterior\n" RESET);
    printf(GREEN "Nome do Produto: " RESET);
    fgets(produto, 100, stdin);
    produto[strlen(produto)-1]='\0';
    if(produto[0] == '\0')
    return;

    printf(GREEN "Quantidade: " RESET);    
    scanf("%d", &quantidade);
    if(!(int)quantidade)
    return;

    printf(GREEN "Preco do Produto: " RESET);    
    scanf("%f", &preco);
    if(!(float)preco)
    return;

    sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, num);
    printf("\nO produto foi guardado como: %s", nome_ficheiro);
      
    FIL = fopen(nome_ficheiro, "w");

    //printf("Nome: %s\n", Client_Name);
    fprintf(FIL, "ID:%.0f\nProduto:%s\nQuantidade:%d\nPreco:%.2f$\n", num, produto, quantidade, preco);

    fclose(FIL);
    Confirm();
}

void Listar_Stock() {
    system("cls");
    char Linha[100];
    char *result;
    boolean found = 0;

    Quantidade_Produtos();

    for (float i = 1; i <= Nr_Produtos; i++)
    {
        sprintf(nome_ficheiro, "Stock/%s%03.0f.txt", Stock, i);
        if ((FIL = fopen(nome_ficheiro,"r")) != NULL) {
            found = 1;
            while (!feof(FIL))
            {
                result = fgets(Linha, 100, FIL);
                    if(result)
                        printf(GREEN "%s" RESET, Linha);
            }
            printf("\n");
        }
        fclose(FIL);

        if ((int)i % 10 == 0)
            Confirm();
    }
     if(!found)
        printf(RED "Nao ha produtos!" RESET);

    Confirm();
    return;
}

#pragma endregion



#pragma region Obsolete


#pragma endregion