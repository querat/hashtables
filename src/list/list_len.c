#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

int             list_len(struct s_list *this)
{
  int           i;
  t_node        *cur;
  
  if (this->first == NULL)
    return (0);
  i = 1;
  cur = this->first;
  while ((cur = cur->next))
    ++i;
  return (i);
}
