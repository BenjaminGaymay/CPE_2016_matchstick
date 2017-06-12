/*
** player.c for matchstick in /home/benjamin.g/delivery/CPE_2016_matchstick/src
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Feb 14 15:28:53 2017 Benjamin GAYMAY
** Last update Sun Feb 26 14:44:14 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
#include "matchstick.h"

int	my_disp_err(char *s)
{
  my_putstr(s);
  return (-1);
}

int	ask_for_the_line(char **tab, int line_max)
{
  char	*s;
  int	line;

  my_putstr("Line: ");
  if ((s = get_next_line(0)) == NULL)
    return (-2);
  if (my_str_isnum(s) == 0)
    return (my_disp_err("Error: invalid input (positive number expected)\n"));
  line = my_getnbr(s);
  free(s);
  if (line > line_max || line <= 0)
    return (my_disp_err("Error: this line is out of range\n"));
  if (count_stick_on_line(tab, line) == 0)
    return (my_disp_err("Error: not enough matches on this line\n"));
  return (line);
}

int	ask_for_the_matches(char **tab, int line_max, int line, int matches_max)
{
  char	*s;
  int	matches;
  int	stick_on_line;

  my_putstr("Matches: ");
  if ((s = get_next_line(0)) == NULL)
    return (-2);
  if (my_str_isnum(s) == 0)
    return (my_disp_err("Error: invalid input (positive number expected)\n"));
  matches = my_getnbr(s);
  free(s);
  stick_on_line = count_stick_on_line(tab, line);
  if (matches <= 0)
    return (my_disp_err("Error: you have to remove at least one match\n"));
  if (matches > matches_max)
    {
      my_printf("Error: you cannot remove more than %d", stick_on_line);
      return (my_disp_err(" matches per turn\n"));
    }
  if (stick_on_line < matches)
    return (my_disp_err("Error : not enough matches on this line\n"));
  return (matches);
}

int	player_turn(char **tab, int line_max, int matches_max)
{
  int	line;
  int	matches;

  line = -1;
  matches = -1;
  my_putstr("\nYour turn:\n");
  while (line == -1 || matches == -1)
    {
      line = ask_for_the_line(tab, line_max);
      if (line != -1 && line != -2)
	matches = ask_for_the_matches(tab, line_max, line, matches_max);
      if (line == -2 || matches == -2)
	return (-1);
    }
  remove_matches(tab, line, matches);
  my_printf("Player removed %d match(es) from line %d\n", matches, line);
  my_showtab(tab);
  return (0);
}
