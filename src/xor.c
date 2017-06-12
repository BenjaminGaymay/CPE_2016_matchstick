/*
** xor.c for matchstick in /home/benjamin.g/delivery/CPE_2016_matchstick
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Feb 15 11:43:16 2017 Benjamin GAYMAY
** Last update Mon Feb 20 13:29:56 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <time.h>
#include "matchstick.h"
#include "my_printf.h"
#include "my.h"

int	get_xor(char **tab)
{
  int	xor;
  int	i;

  xor = 0;
  i = 1;
  while (tab[i + 1] != NULL)
    {
      if (count_stick_on_line(tab, i) > 0)
	xor ^= dec_to_bin(count_stick_on_line(tab, i));
      i++;
    }
  return (xor);
}

int	my_remove(char **tab, int line, int matches)
{
  remove_matches(tab, line, matches);
  my_printf("AI removed %d match(es) from line %d\n", matches, line);
  my_showtab(tab);
  return (0);
}

int	special_k(char **tab, int m)
{
  int	i;
  int	sav_i;
  int	nb1;
  int	nb2;

  i = 1;
  nb1 = 0;
  nb2 = 0;
  while (tab[i + 1] != NULL)
    {
      if (count_stick_on_line(tab, i) == 1)
	nb1++;
      else if (count_stick_on_line(tab, i) > 1)
	{
	  nb2++;
	  sav_i = i;
	}
      i++;
    }
  if (nb2 == 1 && (nb1 % 2 == 1) && (count_stick_on_line(tab, sav_i) <= m))
    return (my_remove(tab, sav_i, count_stick_on_line(tab, sav_i)));
  if (nb2 == 1 && (nb1 % 2 == 0) && (count_stick_on_line(tab, sav_i) - 1 <= m))
    return (my_remove(tab, sav_i, count_stick_on_line(tab, sav_i) - 1));
  return (1);
}

int	ai_turn(char **tab, int max_matches)
{
  int	xor;
  int	remove;
  int	i;

  i = 1;
  my_putstr("\nAI's turn...\n");
  if (special_k(tab, max_matches) == 0)
    return (0);
  xor = get_xor(tab);
  while (tab[i + 1] != NULL)
    {
      remove = bin_to_dec(xor ^ dec_to_bin(count_stick_on_line(tab, i)));
      if ((remove = count_stick_on_line(tab, i) - remove) > 0
	  && remove <= max_matches)
	return (my_remove(tab, i, remove));
      i++;
    }
  i = 1;
  while (tab[i + 1] != NULL && count_stick_on_line(tab, i) == 0)
    i++;
  return (my_remove(tab, i, 1));
}
