/*
** check_error.c for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo/src
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 21:38:46 2017 Lucas Debouté
** Last update Wed Mar  8 22:53:23 2017 Lucas Debouté
*/

#include "philosophers.h"

int	display_error(char *error)
{
  fprintf(stderr, "[" ANSI_COLOR_RED "Error" ANSI_COLOR_RESET "] %s\n", error);
  fprintf(stderr, "Use -h flag for more informations about its usage\n");
  return (EXIT_FAILURE);
}

int	check_all_parameters(char **argv)
{
  int	i;
  int	e;
  int	p;

  e = 0;
  p = 0;
  i = 0;
  while (++i != 5)
    {
      if (strcmp(argv[i], "-p") == 0)
	p += 1;
      if (strcmp(argv[i], "-e") == 0)
	e += 1;
    }
  if (p == 1 && e == 1)
    return (0);
  else
    return (EXIT_FAILURE);
}

int	check_arguments(int argc, char **argv)
{
  if (argc != 5)
    return (display_error("Insuffisant number of arguments."));
  if (strcmp(argv[1], "-p") != 0 &&
      strcmp(argv[1], "-e") != 0 &&
      strcmp(argv[3], "-p") != 0 &&
      strcmp(argv[3], "-e") != 0)
    return (display_error("Wrong flag"));
  if (atoi(argv[2]) <= 0 ||
      atoi(argv[4]) <= 0)
    return (display_error("Numbers must be a positive values"));
  if (check_all_parameters(argv) == EXIT_FAILURE)
    return (display_error("Missing flag."));
  return (0);
}
