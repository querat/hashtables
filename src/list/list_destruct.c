#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void            list_destruct(struct s_list **this, void (*destructor)(void*))
{
  t_node        *cur;
  t_node        *prev;

  prev = NULL;
  if ((*this) == NULL)
    return ;
  if ((*this)->first == NULL)
    {
      free((*this));
      return ;
    }
  cur = (*this)->first;
  while (cur)
    {
      if (cur->data)
        (destructor)(cur->data);
      prev = cur;
      cur = cur->next;
      free(prev);
    }
  free((*this));
  (*this) = NULL;
  return ;
}
