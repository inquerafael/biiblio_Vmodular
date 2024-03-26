#ifndef usuario_h
#define usuario_h

typedef struct {
  char *nome;
  char *numero;
  int id;
  int flag;
  int emprestimos[3];
} Usuario;

int cadastroUsuario(Usuario **usuarios, int *quantUsuarios);
void imprimeU(Usuario *usuarios, int *posicao);
int buscaU(Usuario *usuarios, int posicao);
void removeUsuario(Usuario **usuarios, int *posicao);

#endif // usuario_h