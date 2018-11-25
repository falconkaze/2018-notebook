#include<stdio.h>

struct CharDoubleInt{
  char c;
  double d;
  int i;
} char_double_int;

struct DoubleCharInt {
  double d;
  char c;
  int i;
} double_char_int;

int main(){
  printf("char double int:%d\n", sizeof(char_double_int));
  printf("double char int:%d\n", sizeof(double_char_int));
}
