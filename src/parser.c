/*
** parser.c for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo/src
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 22:31:07 2017 Lucas Debouté
** Last update Wed Mar  8 23:14:31 2017 Lucas Debouté
*/

#include "philosophers.h"

int	get_philosophers(char **argv)
{
  int	i;

  i = 0;
  while (++i != 4)
    {
      if (strcmp(argv[i], "-e") == 0)
	return (atoi(argv[i + 1]));
    }
  return (0);
}

int	get_occurences(char **argv)
{
  int	i;

  i = 0;
  while (++i != 4)
    {
      if (strcmp(argv[i], "-p") == 0)
	return (atoi(argv[i + 1]));
    }
  return (0);
}

int	get_values(char **argv, t_philosophers *philo)
{
  philo->philosophers = get_philosophers(argv);
  philo->occurences = get_occurences(argv);
  if (philo->philosophers >= 0 &&
      philo->philosophers >= 0)
    return (0);
  return (EXIT_FAILURE);
}