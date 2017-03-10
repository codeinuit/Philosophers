/*
** display.c for philosophers in /home/codeine/Projects/B4/PSU/PSU_2016_philo/src
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Fri Mar 10 01:35:43 2017 Lucas Debouté
** Last update Fri Mar 10 17:02:19 2017 Lucas Debouté
*/

#include "philosophers.h"

void	display_status(t_table *table)
{
  int	i;

  i = -1;
  while (++i < table->philosophers)
    {
      printf("[philosopher %d]\nSTAT :  ", table->philos[i].id);
      if (table->philos[i].action == EAT)
	printf("eating\n");
      else if (table->philos[i].action == REST)
	printf("resting\n");
      else if (table->philos[i].action == THINK)
	printf("thinking\n");
      printf("\n");
    }
}
