#include "../include/usuario.h"
#include <stdio.h>
#include <stdlib.h>

int cadastroUsuario(Usuario **usuarios, int *quantUsuarios) {
  int tamanhoAtual = *quantUsuarios + 1;
  Usuario *novoUsuario =
      (Usuario *)realloc(*usuarios, tamanhoAtual * sizeof(Usuario));
  if (novoUsuario == NULL) {
    printf("Erro ao alocar memoria");
    return 0;
  }

  printf("Digite o nome do usuario: ");
  scanf("%s", &novoUsuario[*quantUsuarios].nome);
  printf("Digite o numero do usuario: ");
  scanf("%s", &novoUsuario[*quantUsuarios].numero);
  novoUsuario[*quantUsuarios].id = *quantUsuarios + 1;
  novoUsuario[*quantUsuarios].flag = 1;
  novoUsuario[*quantUsuarios].emprestimos = 0;

  *usuarios = novoUsuario;
  (*quantUsuarios)++;
  return 1;
}

void imprimeU(Usuario *usuarios, int *quant) {
  if (*quant != 0) {
    printf("\n==== ACERVO ====\n\n");
    for (int i = 0; i < *quant; i++) {
      if (usuarios[i].flag != 0) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", &usuarios[i].nome);
        printf("Numero: %s\n", &usuarios[i].numero);
        printf("----------------------\n");
      }
    }
  } else {
    printf("Não há usuarios cadastrados.\n");
  }
}

int buscaU(Usuario *usuarios, int quant) {
  int indice = -1, id = 0;
  printf("\n==== BUSCAR ====\n\n");
  printf("ID do usuario: ");
  scanf("%d", &id);
  for (int i = 0; i < quant; i++) {
    if (id == usuarios[i].id) {
      indice = i;
      return indice;
      printf("acho!");
      break;
    } else {
      printf("usuario não encontrado\n");
    }
  }
  return indice;
}

void removeUsuario(Usuario **usuarios, int *quant) {
  int indiceU = buscaU(*usuarios, *quant);

  if (indiceU != -1 && usuarios[indiceU]->flag == 1) {
    for (int i = indiceU; i < *quant - 1; i++) {
      // sinaliza na flag q o usuario foi removido
      usuarios[i]->flag = 0;
    }
    (*quant)--;
    printf("\nUsuario removido com sucesso!\n");
  } else {
    printf("\nUsuario nao encontrado");
  }
}

void salvaUsuario(FILE *arquivo, Usuario **usuarios, int quantUsuarios) {
  int qtd = quantUsuarios;
  arquivo = fopen("usuarios.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
  } else {
    printf("arquivo aberto");
  }
  for (int i = 0; i < qtd; i++) {
    fprintf(arquivo, "%d %s %s %d\n", usuarios[i]->id, usuarios[i]->nome,
            usuarios[i]->numero, usuarios[i]->emprestimos);
  }
  fclose(arquivo);

  printf("Dados salvos com sucesso no arquivo usuarios.txt.\n");
}

void carregaUsuario(Usuario **usuarios, int *quantUsuarios) {
  FILE *arquivo = fopen("usuarios.txt", "r");
  if (arquivo) {
    while (fscanf(arquivo, "%d %s %s %d", &usuarios[*quantUsuarios]->id,
                  usuarios[*quantUsuarios]->nome,
                  usuarios[*quantUsuarios]->numero,
                  &usuarios[*quantUsuarios]->emprestimos) == 4) {
      // Ler outros campos relevantes aqui, se necessário
      (*quantUsuarios)++;
    }
    fclose(arquivo);
  } else {
    printf("Erro ao abrir o arquivo para leitura.\n");
  }
}