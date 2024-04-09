#include <stdio.h>
#include <stdlib.h>

// Função para ler um vetor de números inteiros positivos
int *leitura(int *size) {
  printf("Digite o tamanho do vetor: ");
  scanf("%d", size);

  int *vetor = (int*)malloc(*size *sizeof(int));
  if(vetor == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }

  printf("Digite os elementos do vetor: ");
  for(int i = 0; i < *size; i++) {
    scanf("%d", &vetor[i]);
  }
  return vetor;
}

// Função para separar os elementos do vetor em dois vetores (pares e ímpares)
void separa(int *vetor, int size, int **pares, int **impares, int *sizePares, int *sizeImpares) {
  *sizePares = 0;
  *sizeImpares = 0;

  for(int i = 0; i < size; i++) {
    if(vetor[i] % 2 == 0) {
      (*sizePares)++;
    } else {
      (*sizeImpares)++;
    }
  }

  *pares = (int*)malloc(*sizePares * sizeof(int));
  *impares = (int*)malloc(*sizeImpares * sizeof(int));

  int indexPares = 0;
  int indexImpares = 0;

  for(int i = 0; i < size; i++) {
    if(vetor[i] % 2 == 0) {
      (*pares)[indexPares++] = vetor[i];
    } else {
      (*impares)[indexImpares++] = vetor[i];
    }
  }

  free(vetor);
}

// Função para imprimir os elementos do vetor
void imprime(int* vetor, int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int size;
  int *vetor = leitura(&size);

  int *pares, *impares, sizePares, sizeImpares;
  separa(vetor, size, &pares, &impares, &sizePares, &sizeImpares);

  printf("Vetor de pares: ");
  imprime(pares, sizePares);

  printf("Vetor de ímpares: ");
  imprime(impares, sizeImpares);

  free(pares);
  free(impares);

  return 0;
}