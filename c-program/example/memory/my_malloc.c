#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char name[100];
  char *desc;

  strcpy(name, "Zara Ali");

  desc = (char *)malloc(200 * sizeof(char));
  if(desc == NULL){
    fprintf(stderr, "Error - unable to allocate required memory\n");
  }else{
    strcpy(desc, "Zara Ali a DPS student");
  }
  printf("Name = %s\n", name);
  printf("Desc = %s\n", desc);
}
