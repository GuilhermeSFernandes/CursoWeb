#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListaE {
 int info;
 struct ListaE* prox;
 struct ListaE* ant;
} ListaE;

ListaE* listaE_insere (ListaE* p, int info)
{
 assert(p);
 ListaE* novo = (ListaE*) malloc(sizeof(ListaE));
 novo->info = info;
 novo->prox = p;
 novo->ant = NULL;
 if (p != NULL){
  p->ant = novo;
 return novo;
 }
} 
// Busca elemento
ListaE* listaE_busca (ListaE* p, int elem)
{
 ListaE* aux;
 for(aux = p; aux != NULL; aux = aux -> prox){
  if(aux -> info == elem){
    return aux;
  }
 }
 return NULL;
}