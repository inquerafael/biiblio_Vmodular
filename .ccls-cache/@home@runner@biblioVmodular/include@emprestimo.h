#ifndef emprestimo_h
#define emprestimo_h
#include "livro.h"
#include "usuario.h"
#include <stdio.h>

typedef struct {
  Livro livro;
  Usuario usuario;
  char *dataEmprestimo;
  char *dataDevolucao;
} Emprestimo;

int emprestar(Emprestimo **emprestimos, int *quantEmprestimos);

void imprimirHist(Emprestimo *emprestimos, int quantEmprestimos);


#endif // emprestimo_hs