#include<stdio.h>

int main(){
  char str[100];
  int i;
  printt("Enter a value:");
  scanf("%s %d", str, &i);

  printf("\nYou entered: %s %d", str, i);
  printf("\n");
  return 0;
}
