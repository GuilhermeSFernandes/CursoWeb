#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calcMedia(int *array, int n, int *resultado){
  int temp = 0;
  for(int i = 0; i < array[i]; i++){
    *resultado += array[i];
    temp++;
  }
  *resultado = *resultado / temp;
}

int main(){
  int array[] = {1, 2, 3, 4, 10};
  int resultado = 0;
  calcMedia(array, 5, &resultado);
  printf("%d\n", resultado);
  return 0;
}