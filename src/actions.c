/*
** actions.c for philosophers in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Sat Mar 11 14:27:21 2017 Lucas Debouté
** Last update Sun Mar 19 22:34:27 2017 Lucas Debouté
*/

#include "philosophers.h"

void	action_eat(t_philo *philo)
{
  if (philo->id % 2 == 1)
    {
      lphilo_take_chopstick(&philo->neighbor->chopsticks);
      pthread_mutex_lock(&philo->neighbor->chopsticks);
      pthread_mutex_lock(&philo->chopsticks);
      lphilo_take_chopstick(&philo->chopsticks);
    }
  if (philo->id % 2 == 0)
    {
      lphilo_take_chopstick(&philo->chopsticks);
      pthread_mutex_lock(&philo->chopsticks);
      lphilo_take_chopstick(&philo->neighbor->chopsticks);
      pthread_mutex_lock(&philo->neighbor->chopsticks);
    }
  lphilo_eat();
  philo->action = EAT;
  philo->bowl -= 1;
  philo->can_eat = 0;
  philo->neighbor->can_eat = 1;
  pthread_mutex_unlock(&philo->chopsticks);
  lphilo_release_chopstick(&philo->chopsticks);
  pthread_mutex_unlock(&philo->neighbor->chopsticks);
  lphilo_release_chopstick(&philo->neighbor->chopsticks);
}

void	action_think(t_philo *philo)
{
  if (philo->id % 2 == 0)
    {
      pthread_mutex_lock(&philo->chopsticks);
      lphilo_take_chopstick(&philo->chopsticks);
      lphilo_think();
      pthread_mutex_unlock(&philo->chopsticks);
      lphilo_release_chopstick(&philo->chopsticks);
    }
  else
    {
      pthread_mutex_lock(&philo->neighbor->chopsticks);
      lphilo_take_chopstick(&philo->neighbor->chopsticks);
      lphilo_think();
      pthread_mutex_unlock(&philo->neighbor->chopsticks);
      lphilo_release_chopstick(&philo->neighbor->chopsticks);
    }
  philo->action = THINK;
}

void	action_rest(t_philo *philo)
{
  lphilo_sleep();
  philo->action = REST;
}
