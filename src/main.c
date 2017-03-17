/*
** main.c for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 22:06:28 2017 Lucas Debouté
** Last update Sat Mar 11 16:34:11 2017 Lucas Debouté
*/

#include "philosophers.h"

void*			philosophers(void *data)
{
  t_philo		*philo;
  int			right_chopstick;
  int			left_chopstick;

  philo = (t_philo *) data;
  while (philo->bowl > 0)
    {
      if (philo->action == EAT)
	action_rest(philo);
      else
	{
	  right_chopstick = pthread_mutex_lock(&philo->chopsticks);
	  left_chopstick = pthread_mutex_trylock(&philo->neighbor->chopsticks);
	 if (!right_chopstick && !left_chopstick)
	    {
	      action_eat(philo);
	    }
	 else if (!right_chopstick || !left_chopstick)
	    {
	      action_think(philo);
	    }
	}
      /*if (pthread_mutex_trylock(&philo->chopsticks) == 0)
	{
	  if (pthread_mutex_trylock(&philo->neighbor->chopsticks) == 0)
	    {
	      action_eat(philo);
	    }
	  else
	    {
	      action_think(philo);
	    }
	}
      if (philo->action == EAT)
      action_rest(philo);*/
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
    pthread_create(&table->threads[i], NULL, philosophers, (void *) &table->philos[i]);
  i = -1;
  while (check_bowl_empty(table))
    {
      //usleep(100);
      //display_status(table);
    }
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
  get_values(argv, &table);
  if (philosophers_simulator(&table) == 1)
    return (EXIT_FAILURE);
  //  pthread_exit(NULL);
  RCFCleanup();
  return (EXIT_SUCCESS);
}
