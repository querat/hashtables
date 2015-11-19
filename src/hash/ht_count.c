#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "hash.h"

size_t          ht_count(t_hash *hash)
{
  size_t        size;
  size_t        i;
  t_node        *node;
  
  size = 0;
  i = -1;
  if (hash == NULL || hash->buckets == NULL || hash->buckets[0] == NULL)
    return (0);
  while ((hash->buckets[++i]))
    {
      node = hash->buckets[i]->first;
      {
        while (node)
          {
            size = (node->data != NULL) ? size + 1 : size;
            node = node->next;
          }
      }
    }
  return (size);
}
