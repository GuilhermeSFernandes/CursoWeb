#include <stdio.h>
#include <stdlib.h>

#define NUM_MESA 5
#define MAX_ESPERA 10

typedef struct{
  int id;
}cliente;

typedef struct{
  cliente clientes[MAX_ESPERA]; 
  int inicio;
  int fim;
  int tam;

}filaEspera;

void iniciarFila(filaEspera *f){
  f -> inicio = 0;
  f -> fim = -1;
  f -> tam = 0;
}
int filaVazia(filaEspera *f){
  if(f -> tam == 0){ 
    return 1;
    }else return 0;
}

int filaCheia(filaEspera *f){
  if( f -> tam == MAX_ESPERA){
    return 1;
  }else return 0;
}
void enfileira(filaEspera *f, cliente c){
  if(filaCheia(f) == 1) return;
  f -> fim = (f -> fim + 1) % MAX_ESPERA;
  f -> clientes[f ->fim] = c;
  f -> tam++;
}
cliente desenfileira(filaEspera *f){
  cliente c;
  if(!filaVazia(f)){
    c = f -> clientes[f -> inicio];
    f -> inicio = (f -> inicio + 1) % MAX_ESPERA;
    f -> tam--;
    return c;
  }else{
    printf("Fila vazia\n");
  }
  return c;
}
void adicionarCliente(cliente *mesa, filaEspera *f, int *id){
  int mesaDisponivel = -1;
  for(int i = 0; i < NUM_MESA; i++){
    if(mesa[i].id == -1){
      mesaDisponivel = i;
      break;
    }
  }
  if(mesaDisponivel != -1){
    mesa[mesaDisponivel].id = *id;
}else{
  if(filaCheia(f) != 1){
    cliente c = { *id };
    enfileira(f, c);
  }else{
    printf("Fila cheia\n");
  }
  (*id)++;
}
}
void liberarMesa(cliente *mesa, filaEspera *f){
  int mesaLiberar;
  printf("Qual mesa deseja liberar?\n");
  scanf("%d", &mesaLiberar);
  if(mesaLiberar >= 0 && mesaLiberar < NUM_MESA && mesa[mesaLiberar].id != -1){
    printf("Mesa %d liberada\n", mesaLiberar);
    mesa[mesaLiberar].id = -1;
  }
  if(!filaVazia(f)){
    cliente c = desenfileira(f);
    mesa[mesaLiberar].id = c.id;
  }
}
void menu(cliente *mesa, filaEspera *f, int *id){
  int op;
  while (1){
    printf("1 - Adicionar cliente\n");
    printf("2 - Liberar mesa\n");
    printf("3 - Sair\n");
    scanf("%d", &op);
    switch(op){
      case 1:
        adicionarCliente(mesa, f, id);
        break;
      case 2:
        liberarMesa(mesa, f);
        break;
      case 3:
        return;
        break;
      default:
        printf("Opção inválida\n");
    }
  }
}
int main(){
  cliente mesa[NUM_MESA];
  filaEspera f;
  int id = 1;
  iniciarFila(&f);
  menu(mesa, &f, &id);
  return 0;
}