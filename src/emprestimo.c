#include "../include/emprestimo.h"
#include "../include/livro.h"
#include "../include/usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int emprestar(Emprestimo **emprestimos, int *quantEmprestimos) {
  int tamahoAtual = *quantEmprestimos + 1;
  Emprestimo *novoEmprestimo =
      (Emprestimo *)realloc(*emprestimos, tamahoAtual * sizeof(Emprestimo));

  if (novoEmprestimo == NULL) {
    printf("Erro ao alocar memoria");
    return 0;
  }

  time_t tempo;
  tempo = time(NULL);
  struct tm *tm = localtime(&tempo);
  int data_atual =
      (tm->tm_year + 1900) * 10000 + (tm->tm_mon + 1) * 100 + tm->tm_mday;

  printf("Digite o ID do livro: ");
  scanf("%d", &novoEmprestimo[*quantEmprestimos].livro.id);
  printf("Digite o ID do usuario: ");
  scanf("%d", &novoEmprestimo[*quantEmprestimos].usuario.id);

  novoEmprestimo[*quantEmprestimos].dataEmprestimo = malloc(11 * sizeof(char));
  sprintf(novoEmprestimo[*quantEmprestimos].dataEmprestimo, "%d% 02d% 02d",
          tm->tm_mday - 1, tm->tm_mon + 1, tm->tm_year + 1900);

  novoEmprestimo[*quantEmprestimos].dataDevolucao = malloc(11 * sizeof(char));
  sprintf(novoEmprestimo[*quantEmprestimos].dataEmprestimo, "%d% 02d% 02d",
          (tm->tm_mday - 1) + 5, tm->tm_mon + 1, tm->tm_year + 1900);

  *emprestimos = novoEmprestimo;
  (*quantEmprestimos)++;

  return 1;
}

void imprimirHist(Emprestimo *emprestimos, int quantEmprestimos) {
  if (quantEmprestimos != 0) {
    printf("\n==== HISTORICO DE EMPRESTIMOS ====\n\n");
    for (int i = 0; i < quantEmprestimos; i++) {
      printf("ID do livro: %d\n", emprestimos[i].livro.id);
      printf("ID do usuario: %d\n", emprestimos[i].usuario.id);
      printf("Data de emprestimo: %s\n", emprestimos[i].dataEmprestimo);
      printf("Data de devolucao: %s\n", emprestimos[i].dataDevolucao);
      printf("----------------------\n");
    }
  }
}

