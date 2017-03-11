/*
** check.c for check in /home/nevastuica/B4/PSU/PSU_2016_philo
** 
** Made by Noémie CARON
** Login   <noemie.caron@epitech.eu>
** 
** Started on  Fri Mar 10 18:39:04 2017 Noémie CARON
** Last update Sat Mar 11 14:25:34 2017 Lucas Debouté
*/

#include "philosophers.h"

int	check_bowl_empty(t_table *table)
{
  int	i;

  i = 0;
  while (i < table->philosophers)
    {
      if (table->philos[i].bowl == 0)
	return (0);
      i++;
    }
  return (1);
}

void	empty_bowls(t_table *table)
{
  int	i;

  i = -1;
  while (++i < table->philosophers)
    table->philos[i].bowl = 0;
}
