#include <stdio.h>
#include <stdlib.h>

typedef struct celula_str{
  int chave;
  struct celula_str *prox;
} celula;

typedef struct inicio_fim{
  celula *inicio;
  celula *fim;
  int qtde;
} inicioFim;

inicioFim *cabeca(){
  inicioFim *aux = (inicioFim*) malloc(sizeof(inicioFim));
  if(aux == NULL) return 0;
  aux -> inicio = NULL;
  return aux;
}
int vazia(inicioFim *p){
  if(p->inicio == NULL){
    return 1;
  }else return 0;
}
void empilha(inicioFim *p, int k){
  celula *novo = (celula*) malloc (sizeof(celula));
  if(novo){
    novo -> chave = k;
    novo -> prox = p -> inicio;
    p -> inicio = novo;
    p -> qtde++;
  }
}
void desempilha(inicioFim *f){
  celula *aux = f -> inicio;
  if(vazia(f) == 1) return;
  f -> inicio = f -> inicio -> prox;
  free(aux);
  aux = NULL;
}
void desempilhaTodos(inicioFim *f){
  if(f->inicio == NULL) return;
  while(vazia(f) != 1){
    desempilha(f);
  }
}
void imprime(celula *a){
  if(a == NULL)return;
  while(a){
    printf("%d\n", a -> chave);
    a = a -> prox;
  }
}