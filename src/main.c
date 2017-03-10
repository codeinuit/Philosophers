/*
** main.c for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 22:06:28 2017 Lucas Debouté
** Last update Fri Mar 10 16:39:30 2017 Lucas Debouté
*/

#include "philosophers.h"

void*			philosophers(void *data)
{
  t_philo		*philo;

  philo = (t_philo *) data;
  while (philo->bowl > 0)
    {
      if (pthread_mutex_trylock(&philo->chopsticks) == 0)
	{
	if (pthread_mutex_trylock(&philo->neighbor->chopsticks) == 0)
	    {
	      philo->action = EAT;
	      philo->bowl -= 1;
	      sleep(1);
	      pthread_mutex_unlock(&philo->neighbor->chopsticks);
	    }
	else
	  {
	    philo->action = THINK;
	  }
	pthread_mutex_unlock(&philo->chopsticks);
	}
      philo->action = REST;
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
  	      usleep(100);
  display_status(table);
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
  if (check_arguments(argc, argv) != 0)
    return (EXIT_FAILURE);
  get_values(argv, &table);
  if (philosophers_simulator(&table) == 1)
    return (EXIT_FAILURE);
  pthread_exit(NULL);
  return (EXIT_SUCCESS);
}
