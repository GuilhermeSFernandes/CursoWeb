#include <stdio.h>
#include <stdlib.h>

struct No{
  int chave;
  struct No *prox;

};
typedef struct No no;

no *aloca (int k){
  no *novo;
  novo = (no*) malloc(sizeof(no));
  if(novo == NULL) return NULL;
  novo->chave = k;
  novo->prox = NULL;
  return novo;
}
void insereInicio(no **prim, int k){
  assert(prim);
  no* noAux = aloca(k);
  if(noAux == NULL) return;
  noAux->prox = *prim;
  *prim = noAux;
}
void removePrimeiro(no **prim){
  assert(prim);
  if(*prim == NULL) return;
  no *aux = *prim;
  *prim = (*prim) -> prox;
  free(aux);
}

int main(){
}