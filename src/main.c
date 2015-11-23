#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "hash.h"

void            print_data(void *data)
{
  char          *str = (data != NULL) ? data : "[NULL]";

  printf("%s\n", str);
  return ;
}

char            *rev(char *str)
{
  int end;
  int start;
  
  end = strlen(str)-1;
  start = 0;
  while (start < end)
    {
      str[start] ^= str[end];
      str[end] ^= str[start];
      str[start]^= str[end];
      ++start;
      --end;
    }
  return str;
}

void            voidrev(void *data)
{
  char          *str;

  str = data;
  if (str)
    rev(str);
}

int             main(int ac, char **av)
{
  int           i = 0;
  t_hash        *hash;
  
  if (av[1] == NULL || ac < 1)
    return (EXIT_FAILURE);

  hash = ht_init(5);
  if (hash == NULL)
    return (EXIT_FAILURE);
  while (av[++i] != NULL)
    if ((ht_add_entry(hash, rev(strdup(av[i])), strdup(av[i]), (strlen(av[i])))) == false)
      {
        printf("erreur lors de l'ajout d'un maillon.\n");
        return (EXIT_FAILURE);
      }
  
  
  char *str = ht_get_entry(hash, "main.o", 6);
  if (str)
    printf("\nget entry : %s\n", str);
  else
    printf("nope\n");
  printf("éléments dans la hashtable : %d\n", ht_count(hash));

  /* passe un revstr dans chaque élément de la hashtable */
  ht_foreach(hash, &voidrev);

  ht_print(hash);
  hash = ht_free(hash, &free);
  
  
  return 0;
}


