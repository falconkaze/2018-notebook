#include <stdio.h>

int main(){
  int num;
  char c;
  float f;
  double d;
  char str[100];
  printf("请依次输入字符，整数，浮点数, 浮点数，字符串，中间用空格隔开.");
  scanf("%c %d %f %e %s",&c , &num, &f, &d, str);
  printf("输入的依次是：%c, %d, %f, %e, %s", c, num, f, d, str);
}
