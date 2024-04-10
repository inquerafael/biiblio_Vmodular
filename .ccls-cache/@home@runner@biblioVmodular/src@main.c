#include "../include/emprestimo.h"
#include "../include/livro.h"
#include "../include/usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int menu() {
  int opcao;
  printf("\n==== MENU ====\n\n");
  printf("1 - Area de Livros\n");
  printf("2 - Area do usuario\n");
  printf("3 - Area de emprestimos\n");
  printf("4 - Arq. Usuario(teste_Arqui.)\n"); // teste
  printf("0 - Sair\n\n");
  printf("Digite a opcao: ");
  scanf("%d", &opcao);
  return opcao;
}
int menuLivro() {
  int opcao;
  printf("\n==== MENU L ====\n\n");
  printf("1 - Cadastro de livro\n");
  printf("2 - Listar livros\n");
  printf("3 - Remove livro\n");
  printf("4 - Modificar cadastro\n");
  printf("0 - Sair\n\n");
  printf("Digite a opcao: ");
  scanf("%d", &opcao);
  return opcao;
}
int menuUsuario() {
  int opcao;
  printf("\n==== MENU U ====\n\n");
  printf("1 - Cadastro de usuario\n");
  printf("2 - Listar usuarios\n");
  printf("3 - Remove usuario\n");
  printf("0 - Sair\n\n");
  printf("Digite a opcao: ");
  scanf("%d", &opcao);
  return opcao;
}
int menuEmprestimos() {
  int opcao;
  printf("\n==== MENU E ====\n\n");
  printf("1 - Fazer emprestimo\n");
  printf("2 - Historico de emprestimos\n");
  printf("0 - Sair\n\n");
  printf("Digite a opcao: ");
  scanf("%d", &opcao);
  return opcao;
}
void Limpar() {
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);

  const char *MOVE_CURSOR_HOME = "\e[H";
  write(STDOUT_FILENO, MOVE_CURSOR_HOME, 3);
}

int main(void) {

  Livro *livros = NULL;
  Usuario *usuarios = NULL;
  Emprestimo *emprestimos = NULL;
  FILE *emprest;

  int quantLivros = 0, posicaoU = 0, posicaoE = 0, opcao = -1, opcaoU = -1,
      opcaoL = -1, opcaoE = -1;
  do {
    opcao = menu();

    switch (opcao) {
    case 1:
      do {
        opcaoL = menuLivro();

        switch (opcaoL) {
        case 1:
          Limpar();
          cadastroLivro(&livros, &quantLivros);
          break;
        case 2:
          Limpar();
          imprime(livros, &quantLivros);
          break;
        case 3:
          removeLivro(&livros, &quantLivros);
          break;
        case 4:
          modificaLivro(livros, quantLivros);
          break;
        case 0:
          Limpar();
          printf("Saindo...\n");
          break;
        default:
          printf("Opcao invalida\n");
        }
      } while (opcaoL != 0);
      break;
    case 2:
      do {
        opcaoU = menuUsuario();

        switch (opcaoU) {
        case 1:
          Limpar();
          cadastroUsuario(&usuarios, &posicaoU);
          break;
        case 2:
          Limpar();
          imprimeU(usuarios, &posicaoU);
          break;
        case 3:
          removeUsuario(&usuarios, &posicaoU);
          break;
        case 0:
          Limpar();
          printf("Saindo...\n");
          break;
        }
      } while (opcaoU != 0);
      break;
    case 3:
      do {
        opcaoE = menuEmprestimos();
        switch (opcaoE) {
        case 1:
          Limpar();
          emprestar(&emprestimos, &posicaoE);
          break;
        case 2:
          Limpar();
          imprimirHist(emprestimos, posicaoE);
          break;
        default:
          printf("Opcao invalida\n");
        }
      } while (opcaoE != 0);
      break;
    case 4:

      salvaUsuario(emprest, &usuarios, posicaoU);
      break;
    default:
      printf("Opcao invalida\n");
    }
  } while (opcao != 0);

  return 0;
}