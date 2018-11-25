#include <stdio.h>

union Data{
  int i;
  float f;
  char str[8];
  double d;
}data;

int main(){
  printf("dataSize:%d\n", sizeof(data));
}
