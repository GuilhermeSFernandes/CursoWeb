#include <stdio.h>
#include <stdlib.h>

#define SalMin 1302
typedef struct
{
  char nome[100];
  char ocupacao[100];
  float renda;
} Familia;

int main (){
  int n = 0;
  printf("Quantas pessoas moram na residência? ");
  scanf("%d", &n);
  Familia *membros = (Familia*) malloc (n * sizeof(Familia));
  for(int i = 0; i < n; i++){
    printf("Digite o nome da pessoa %d: ", i+1);
    scanf("%s", membros[i].nome);
    printf("Digite a ocupação da pessoa %d: ", i+1);
    scanf("%s", membros[i].ocupacao);
    printf("Digite a renda bruta da pessoa %d: ", i+1);
    scanf("%f", &membros[i].renda);
    float perCapita = 0.0;
    for(int i = 0; i < n; i++){
      perCapita += membros[i].renda;
    }
    perCapita = perCapita / n;
    if(perCapita < 1.5 * SalMin){
      printf("O estudante poderia receber Auxílio Estudantil.\n");
    } else {
      printf("O estudante não poderia receber Auxílio Estudantil.\n");
    }
  }
  free(membros);
  membros = NULL;

}