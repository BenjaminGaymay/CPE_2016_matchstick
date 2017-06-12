/*
** my_showtab.c for my_showtab in /home/benjamin.g/save/Create/library
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Jan 17 20:56:55 2017 Benjamin GAYMAY
** Last update Tue Feb 14 14:44:05 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"

void	my_showtab(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    {
      my_putstr(array[i++]);
      my_putchar('\n');
    }
}

void	free_array(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    free(array[i++]);
  free(array);
}
