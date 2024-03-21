#include <stdio.h>



int fatorial (int n){
  int fat = 1;
  for (int i = 1; i <= n; i++){
    fat *= i;
  }
  return fat;
}
int potencia (int base, int exp){
  int pot = 1;
  for(int i = 1; i <= exp; i++){
    pot *= base;
  }
  return pot;
}
int somaFibonacci(int n){
  int p = 1;
  int s = 1;
  int next = 1;
  int soma = 0;
  if (n == 1) return 1;
  for (int i = 0; i < n; i++){
    next = p + s;
    p = s;
    soma += next;
  }
  return soma;
}
float mediaAltura(int v[], int n){
  int soma = 0;
  float media;
  for (int i = 0; i < n; i++){
    soma += v[i];
  }
  media = (float)soma/n;
  return soma;
}

int main (){
  int v[4] = {1, 5, 10 , 20};
  printf("\n%d", fatorial(5));
  printf("\n%d", potencia (2,5));
  printf("\n%d\n", somaFibonacci(5));
  printf("%d\n", mediaAltura(v, 4));
}