#include <stdio.h>

int main() {
   int n, s = 0;
   scanf("%d", &n);
    for (int i = 1; i <= n; i++){
      if (n % i == 0){
        s++;
      }
    }
if (s == 2){
  printf("O número %d é primo", n);
}
else{
  printf("O número %d não é primo", n);
}
printf("\n%d\n", s);
}
