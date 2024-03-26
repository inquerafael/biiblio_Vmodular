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

  return 1;
}

void imprimirHist(Emprestimo *emprestimos, int quantEmprestimos) {
  if (quantEmprestimos != 0) {
    printf("\n==== HISTORICO DE EMPRESTIMOS ====\n\n");
  }
}