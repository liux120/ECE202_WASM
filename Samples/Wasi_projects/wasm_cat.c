#include <stdio.h>
#include <stdlib.h>
#include <wasi/core.h>
int main(int argc, char *argv[]) {
  if(argc != 2) return -1;
  FILE* fp;
  char c;
  fp = fopen(argv[1], "r");
  while((c = getc(fp)) != EOF)
    printf("%c", c);
  fclose(fp);
  return 0;
}
