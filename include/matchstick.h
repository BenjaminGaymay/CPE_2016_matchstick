/*
** matchstick.h for matchstick in /home/benjamin.g/delivery/CPE_2016_matchstick
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Feb 13 13:29:21 2017 Benjamin GAYMAY
** Last update Sun Feb 26 14:44:35 2017 Benjamin GAYMAY
*/

#ifndef MATCHSTICK_H_
# define MATCHSTICK_H_

char	**fill_my_void_map(int);
void	remove_matches(char **, int, int);
int	count_stick_on_line(char **, int);
int	player_turn(char **, int, int);
int	ai_turn(char **, int);
int	dec_to_bin(int);
int	bin_to_dec(int);
int	my_disp_err(char *);

#endif /* !MATCHSTICK_H_ */
