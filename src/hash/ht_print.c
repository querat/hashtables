#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "list.h"
#include "hash.h"

void            ht_print(t_hash *hash)
{
  t_list        *bucket;
  t_node        *list;
  t_entry       *entry;
  size_t        i;
  
  if (hash == NULL || hash->buckets == NULL || hash->buckets[0] == NULL)
    return ;
  i = -1;
  puts("----------------------------------------------------------\n");
  while (++i < hash->size)
    {
      printf("[%p] bucket index '%u'-------------------------------\n",
             hash->buckets[i], i);
      bucket = hash->buckets[i];
      if (bucket != NULL && bucket->first != NULL)
        {
          list = bucket->first;
          while (list != NULL)
            {
              entry = list->data;
              printf("    Node entry -> key %s, data %s\n",
                     entry->key,
                     entry->data);
              list = list->next;
            }
        }
    }
  puts("----------------------------------------------------------\n");  
  return ;
}
