/*
** my_power_rec.c for my_power_rec in /home/benjamin.g/delivery/CPool_Day05
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Oct  7 14:14:32 2016 Benjamin GAYMAY
** Last update Tue Feb 14 16:35:42 2017 Benjamin GAYMAY
*/

#include "my.h"

int	my_power_rec(int nb, int p)
{
  int	nbr;

  if (p < 0)
    nbr = 0;
  else
    {
      nbr = 1;
      if (p > 0)
	nbr = my_power_rec(nb, p - 1) * nb;
    }
  return (nbr);
}
