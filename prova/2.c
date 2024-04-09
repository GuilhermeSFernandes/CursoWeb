#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 5
#define MAX_NOME 16 // 15 letras + 1 para o caractere nulo

typedef struct {
    int codigo;
    char nome[MAX_NOME];
    float preco;
    int quantidade;
} Produto;

void lerProduto(Produto *produto) {
    printf("Digite o código do produto: ");
    scanf("%d", &produto->codigo);
    printf("Digite o nome do produto (máximo 15 letras): ");
    scanf("%s", produto->nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &produto->preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidade);
}

void exibirProduto(Produto produto) {
    printf("Código: %d, Nome: %s, Preço: R$%.2f, Quantidade: %d\n", produto.codigo, produto.nome, produto.preco, produto.quantidade);
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int i;

    // Ler informações dos produtos
    for (i = 0; i < MAX_PRODUTOS; i++) {
        printf("Produto %d:\n", i + 1);
        lerProduto(&produtos[i]);
    }

    // Processar pedidos
    int codigo_pedido, quantidade_pedido;
    while (1) {
        printf("Digite o código do produto do pedido (0 para sair): ");
        scanf("%d", &codigo_pedido);
        if (codigo_pedido == 0) break;

        printf("Digite a quantidade do pedido: ");
        scanf("%d", &quantidade_pedido);

        int encontrado = 0;
        for (i = 0; i < MAX_PRODUTOS; i++) {
            if (produtos[i].codigo == codigo_pedido) {
                encontrado = 1;
                if (produtos[i].quantidade >= quantidade_pedido) {
                    produtos[i].quantidade -= quantidade_pedido;
                    printf("Pedido realizado com sucesso!\n");
                } else {
                    printf("Não há quantidade suficiente em estoque para atender ao pedido.\n");
                }
                break;
            }
        }
        if (!encontrado) {
            printf("Código de produto não encontrado.\n");
        }
    }

    return 0;
}
