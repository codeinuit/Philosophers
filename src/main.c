/*
** main.c for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 22:06:28 2017 Lucas Debouté
** Last update Wed Mar  8 22:52:33 2017 Lucas Debouté
*/

#include "philosophers.h"

int	main(int argc, char **argv)
{
  if (check_arguments(argc, argv) != 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
