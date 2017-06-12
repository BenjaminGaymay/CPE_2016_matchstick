/*
** matchstick.c for matchstick in /home/benjamin.g/delivery/CPE_2016_matchstick/matchstick
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Feb 13 13:51:13 2017 Benjamin GAYMAY
** Last update Wed Feb 15 10:25:39 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"
#include "my.h"

void	put_stick_on_map(char **tab, int nb_lin, int nb_col)
{
  int	i;
  int	col;
  int	col_max;
  int	col_min;

  i = 0;
  col = 0;
  while (i < nb_lin - 1)
    {
      col = 0;
      col_max = nb_col / 2 + i - 1;
      col_min = nb_col / 2 - i + 1;
      if (i !=0)
	{
	  while (col < col_min)
	    col++;
	  while (col <= col_max)
	    tab[i][col++] = '|';
	}
      i++;
    }
}

char	**malloc_array(int nb_line, int nb_col)
{
  int	i;
  int	columns;
  char	**array;

  array = malloc(sizeof(char *) * (nb_line + 1));
  if (array == NULL)
    return (NULL);
  array[0] = NULL;
  i = 0;
  while (i < nb_line)
    {
      if ((array[i] = malloc(sizeof(char) * (nb_col + 1))) == NULL)
	return (NULL);
      array[i][0] = '\0';
      i++;
    }
  return (array);
}

char	**fill_my_void_map(int nb_lin)
{
  char	**tab;
  int	i;
  int	j;

  i = 0;
  if ((tab = malloc_array(nb_lin + 2, (nb_lin * 2 + 2))) == NULL)
    return (NULL);
  while (i < nb_lin + 2)
    {
      j = 0;
      while (j < (nb_lin * 2 + 1))
	{
	  if (i == 0 || i == nb_lin + 1)
	    tab[i][j] = '*';
	  else
	    tab[i][j] = (j == 0 || j == (nb_lin * 2) ? '*' : ' ');
	  j++;
	}
      tab[i][j] = '\0';
      i++;
    }
  tab[i] = NULL;
  put_stick_on_map(tab, nb_lin + 2, (nb_lin * 2 + 1));
  return (tab);
}

void	remove_matches(char **tab, int line, int nb_matches)
{
  int	i;

  i = my_strlen(tab[line]) - 2;
  while (nb_matches != 0)
    {
      if (tab[line][i] == '|')
	{
	  tab[line][i] = ' ';
	  nb_matches--;
	}
      i--;
    }
}
