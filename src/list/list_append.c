#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int             list_append(t_list **this, void *data)
{
  t_node        *cur;
  
  if (this == NULL || (*this) == NULL)
    return (false);
  if ((*this)->first == NULL)
    {
      (*this)->first = malloc(sizeof(t_node));
      if ((*this)->first == NULL)
        return (false);
      (*this)->first->data = data;
      (*this)->first->next = NULL;
      (*this)->last = NULL;
      return (true);
    }
  cur = (*this)->first;
  while (cur->next)
    cur = cur->next;
  cur->next = malloc(sizeof(t_node));
  if (cur->next == NULL)
    return (false);
  cur->next->next = NULL;
  cur->next->data = data;
  (*this)->last = cur->next;
  return (true);
}
