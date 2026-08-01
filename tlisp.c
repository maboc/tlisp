#include "tlisp.h"

int main(int argc, char ** argv){
  struct waarde_type * waarde;
  char * arg1;
  
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

  printf("Argc             :%i\n", argc);
  if(argc<2){
    printf("Melding          :Dan bedenk ik zelf wel iets\n");
    arg1=malloc(strlen("(* (+ 10 1) (- 10 1))"));
    bzero(arg1, strlen("(* (+ 10 1) (- 10 1))"));
    arg1=strncpy(arg1, "(* (+ 10 1) (- 10 1))", strlen("(* (+ 10 1) (- 10 1))"));
  } else {

    arg1=malloc(strlen(argv[1])+1);
    bzero(arg1, strlen(argv[1])+1);
    arg1=strncpy(arg1, argv[1], strlen(argv[1])+1);  
  }
  printf("arg              :%s\n", arg1);

  /*
    Voor nu ga ik er van uit dat alle input helemaal pico bello in elkaar steekt
    Later kan er wel een soort input-schoonmaak actie gemaakt
  */
  
  
  free(arg1);
  
  return 0;
}
