#include <stdio.h>
#include <string.h>
void upper(char *s){
  for(int i = 0; i < strlen(s); i++){
    if(s[i]>= 'a' && s[i] <= 'z'){
      s[i] -= 32;
    }
  }
}
int main(){
  char s[] = "Prova";
  upper(s);
  printf("%s\n", s);
  return 0;
}