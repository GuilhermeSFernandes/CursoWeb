//Rafael Montani | Joao Geronimo | Guilherme Fernandes | Stheven Alves | Grupo 10
#include <stdio.h>  

int resto_divisao(int A, int B) {
    if (A < B) {
        return A;
    }
    while (A >= B) {
        A -= B;
    }
    return A;
}
int sucessor_impar(int n){
  if (resto_divisao(n, 2) == 0){
    return n + 1;
  }else{
    return n + 2;
  }
}
int fetuccini(int A, int n){
  int b = A;
  int temp;
  if (n == 1) {
    return A;
  }
  if (n == 2) {
    return b;
  }
  for (int i = 3; i <= n; i++) {
    if (resto_divisao(n, 2) == 1) {
      temp = A + b;
    } else {
      temp = A - b;}
    A = b;
    b = temp;
  }
  return temp;
}
int main(){
  return 0;
}