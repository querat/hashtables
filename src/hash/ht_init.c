#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "hash.h"

/*
** <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
** Free the memory allocated before the last malloc failed
*/
static t_list   **ht_init_entries_failure(t_list **arr)
{
  int           i;

  i = -1;
  while (arr[++i] != NULL)
    free(arr[i]);
  free(arr);
  return (NULL);
}

/*
** <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
** Allocates struct memory for each bucket of entries
*/
static t_list   **ht_init_buckets(size_t size)
{
  t_list        **list_array;
  size_t        i;

  i = 0;
  list_array = malloc(sizeof(t_list*) * (size + 1));
  if (list_array == NULL)
    return (NULL);
  while (i < size)
    {
      list_array[i] = new_list();
      if (list_array[i] == NULL)
        return (ht_init_entries_failure(list_array));
      ++i;
    }
  list_array[i] = NULL;
  return (list_array);
}

/*
** <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
** Returns a pointer to a prepared hashtable with sz buckets list of entries
*/
t_hash          *ht_init(size_t sz)
{
  t_hash        *ht;

  ht = malloc(sizeof(t_hash));
  if (ht == NULL || sz <= 0)
    return (NULL);
  ht->size = sz;
  ht->buckets = ht_init_buckets(ht->size);
  ht->hash = &ht_hash_function;
  return (ht);
}

