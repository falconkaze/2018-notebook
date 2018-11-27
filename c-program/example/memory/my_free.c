#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char name[100];
  char *desc;

  strcpy(name, "Zara Ali");

  desc = (char *)malloc(30 * sizeof(char));
  if(desc == NULL){
    fprintf(stderr, "Error - unable to allocate required memory\n");
  }else{
    strcpy(desc, "Zara Ali a DPS student.");
  }
  // 假设需要存储更大的描述信息
//  desc = realloc(desc, 100 * sizeof(char));
  if(desc == NULL){
    fprintf(stderr, "Error - unable to allocate required memory\n");
  }else{
    strcat(desc, "She is in class 10th.");
  }
  printf("Name = %s\n", name);
  printf("Desc = %s\n", desc);
  free(desc);
}
