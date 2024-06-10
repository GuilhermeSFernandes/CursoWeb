#include  <stdio.h>
#include  <stdlib.h>
#include <assert.h>

struct listaCircular{
  int chave;
  struct listaCircular *prox;
};
typedef struct listaCircular listaCircular;

void insereCircular(listaCircular **p, int info){
  assert(p);
  if(*p == NULL){
    *p = (listaCircular*) malloc(sizeof(listaCircular));
    if(*p != NULL){
      (*p) -> chave = info;
      (*p) -> prox = *p;
    }
  }else{
    listaCircular *aux = (listaCircular*) malloc(sizeof(listaCircular));
    if(aux == NULL) return;
    aux -> chave = info;
    aux -> prox = (*p) -> prox;
    (*p) -> prox = aux;
  }
}
void removeCircular(listaCircular **p){
  assert(p);
  if(*p == NULL) return;
  listaCircular *pPrim = (*p) -> prox;
  listaCircular *pPenult = (*p) -> prox;
  if(pPrim -> prox != pPrim){
    while(pPenult -> prox != *p){
      pPenult = pPenult -> prox;
    }
    free(*p);
    *p = pPenult;
    pPenult -> prox = pPrim;
  }else{
    free(*p);
    *p = NULL;
  }
  