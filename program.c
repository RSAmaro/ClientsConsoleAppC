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
char NomePrograma[50] = "Coutaro";
char escolha_char[3];
int escolha = 0;

//Respostas
void Invalid() {printf(RED "\nEscolha Invalida!\n" RESET); printf("\nPressiona ENTER para continuar\n"); getch(); }
void Lines() { printf("====================");}

//Program
void main() {
    Menu();
}

// MENUS
#pragma region Menu
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
            case 1:
                break;
            case 2:
                Menu_Stock();
                break;
            case 3:
                Menu_Clientes();
                break;
            case 9:
                
                break;
            default:
                Invalid();
              
                break;
         }

        } while (escolha != 9);
}

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
             case 1:
                Inserir_Cliente();
                break;
             case 2:
                
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
             case 1:
                //Stock_Inserir();
                break;
             case 2:
                 
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
#pragma endregion

// CLIENTES
#pragma region Clientes
void Inserir_Clientes() {
    FILE *ficheiro;
    
    char nome_ficheiro[100];
    char nome[100] = "Cliente";
    char Client_Name[100];

    for (float i = 0; i < 5; i++)
    {
        sprintf(nome_ficheiro, "%s%03.0f.txt", nome, i+1);
        printf("\n%s", nome_ficheiro);
      
        ficheiro = fopen(nome_ficheiro, "w");
        printf("Nome: ");
        scanf("%s", Client_Name);

        printf("Nome: %s\n", Client_Name);

        fprintf(ficheiro, "Nome: %s\n", Client_Name);

        fclose(ficheiro);
    }
}


void Inserir_Cliente() {
   system("cls"); 
   Inserir_Clientes();

   printf("\nPressiona ENTER para continuar\n");
   getch();   
}
#pragma endregion