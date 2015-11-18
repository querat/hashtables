#ifndef HASH_H_
# define HASH_H_

#include <stdlib.h>
#include "list.h"

typedef struct  s_entry
{
  void          *data;
  void          *key;
  size_t	hash;
  size_t        key_size;
  size_t        data_size;
}               t_entry;

typedef struct  s_hash
{
  size_t        size;
  t_list        **buckets;
  size_t        (*hash)(void *data, size_t size);
}               t_hash;

t_hash          *ht_init(size_t size);
size_t          ht_hash_function(void *data, size_t size);
int             ht_add_entry(t_hash *hash, void *data, void *key, size_t key_size);
int             ht_rm_entry(t_hash *hash, void *key, size_t key_size,
                            void (*destructor)(void*));
void            *ht_get_entry(t_hash *hash, void *key, size_t key_size);
void            ht_print(t_hash *hash);
t_hash          *ht_free(t_hash *hash, void (*ptr)(void*));
int             ht_key_cmp(void *cmp_, size_t cmp_size,
                           void *key_, size_t key_size);
t_entry         *ht_free_entry(t_entry *entry, void (*ptr)(void*));


#endif /* !hash.h */
