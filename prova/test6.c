#include <stdio.h>
#include <string.h>
#include <limits.h>

struct atleta {
  char nome[20];
  int tempos[6];
  int velocidades[6];
  int batimentos[6];
};

void analisarAtleta(struct atleta* a) {
  int tempoTotal = 0;
  int velocidadeMax = INT_MIN;
  int batimentoMax = INT_MIN;
  int batimentoMin = INT_MAX;

  for (int i = 0; i < 6; i++) {
    tempoTotal += a->tempos[i];
    if (a->velocidades[i] > velocidadeMax) {
      velocidadeMax = a->velocidades[i];
    }
    if (a->batimentos[i] > batimentoMax) {
      batimentoMax = a->batimentos[i];
    }
    if (a->batimentos[i] < batimentoMin) {
      batimentoMin = a->batimentos[i];
    }
  }

  printf("Atleta: %s\n", a->nome);
  printf("Tempo médio de corrida: %d\n", tempoTotal / 6);
  printf("Velocidade máxima alcançada: %d\n", velocidadeMax);
  printf("Amplitude do batimento cardíaco: %d\n", batimentoMax - batimentoMin);
}

int main() {
  struct atleta a;
  strcpy(a.nome, "Atleta 1");
  for (int i = 0; i < 6; i++) {
    a.tempos[i] = 10 * (i + 1); // Exemplo de tempos
    a.velocidades[i] = 20 * (i + 1); // Exemplo de velocidades
    a.batimentos[i] = 60 + i; // Exemplo de batimentos
  }

  analisarAtleta(&a);

  return 0;
}