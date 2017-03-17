/*
** init.c for philosophers in /home/codeine/Projects/B4/PSU/PSU_2016_philo/src
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Thu Mar  9 19:06:02 2017 Lucas Debouté
** Last update Fri Mar 17 11:15:07 2017 Lucas Debouté
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
      table->philos[i].action = THINK;
      table->philos[i].bowl = table->occurences;
      pthread_mutex_init(&table->philos[i].chopsticks, NULL);
      table->philos[i].has_resting = 0;
      if (i == table->philosophers - 1)
	table->philos[i].neighbor = &table->philos[0];
      else
	table->philos[i].neighbor = &table->philos[i + 1];
    }
  return (0);
}

int	init_simulator(t_table *table)
{
  if (init_philosopher(table) != 0)
    return (1);
  if ((table->threads = malloc(sizeof(pthread_t) * table->philosophers))
      == NULL)
    return (1);
  return (0);
}
