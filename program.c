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
void Invalid() {printf(RED "\nEscolha Invalida!\n" RESET);}
void Lines() { printf("====================");}

//Program
void main() {
    Menu();
}

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
                Menu_Produtos();
                break;
             case 9:
                printf("Ate Amanha!\n");
                break;
             default:
                Invalid();
                break;
         }

        } while (escolha != 9);
}

void Menu_Produtos() {
    do
        {
         system("cls");
         Lines();
         printf(YELLOW "\n%s" RESET " - " GREEN "Produtos\n\n" RESET, NomePrograma);
         printf("1. Visualizar\n");
         printf("2. Inserir\n");
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
                 printf("Ola");
                  break;
             case 2:
                 printf("Ola");
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
