#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "hash.h"

int             ht_add_entry(t_hash *hash, void *data,
                             void *key, size_t key_size)
{
  size_t	hashed_key;
  size_t        offset;
  t_entry       *entry;
  
  hashed_key = (hash->hash)(key, key_size);
  offset = hashed_key % hash->size;
  entry = malloc(sizeof(t_entry));
  if (entry == NULL)
    return (false);
  entry->data = data;
  entry->key = key;
  entry->key_size = key_size;
  entry->hash = hashed_key;
  return ((*(hash->buckets[offset])).prepend(&hash->buckets[offset], entry));
}
