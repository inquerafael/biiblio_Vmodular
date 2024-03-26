#include "emprestimo.h"
#include "livro.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

int cadastroEmprestimo(Emprestimo **emprestimos, int *quantEmprestimos) {
  int tamanhoAtual = *quantEmprestimos;
  Emprestimo *novoEmprestimo =
      (Emprestimo *)realloc(*emprestimos, tamanhoAtual * sizeof(Emprestimo));

  if (novoEmprestimo == NULL) {
    printf("Erro ao alocar memoria");
    return 0;
  }

  printf("Digite a data de emprestimo: ");
  scanf("%s", novoEmprestimo[*quantEmprestimos].dataEmprestimo);
  printf("Digite a data de devolucao: ");
  scanf("%s", novoEmprestimo[*quantEmprestimos].dataDevolucao);
  novoEmprestimo[*quantEmprestimos].id = *quantEmprestimos + 1;

  *emprestimos = novoEmprestimo;
  (*quantEmprestimos)++;
  return 1;
}