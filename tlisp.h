#ifndef _TLISP_
#define TLISP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct waarde_type{
  int soort; /* 0 : integer 1 : string 2 : error (?)) */
  int i;
  char * s;
};


struct waarde_type * creeer_waarde(int, int, char *);
struct waarde_type * evaluate(struct waarde_type *);
void laat_waarde_zien(struct waarde_type *);
void verwijder_waarde(struct waarde_type *);
struct waarde_type * gebalanceerd(struct waarde_type *);

#endif
