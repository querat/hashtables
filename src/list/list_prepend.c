#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int             list_prepend(struct s_list **this, void *data)
{
  t_node        *new;
  
  if (this == NULL || (*this) == NULL)
    return (false);
  new = malloc(sizeof(t_node));
  if (new == NULL)
    return (false);
  new->data = data;
  new->next = (*this)->first;
  (*this)->first = new;
  if ((*this)->first->next == NULL)
    (*this)->last = NULL;
  return (true);
}
