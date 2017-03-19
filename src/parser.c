/*
** parser.c for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo/src
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 22:31:07 2017 Lucas Debouté
** Last update Sun Mar 19 22:44:34 2017 Lucas Debouté
*/

#include "philosophers.h"

int	get_philosophers(char **argv)
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

int	get_occurences(char **argv)
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

int	get_values(char **argv, t_table *table)
{
  table->philosophers = get_philosophers(argv);
  table->occurences = get_occurences(argv);
  if (table->philosophers == 1)    
    return (EXIT_FAILURE);
  if (table->philosophers >= 2 &&
      table->occurences >= 0)
    return (0);
  return (EXIT_FAILURE);
}
