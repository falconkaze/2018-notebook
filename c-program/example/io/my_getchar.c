#include<stdio.h>

int main(){
  char c;

  printf("Enter a char value:");
  c = getchar();
  
  printf("\nYou entered:");
  putchar(c);
  putchar('\n');

  printf("Enter a char value:");
  int i = getchar();
  
  printf("\nYou entered:");
  putchar(i);
  putchar('\n');

  char str[5];
  for(int value = 0; value < 5; value++) {
    printf("Enter a char value:");
    str[value] = getchar();
    putchar(str[value]);
    putchar('\n');
  }
  printf("\nYou entered:%s", str);
}
