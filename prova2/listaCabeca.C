#include  <stdio.h>
#include  <stdlib.h>

struct No{
  int chave;
  struct No *prox;

};
typedef struct No no;

no *criarlista(){
  no *cabeca = (no*) malloc(sizeof(no));
  if(cabeca == NULL) return;
  cabeca -> chave = -1;
  cabeca -> prox = NULL;
  return cabeca;
}
void insereInicio(no *lista, int chave){
  no *novo = (no*) malloc(sizeof(no));
  if(novo == NULL) return;
  novo -> prox = lista -> prox;
  lista -> prox = novo;
}