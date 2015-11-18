#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/*
** Pseudo-constructeur de liste chaînée
*/
t_list          *new_list()
{
  t_list        *this;
  
  this = malloc(sizeof(t_list));
  if (this == NULL)
    return (NULL);
  this->first = NULL;
  this->last = NULL;
  this->append = &list_append;
  this->prepend = &list_prepend;
  this->destruct = &list_destruct;
  this->print = &list_print;
  this->rm_node = &list_rm_node;
  this->rm_first_node = &list_rm_first_node;
  this->rm_last_node = &list_rm_last_node;
  this->insert = &list_insert;
  
  return (this);
}
