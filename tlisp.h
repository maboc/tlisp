#include <stdio.h>
#include <stddef.h>
#include "dll.h"

const int IVAL=1;
const int SVAL=2;
const int CVAL=3;

struct value {
  int value_type; /* What type is this value */
  char * name;    /* Name of the variable*/
  int i_value;    /* filled in case of an integer */
  char * s_value; /* filled in case of a string */
  char c_value;   /* filled in case of a boolean */
};

struct dll * varlist=NULL;
