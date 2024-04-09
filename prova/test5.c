#include <stdio.h>
#include <stdlib.h>

struct data{
  int dia;
  int mes;
  int ano;
};
int DifDia(struct data D1, struct data D2){
  int diasD1 = D1.ano * 365 + D1.mes * 30 + D1.dia;
  int diasD2 = D2.ano * 365 + D2.mes * 30 + D2.dia;
  int Res = diasD1 - diasD2;
  if(Res < 0){
    return(diasD2 - diasD1);
  }
  return Res;
  
}

int main(){
  struct data d1 = {10, 4, 2024}; // Data inicial
    struct data d2 = {40, 4, 2024}; // Data final

    int diferenca_dias = DifDia(d1, d2);

    printf("A diferenca entre as datas e: %d dias.\n", diferenca_dias);

    return 0;
}