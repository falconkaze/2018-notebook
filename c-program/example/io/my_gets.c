#include<stdio.h>

int main(){
  char str[5];

  printf("Enter a string:");
  fgets(str, 5, stdin);
  printf("\nYou entered:");
  fputs(str, stdout);
  printf("size:%d", sizeof(str));
  return 0;
}
