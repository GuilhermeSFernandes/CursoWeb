#include <stdio.h>
#include <stdlib.h>

#define SALARIO_MINIMO 1302.00

typedef struct {
  char nome[50];
  char ocupacao[50];
  double renda_bruta;
} Pessoa;

int main() {
  int n;
  printf("Quantas pessoas moram na residência? ");
  scanf("%d", &n);

  Pessoa *pessoas = (Pessoa*) malloc(n * sizeof(Pessoa));

  for(int i = 0; i < n; i++) {
    printf("Digite o nome da pessoa %d: ", i+1);
    scanf("%s", pessoas[i].nome);
    printf("Digite a ocupação da pessoa %d: ", i+1);
    scanf("%s", pessoas[i].ocupacao);
    printf("Digite a renda bruta da pessoa %d: ", i+1);
    scanf("%lf", &pessoas[i].renda_bruta);
  }

  double renda_total = 0.0;
  for(int i = 0; i < n; i++) {
    renda_total += pessoas[i].renda_bruta;
  }

  double renda_per_capita = renda_total / n;
  printf("A renda per-capita da família é: R$%.2lf\n", renda_per_capita);
  printf("Isso representa %.2lf salários mínimos.\n", renda_per_capita / SALARIO_MINIMO);

  if(renda_per_capita < 1.5 * SALARIO_MINIMO) {
    printf("O estudante poderia receber Auxílio Estudantil.\n");
  } else {
    printf("O estudante não poderia receber Auxílio Estudantil.\n");
  }

  free(pessoas);
  return 0;
}