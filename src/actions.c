/*
** actions.c for philosophers in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Sat Mar 11 14:27:21 2017 Lucas Debouté
** Last update Fri Mar 17 11:51:01 2017 Lucas Debouté
*/

#include "philosophers.h"

void	action_eat(t_philo *philo)
{
  lphilo_take_chopstick(&philo->chopsticks);
  lphilo_take_chopstick(&philo->neighbor->chopsticks);
  lphilo_eat();
  philo->action = EAT;
  philo->bowl -= 1;
  pthread_mutex_unlock(&philo->chopsticks);
  pthread_mutex_unlock(&philo->neighbor->chopsticks);
  lphilo_release_chopstick(&philo->chopsticks);
  lphilo_release_chopstick(&philo->neighbor->chopsticks);
  usleep(100);
}

void	action_think(t_philo *philo)
{
  lphilo_take_chopstick(&philo->chopsticks);
  lphilo_think();
  philo->action = THINK;
  pthread_mutex_unlock(&philo->chopsticks);
  lphilo_release_chopstick(&philo->chopsticks);
  usleep(100);
}

void	action_rest(t_philo *philo)
{
  lphilo_sleep();
  philo->action = REST;
  usleep(100);
}
