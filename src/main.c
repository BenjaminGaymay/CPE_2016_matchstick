/*
** main.c for main in /home/benjamin.g/delivery/CPE_2016_matchstick_bootstrap
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Feb 13 10:22:45 2017 Benjamin GAYMAY
** Last update Sun Feb 26 14:44:28 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my_printf.h"
#include "my.h"

int	count_stick_on_line(char **tab, int line)
{
  int	i;
  int	stick;

  i = 0;
  stick = 0;
  while (tab[line][i] != '\0')
    {
      if (tab[line][i] == '|')
	stick++;
      i++;
    }
  return (stick);
}

int	check_lose(char **tab)
{
  int	i;
  int	sticks;

  i = 0;
  sticks = 0;
  while (tab[i] != NULL)
    sticks += count_stick_on_line(tab, i++);
  return (sticks == 0 ? 1 : 0);
}

int	start_game(char **tab, int line_max, int matches_max)
{
  while (1)
    {
      if (player_turn(tab, line_max, matches_max) == -1)
	return (0);
      if (check_lose(tab) == 1)
	return (2);
      ai_turn(tab, matches_max);
      if (check_lose(tab) == 1)
	return (1);
    }
}

int	main(int ac, char *av[])
{
  char	**tab;
  int	ret;

  if (ac == 3)
    tab = fill_my_void_map(my_getnbr(av[1]));
  else
    return (my_disp_err("Error: invalid number of arguments\n"));
  if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
    return (my_disp_err("Error: write only numbers\n"));
  my_showtab(tab);
  ret = start_game(tab, my_getnbr(av[1]), my_getnbr(av[2]));
  if (ret == 2)
    my_putstr("You lost, too bad...\n");
  else if (ret == 1)
    my_putstr("I lost... snif... but I'll get you next time!!\n");
  free_array(tab);
  return (ret);
}
