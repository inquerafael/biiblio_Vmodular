#include "emprestimo.h"
#include "livro.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

int emprestar(Emprestimo **emprestimos, int *quantEmprestimos) {
  int tamahoAtual = *quantEmprestimos + 1;
  Emprestimo *novoEmprestimo =
      (Emprestimo *)realloc(*emprestimos, tamahoAtual * sizeof(Emprestimo));

  if (novoEmprestimo == NULL) {
    printf("Erro ao alocar memoria");
    return 0;
  }

  printf("Digite o ID do livro: ");
  scanf("%d", &novoEmprestimo[*quantEmprestimos].livro.id);
  printf("Digite o ID do usuario: ");
  scanf("%d", &novoEmprestimo[*quantEmprestimos].usuario.id);
  printf("Digite a data de emprestimo: ");
  scanf("formato dd/mm/aa: %s",
        novoEmprestimo[*quantEmprestimos].dataEmprestimo);
  printf("Digite a data de devolucao: ");
  scanf("formato dd/mm/aa: %s",
        novoEmprestimo[*quantEmprestimos].dataDevolucao);

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