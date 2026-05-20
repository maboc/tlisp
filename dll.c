#include "dll.h"

struct dll * first(struct dll * list){
  if (list!=NULL){
    while (list->prev!=NULL){
      list=list->prev;
    }
  }
  return list;
}


struct dll * last(struct dll * list){
  if(list!=NULL){
    while(list->next!=NULL){
      list=list->next;
    }
  }
  return list;
}
