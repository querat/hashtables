#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

int             list_rm_first_node(struct s_list *this, void (*destructor)(void*))
{
  t_node        *tmp;
  
  if (this == NULL)
    return (false);
  if (this->first == NULL)
    return (false);
  if (destructor != NULL && this->first->data != NULL)
    (destructor)(this->first->data);
  tmp = this->first->next;
  free(this->first);
  this->first = tmp;
  return (true);
}

int             list_rm_last_node(struct s_list *this, void (*destructor)(void*))
{
  t_node        *tmp;
  
  if (this == NULL)
    return (false);
  if (this->first == NULL)
    return (false);
  if (this->first->next == NULL)
    {
      if (destructor && this->first->data)
        (destructor)(this->first->data);
      free(this->first);
      this->first = NULL;
      return (true);
    }
  tmp = this->first;
  while(tmp && tmp->next && tmp->next->next)
    tmp = tmp->next;
  if (destructor && tmp->next->data)
    (destructor)(tmp->next->data);
  free(tmp->next);
  tmp->next = NULL;
  return (true);
}
  
int             list_rm_node(struct s_list      *this,
                             int                offset,
                             void               (*destructor)(void*))
{
  int           i;
  t_node        *cur;
  t_node        *tmp;
  
  if (this == NULL || this->first == NULL)
    return (false);
  if (offset <= 0)
    return (list_rm_first_node(this, destructor));
  else if (offset >= ((list_len(this) - 1)))
    return (list_rm_last_node(this, destructor));
  i = -1;
  cur = this->first;
  while (++i < offset)
    {
      tmp = cur;
      cur = cur->next;
    }
  if (destructor && cur->data)
    (destructor)(cur->data);
  tmp->next = cur->next;
  free(cur);
  return (true);
}
