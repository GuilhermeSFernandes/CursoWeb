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
int fetuccini(int primeiro_termo, int segundo_termo, int n) {
    int termo_anterior = primeiro_termo;
    int termo_atual = segundo_termo;
    int temp;

    if (n == 1) {
        return primeiro_termo;
    }
    if (n == 2) {
        return segundo_termo;
    }

    int operacao = 1;

    for (int i = 3; i <= n; i++) {
        temp = termo_atual + (operacao * termo_anterior);
        termo_anterior = termo_atual;
        termo_atual = temp;
        operacao *= -1; 
    }
    return temp;
}
int main(){
  return 0;
}