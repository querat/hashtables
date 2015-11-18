#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "hash.h"

void            *ht_get_entry(t_hash *hash, void *key, size_t key_size)
{
  int           offset;
  t_entry       *entry;
  t_node	*node;
  t_list	*list;

  entry = NULL;
  offset = hash->hash(key, key_size);
  offset = (offset % hash->size);
  if (((list = (hash->buckets[offset])) == NULL) ||
      ((node = list->first) == NULL))
    return (NULL);
  while (node != NULL)
    {
      entry = node->data;
      if (entry != NULL)
	{
	  if (ht_key_cmp(key, key_size, entry->key, entry->key_size))
	    return (entry->data);
	}
      node = node->next;
    }
  printf("no matching key, bucket %d", offset);
  return (NULL);
}
