#include <stdio.h>
#include <stdlib.h>

typedef struct celula_str{
  int chave;
  struct celula_str *prox;
} celula;

typedef struct inicio_fim{
  celula *inicio;
  celula *fim;
} inicioFim;

inicioFim *cabeca(){
  struct inicio_fim *aux = (struct inicio_fim*) malloc(sizeof(struct inicio_fim));
  if(aux == NULL) return 0;
  aux -> inicio = NULL;
  aux -> fim = NULL;
  return aux;
}
int vazia(inicioFim *f){
  if(f -> inicio == NULL){
    return 1;
  }else return 0;
}
void insereFila(inicioFim *f, int k){
  celula *novo = (celula*) malloc(sizeof(celula));
  if(novo){
    novo -> chave = k;
    novo -> prox = NULL;
    f -> fim -> prox = novo;
    f -> fim = novo;
  }
  if( f -> inicio == NULL){
    f -> inicio = f -> fim;
  }
}
void retiraFila(inicioFim *f){
  if(vazia(f) == 1) return;
  celula *aux = f -> inicio;
  f -> inicio = f -> inicio -> prox;
  free(aux);
  if(f -> inicio == NULL){
    f -> fim = null;
  }
}
void retirarTodos(inicioFim *f){
  while(vazia(f) != 1){
    retiraFila(f);
  }
}
void imprime(inicioFim *f){
  celula *aux = f -> inicio;
  if(aux){
    while(aux){
      printf("%d\n", aux -> chave);
      aux = aux -> prox;
    }
  }
}