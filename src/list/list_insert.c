#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

static t_node   *new_node_to_insert(t_node *cur, void *data)
{
  t_node        *new;
  
  new = malloc(sizeof(t_node));
  if (new == NULL)
    return (NULL);
  new->data = data;
  new->next = cur;
  return (new);
}
  
int             list_insert(struct s_list **this, int offset, void *data)
{
  int           i;
  t_node        *cur;
  t_node        *tmp;
  t_node        *new;
  
  if (this == NULL || (*this) == NULL || (*this)->first == NULL)
    return (false);
  if (offset <= 0)
    return (list_prepend(this, data));
  else if (offset >= ((list_len((*this)))))
    return (list_append(this, data));
  i = -1;
  cur = (*this)->first;
  while (++i < offset)
    {
      tmp = cur;
      cur = cur->next;
    }
  new = new_node_to_insert(cur, data);
  if (new == NULL)
    return (false);
  tmp->next = new;
  return (true);
}
