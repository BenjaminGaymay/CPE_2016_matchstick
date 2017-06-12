/*
** bin.c for matchstick in /home/benjamin.g/delivery/CPE_2016_matchstick
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Feb 20 13:29:14 2017 Benjamin GAYMAY
** Last update Mon Feb 20 13:32:22 2017 Benjamin GAYMAY
*/

#include "my.h"

int	dec_to_bin(int	dec)
{
  int	bin;
  int	zero;

  bin = 0;
  zero = 0;
  while (dec != 0)
    {
      if (bin == 0 && dec % 2 == 0)
	zero++;
      bin *= 10;
      bin = bin + dec % 2;
      dec /= 2;
    }
  while (zero != 0)
    {
      bin *= 10;
      zero--;
    }
  return (bin);
}

int	bin_to_dec(int bin)
{
  int	dec;
  int	i;

  dec = 0;
  i = 0;
  while (bin != 0)
    {
      if (bin % 10 == 1)
	dec += my_power_rec(2, i);
      i++;
      bin /= 10;
    }
  return (dec);
}
