/*
** main.c for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 22:06:28 2017 Lucas Debouté
** Last update Thu Mar  9 19:35:15 2017 Lucas Debouté
*/

#include "philosophers.h"

int			philosophers_simulator(t_table *table)
{
  if (init_simulator(table) == 0)
    return (1);
  return (0);
}

int			main(int argc, char **argv)
{
  t_table		table;

  if (argc == 2 && strcmp(argv[1], "-h") == 0)
    {
      display_help();
      return (EXIT_SUCCESS);
    }
  if (check_arguments(argc, argv) != 0)
    return (EXIT_FAILURE);
  get_values(argv, &table);
  if (philosophers_simulator(&table) == 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
