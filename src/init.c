/*
** init.c for philosophers in /home/codeine/Projects/B4/PSU/PSU_2016_philo/src
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Thu Mar  9 19:06:02 2017 Lucas Debouté
** Last update Thu Mar  9 20:56:55 2017 Lucas Debouté
*/

#include "philosophers.h"

int	init_philosopher(t_table *table)
{
  int	i;

  i = -1; 
  if ((table->philos = malloc(sizeof(t_philo) * table->philosophers)) == NULL)
    return (1);
  while (++i < table->philosophers)
    {
      table->philos[i].id = i;
      table->philos[i].action = NOTHING;
      table->philos[i].bowl = table->occurences;
      table->philos[i].chopsticks = 1;
      if (i == table->philosophers)
	table->philos[i].neighbor = &table->philos[0];
      else
	table->philos[i].neighbor = &table->philos[i + 1];
    }
  return (0);
}

int	init_simulator(t_table *table)
{
  init_philosopher(table);
  return (0);
}
