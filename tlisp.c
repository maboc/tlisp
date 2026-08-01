#include "tlisp.h"

struct waarde_type * creeer_waarde(int soort, int n, char * s){
  struct waarde_type * tmp;

  tmp=malloc(sizeof(struct waarde_type));
  tmp->soort=soort;
  if (soort==0){
    tmp->i=n;
  } else if (n==1){
    tmp->s=malloc(strlen(s)+1);
    bzero(tmp->s, strlen(s)+1);
    tmp->s=strncpy(tmp->s, s, strlen(s));
  } else {
    tmp->i=n;
    tmp->s=malloc(strlen(s)+1);
    bzero(tmp->s, strlen(s)+1);
    tmp->s=strncpy(tmp->s, s, strlen(s));
  }

  return tmp;
}

void verwijder_waarde(struct waarde_type * in_val){
  if(in_val->soort==1){
    free(in_val);
  } else {
    free(in_val->s);
    free(in_val);
  }
}

struct waarde_type * interpret(struct waarde_type * in_val){
  struct waarde_type * ret_val;
  
  laat_waarde_zien(in_val);

  /*als de waarde een integer is dan kunnen we meteen terug geven*/
  if(in_val->soort==0){
    ret_val=creeer_waarde(0, in_val->i, in_val->s);
  } else if (in_val->soort==1) {
    char * sp; /*start pointer*/
    char * ep; /*end pointer*/
    char * wp; /*work pointer*/
    int counter;

    sp=in_val->s;
    wp=sp;

    while(wp!=NULL){
      printf("%c\n", wp);
      wp++;
    }
    ret_val=creeer_waarde(1,0,"gelukt");
  }

  return ret_val;
}

void laat_waarde_zien(struct waarde_type * in_val){
  printf("soort  : %i\n", in_val->soort);
  printf("int    : %i\n", in_val->i);
  printf("string : %s\n", in_val->s);

  return;
}

int main(int argc, char ** argv){
  char * arg1;
  struct waarde_type * in_val;
  struct waarde_type * ret_val;
  
  printf("tlisp\n");

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

  /*
    Dan nu maar interpreteren
  */

  in_val=creeer_waarde(1, 0, arg1);
  
  ret_val=interpret(in_val);

  laat_waarde_zien(in_val);
  
  verwijder_waarde(in_val);
  
  return 0;
}
