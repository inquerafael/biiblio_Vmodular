#include "../include/livro.h"
#include <stdio.h>
#include <stdlib.h>

int cadastroLivro(Livro **livros, int *quantLivros) {
  int tamahoAtual = *quantLivros + 1;
  Livro *novoLivro = (Livro *)realloc(*livros, tamahoAtual * sizeof(Livro));

  if (novoLivro == NULL) {
    printf("Erro ao alocar memoria");
    return 0;
  }
  printf("Digite o titulo do livro: ");
  scanf("%s", novoLivro[*quantLivros].titulo);
  printf("Digite o autor do livro: ");
  scanf("%s", novoLivro[*quantLivros].autor);
  printf("Digite a quantidade de livros: ");
  scanf("%d", &novoLivro[*quantLivros].quanti);
  novoLivro[*quantLivros].id = *quantLivros + 1;
  novoLivro[*quantLivros].flag = 1;

  *livros = novoLivro;
  (*quantLivros)++;
  return 1;
}

void imprime(Livro *livros, int *quant) {

  if (*quant != 0) {
    printf("\n==== ACERVOs ====\n\n");
    for (int i = 0; i < *quant; i++) { // percorre o vetor
      if (livros[i].flag != 0) {
        printf("ID: %d\n", livros[i].id);
        printf("Autor: %s\n", livros[i].autor);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Quantidade: %d\n", livros[i].quanti);
        printf("----------------------\n");
      } else {
        printf("Este livro foi removido.\n");
      }
    }
  } else {
    printf("Não há livros cadastrados.\n");
  }
}

int busca(Livro *livros, int quant) {

  int indice = -1, id = 0;

  printf("\n==== BUSCAR ====\n\n");
  printf("ID do livro: ");
  scanf("%d", &id);
  for (int i = 0; i < quant; i++) {
    if (id == livros[i].id) {
      indice = i;
      return indice;
      break;
    }
  }
  printf("Titulo não encontrado\n");
  
  return 0;
}

void removeLivro(Livro **livros, int *quant) {

  int indice = busca(*livros, *quant);

  if (indice != -1 && livros[indice]->flag == 1) {
    for (int i = indice; i < *quant - 1; i++) {
      // move os livros para preencher o espaco vazio
      livros[i]->flag = 0;
    }
    (*quant)--; // decrementa o contador de livros
    printf("\nLivro removido com sucesso!\n");
  } else {
    printf("\nLivro nao encontrado.\n");
  }
}

void modificaLivro(Livro *livros, int posicao) {
  int indice = busca(livros, posicao);
  if (indice != -1 && livros[indice].flag == 1) {

    printf("Digite o novo autor: ");
    scanf("%s", livros[indice].autor);
    printf("Digite o novo titulo: ");
    scanf("%s", livros[indice].titulo);
    printf("Digite a nova quantidade: ");
    scanf("%d", &livros[indice].quanti);
    printf("Livro modificado com sucesso!\n");
  }
}