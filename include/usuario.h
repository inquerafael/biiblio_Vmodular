#ifndef usuario_h
#define usuario_h
#include <stdio.h>

typedef struct {
  int id;
  char *nome;
  char *numero;
  int flag;
  int emprestimos;
} Usuario;

int cadastroUsuario(Usuario **usuarios, int *quantUsuarios);
void imprimeU(Usuario *usuarios, int *posicao);
int buscaU(Usuario *usuarios, int posicao);
void removeUsuario(Usuario **usuarios, int *posicao);
void salvaUsuario(FILE *arquivo, Usuario **usuarios, int quantUsuarios);
void carregaUsuario(Usuario **usuarios, int *quantUsuarios);

#endif // usuario_h