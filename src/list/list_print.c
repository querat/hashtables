#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void            list_print(t_list *this, void (*printer)(void*))
{
  t_node        *current_node;
  
  if (this == NULL || this->first == NULL)
    return ;
  current_node = this->first;
  while (current_node != NULL)
    {
      if (current_node->data != NULL)
        (printer)(current_node->data);
      current_node = current_node->next;
    }
  return ;
}
