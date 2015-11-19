#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "hash.h"

size_t          ht_foreach(t_hash *hash, void (*func)(void*))
{
  size_t        i;
  t_node        *node;
  size_t        affected;
  t_entry       *entry;
  
  i = -1;
  affected = 0;
  if (hash == NULL || hash->buckets == NULL || hash->buckets[0] == NULL)
    return (false);
  while (hash->buckets[++i] != NULL)
    {
      node = hash->buckets[i]->first;
      {
        while (node != NULL)
          {
            if (func != NULL && (entry = node->data) != NULL && entry->data)
              {
                (func)(entry->data);
                ++affected;
              }
            node = node->next;
          }
      }
    }
  return (affected);
}
