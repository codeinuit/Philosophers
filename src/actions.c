/*
** actions.c for philosophers in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Sat Mar 11 14:27:21 2017 Lucas Debouté
** Last update Fri Mar 17 10:44:13 2017 Lucas Debouté
*/

#include "philosophers.h"

void	action_eat(t_philo *philo)
{
  lphilo_take_chopstick(&philo->chopsticks);
  lphilo_take_chopstick(&philo->neighbor->chopsticks);
  lphilo_eat();
  philo->action = EAT;
  philo->bowl -= 1;
  usleep(30);
  pthread_mutex_unlock(&philo->chopsticks);
  pthread_mutex_unlock(&philo->neighbor->chopsticks);
  lphilo_release_chopstick(&philo->chopsticks);
  lphilo_release_chopstick(&philo->neighbor->chopsticks);
  //sleep(1);
}

void	action_think(t_philo *philo)
{
  lphilo_take_chopstick(&philo->chopsticks);
  lphilo_think();
  philo->action = THINK;
  pthread_mutex_unlock(&philo->chopsticks);
  lphilo_release_chopstick(&philo->chopsticks);
  //sleep(1);
}

void	action_rest(t_philo *philo)
{
  lphilo_sleep();
  usleep(30);
  philo->action = REST;
  //sleep(1);
}
