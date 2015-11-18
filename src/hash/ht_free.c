#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "hash.h"

t_entry  *ht_free_entry(t_entry *entry, void (*ptr)(void*))
{
  if (entry == NULL)
    return (NULL);
  if (ptr && entry->data)
    (ptr)(entry->data);
  free(entry->key);
  free(entry);
  return (NULL);
}

static t_list   *free_bucket(t_list *bucket, void (*ptr)(void*))
{
  t_node        *cur_list;
  t_node        *tmp_to_free;
  
  
  cur_list = bucket->first;
  if (cur_list != NULL)
    {
      while (cur_list != NULL)
        {
          ht_free_entry(cur_list->data, ptr);
          tmp_to_free = cur_list;
          cur_list = cur_list->next;
          free(tmp_to_free);
        }
    }
  free(bucket);
  return (NULL);
}

t_hash          *ht_free(t_hash *hash, void (*ptr)(void*))
{
  size_t        i;

  i = -1;
  if (hash == NULL || hash->buckets == NULL || hash->buckets[0] == NULL)
    return (hash);
  while (hash->buckets[++i] != NULL)
    hash->buckets[i] = free_bucket(hash->buckets[i], ptr);
  free(hash->buckets);
  free(hash);
  return (NULL);
}
