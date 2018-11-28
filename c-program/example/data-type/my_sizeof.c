#include <stdio.h>

int main(){
  char charType;
  int intType;
  long longType;
  long long longLong;
  float floatType;
  double doubleType;
  long double longDouble;

  printf("Size of char: %d\n", sizeof(charType));
  printf("Size of int: %d\n", sizeof(intType));
  printf("Size of long: %d\n", sizeof(longType));
  printf("Size of long long: %d\n", sizeof(longLong));
  printf("Size of float: %d\n", sizeof(floatType));
  printf("Size of double: %d\n", sizeof(doubleType));
  printf("Size of long double: %d\n", sizeof(longDouble));
}
