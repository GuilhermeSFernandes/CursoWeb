#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 20
#define TAM_TITULO 50
#define TAM_AUTOR 50

typedef struct {
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int ano_publicacao;
} Livro;

void cadastrarLivro(Livro acervo[], int *numLivros) {
    if (*numLivros >= MAX_LIVROS) {
        printf("O acervo está cheio. Não é possível cadastrar mais livros.\n");
        return;
    }

    printf("Digite o título do livro: ");
    scanf(" %[^\n]s", acervo[*numLivros].titulo);
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]s", acervo[*numLivros].autor);
    printf("Digite o ano de publicação do livro: ");
    scanf("%d", &acervo[*numLivros].ano_publicacao);

    (*numLivros)++;
    printf("Livro cadastrado com sucesso!\n");
}

void listarLivros(Livro acervo[], int numLivros) {
    if (numLivros == 0) {
        printf("Acervo vazio.\n");
        return;
    }

    printf("Livros cadastrados:\n");
    for (int i = 0; i < numLivros; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Título: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Ano de publicação: %d\n", acervo[i].ano_publicacao);
    }
}

void pesquisarLivro(Livro acervo[], int numLivros) {
    char tituloBusca[TAM_TITULO];
    printf("Digite o título do livro a ser pesquisado: ");
    scanf(" %[^\n]s", tituloBusca);

    int encontrado = 0;
    for (int i = 0; i < numLivros; i++) {
        if (strcmp(acervo[i].titulo, tituloBusca) == 0) {
            printf("Livro encontrado:\n");
            printf("Título: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Ano de publicação: %d\n", acervo[i].ano_publicacao);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Livro não encontrado.\n");
    }
}

int main() {
    Livro *acervo = malloc(MAX_LIVROS * sizeof(Livro));
    if (acervo == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int numLivros = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Pesquisar livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarLivro(acervo, &numLivros);
                break;
            case 2:
                listarLivros(acervo, numLivros);
                break;
            case 3:
                pesquisarLivro(acervo, numLivros);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    free(acervo);
    acervo = NULL;
    return 0;
}
