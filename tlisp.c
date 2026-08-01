#include "tlisp.h"

int main(int argc, char ** argv){
  struct waarde_type * waarde;

  waarde=malloc(sizeof(struct waarde_type));
  waarde->s=NULL;
  waarde->s=malloc(strlen("hallo daar"));
  bzero(waarde->s, strlen("hallo daar"));
  waarde->s=strncpy(waarde->s, "hallo daar", strlen("hallo daar"));

  
  printf("tlisp\n");

  waarde->i=10;

  printf("waarde (integer) :%i\n", waarde->i);
  printf("waarde (string)  :%s\n", waarde->s);

  free(waarde->s);
  free(waarde);

  

  return 0;
}
