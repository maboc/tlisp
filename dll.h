#include <stddef.h>

struct dll {
  struct dll * prev;
  struct dll * next;
  void * payload;
};

struct dll * first(struct dll *);
struct dll * last(struct dll *);

