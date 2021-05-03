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
                Menu_Stock();
                break;
            case 9:
                
                break;
            default:
                Invalid();
                Sleep(1000);
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
                Stock_Inserir();
                break;
             case 2:
                 
                break;
             case 9:
                Menu();
                break;
             default:
                Invalid();
                Sleep(1000);
                break;
         }

        } while (escolha != 9);
}


// STOCK

void Check_Stock() {
    FILE *ficheiro;
    
    char nome_ficheiro[100];
    char nome[100] = "Produto";

    for (float i = 0; i < 5; i++)
    {
        sprintf(nome_ficheiro, "%s%03.0f.txt", nome, i+1);
        printf("\n%s", nome_ficheiro);
      
        ficheiro = fopen(nome_ficheiro, "w");

        fprintf(ficheiro, "Ta da!!");  
        fclose(ficheiro);
    }
}


void Stock_Inserir() {
   system("cls"); 
   Check_Stock();

   printf("\nPressiona ENTER para continuar\n");
    getch();   
}
