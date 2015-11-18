#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "hash.h"

int             ht_key_cmp(void *cmp_, size_t cmp_size,
                           void *key_, size_t key_size)
{
  size_t	i;
  char		*cmp;
  char		*key;

  cmp = cmp_;
  key = key_;
  i = -1;
  if (key_size != cmp_size || cmp == NULL || key == NULL)
    return (false);
  while (++i < cmp_size)
    {
      if (cmp[i] != key[i])
	return (false);
    }
  return (true);
}
