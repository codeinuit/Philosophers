/*
** main.c for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 22:06:28 2017 Lucas Debouté
** Last update Sun Mar 19 22:46:48 2017 Lucas Debouté
*/

#include "philosophers.h"

void*			philosophers(void *data)
{
  t_philo		*philo;

  philo = (t_philo *) data;
  while (philo->table->running == 1);
  while (philo->bowl > 0)
    {
      if (philo->can_eat == 1)
	{
	  if (philo->action == REST)
	    action_think(philo);
	  else if (philo->action == THINK)
	    action_eat(philo);
	  else
	    action_rest(philo);
	}
      usleep(10);
    }
  return (NULL);
}

int			philosophers_simulator(t_table *table)
{
  int			i;

  i = -1;
  if (init_simulator(table) != 0)
    return (1);
  while (++i < table->philosophers)
    pthread_create(&table->threads[i], NULL, philosophers, (void *)
		   &table->philos[i]);
  i = -1;
  table->running = 0;
  while (check_bowl_empty(table));
  empty_bowls(table);
  i = -1;
  while (++i < table->philosophers)
    pthread_join(table->threads[i], NULL);
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
  RCFStartup(argc, argv);
  if (check_arguments(argc, argv) != 0)
    return (EXIT_FAILURE);
  if (get_values(argv, &table) == EXIT_FAILURE)
    {
      display_error("Invalid number");
      return (EXIT_FAILURE);
    }
  if (philosophers_simulator(&table) == 1)
    return (EXIT_FAILURE);
  RCFCleanup();
  return (EXIT_SUCCESS);
}
