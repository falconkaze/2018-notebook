#include<stdio.h>

int main(){
  FILE *fp = NULL;

  fp = fopen("/tmp/test.txt", "w+");
  fprintf(fp, "This is testing for fprinf...%d\n", 123);
  fputs("This is testing for fputs...\n", fp);
  fclose(fp);

  fp = fopen("/tmp/test.txt", "r+");
  char buff[255];
  fscanf(fp, "%s", buff);
  printf("1:%s\n", buff);

  fgets(buff, 255, fp);
  printf("2:%s\n", buff);

  printf("3:%c\n", fgetc(fp));

  fgets(buff, 255, fp);
  printf("3:%s\n", buff);
  fclose(fp);
}
