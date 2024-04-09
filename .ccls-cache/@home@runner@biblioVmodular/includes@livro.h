#ifndef biblio_vM_h
#define biblio_vM_h

typedef struct {
  char titulo[50];
  char autor[30];
  int quanti;
  int id;
  int flag; // 1 ativo | 0 inativo
} Livro;

int cadastroLivro(Livro **livros, int *quantLivros);
void imprime(Livro *livros, int *posicao);
int busca(Livro *livros, int posicao);
void removeLivro(Livro **livros, int *posicao);
void modificaLivro(Livro *livros, int posicao);

#endif // biblio_vM_h