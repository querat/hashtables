#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "hash.h"

size_t          ht_hash_function(void *data, size_t size)
{
  size_t        i;
  char          *str;
  size_t        sum;
  
  str = data;
  if (str == NULL)
    return (0);
  i = 0;
  sum = 1;
  while (i < size)
    {
      sum *= str[i];
      if (i > 0)
        sum ^= str[i - 1];
      ++i;
    }
  
  return (sum);
}
