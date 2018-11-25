#include<stdio.h>

int main(){
  FILE *fp = NULL;
  fp = fopen("/tmp/fseek.txt","w");
  fprintf(fp, "This is testint for fprintf...\n");
  fseek(fp, 10, SEEK_SET);
  if(fputc(65, fp) == EOF) {
    printf("fputc fail");
  }
  fclose(fp);
}
