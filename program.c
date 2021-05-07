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
int MaxQuantidade = 99999999;
char NomePrograma[50] = "Coutaro";
char nome_ficheiro[100];

char escolha_char[3];
int escolha;

char Cliente[100] = "Cliente";

//Respostas
void Invalid() {printf(RED "\nEscolha Invalida!\n" RESET); Confirm(); }
void Lines() { printf("====================");}
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
         printf("1. Vendas\n");
         printf("2. Stock\n");
         printf("3. Clientes\n");
         printf("4. Fornecedores\n");

         printf(RED "\n9. Sair\n" RESET);
         Lines();
         printf(GREEN "\nEscolha: " RESET);
         scanf("%s",escolha_char);
         escolha = atoi(escolha_char);

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
         printf("1. Inserir\n");
         printf("2. Listar\n");
         printf("3. Editar\n");
         printf("4. Eliminar\n");

         printf(RED "\n9. Voltar\n" RESET);
         Lines();
         printf(GREEN "\nEscolha: " RESET);
         scanf("%s",escolha_char);
         escolha = atoi(escolha_char);

         switch (escolha)
         {
             case 1: Inserir_Cliente(); break;
             case 2: break;
             case 3: break;
             case 4: break;
             case 9: Menu(); break;
             default: Invalid(); break;
         }

        } while (escolha != 9);
}

float Check_Clientes() {
    FILE *fptr;
    for (float i = 1; i < MaxQuantidade; i++)
    {
        sprintf(nome_ficheiro, "%s%03.0f.txt", Cliente, i);
        if ((fptr = fopen(nome_ficheiro,"r")) == NULL)
            return i;
        
        fclose(fptr);
    }
}

void Inserir_Cliente() {
    system("cls");
    FILE *FIL;
    char Client_Name[100];
    float num = Check_Clientes();
    
    printf("Insercao de um cliente\n\n");
    printf("Nome do Cliente: ");
    scanf("%s", Client_Name);

    sprintf(nome_ficheiro, "%s%03.0f.txt", Cliente, num);
    printf("\nO cliente foi guardado como: %s", nome_ficheiro);
      
    FIL = fopen(nome_ficheiro, "w");

    //printf("Nome: %s\n", Client_Name);
    fprintf(FIL, "Nome: %s\n", Client_Name);

    fclose(FIL);
    Confirm();
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
         printf("3. Editar\n");
         printf("4. Eliminar\n");

         printf(RED "\n9. Voltar\n" RESET);
         Lines();
         printf(GREEN "\nEscolha: " RESET);
         scanf("%s",escolha_char);
         escolha = atoi(escolha_char);

         switch (escolha)
         {
             case 1: break;
             case 2: break;
             case 3: break;
             case 4: break;
             case 9: Menu(); break;
             default: Invalid(); break;
         }

        } while (escolha != 9);
}
#pragma endregion