/*
** extern.h for philosophe in /home/codeine/Projects/B4/PSU/PSU_2016_philo/includes
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Fri Mar 17 11:19:15 2017 Lucas Debouté
** Last update Fri Mar 17 11:19:40 2017 Lucas Debouté
*/

#ifndef LIBRICEFEREE_EXTERN_
# define LIBRICEFEREE_EXTERN_

# include <pthread.h>

/* MUST be the first instruction in your main to Init the library */
int	RCFStartup(int ac, char **av);

/* MUST be called after use to release library ressources */
void	RCFCleanup();

/* Call it when a philo is eating */
int	lphilo_eat();

/* Call it when a philo is sleeping */
int	lphilo_sleep();

/* Call it when a philo is thinking */
int	lphilo_think();

/* Call it when a philo takes a chopstick */
int	lphilo_take_chopstick(const pthread_mutex_t *mutex_id);

/* Call it when a philo releases a chopstick */
int	lphilo_release_chopstick(const pthread_mutex_t *mutex_id);

#endif /* !LIBRICEFEREE_EXTERN_ */
