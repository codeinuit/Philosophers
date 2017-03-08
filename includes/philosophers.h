/*
** philosophers.h for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 21:41:21 2017 Lucas Debouté
** Last update Wed Mar  8 22:53:59 2017 Lucas Debouté
*/

#ifndef _PHILOSOPHERS_H
# define _PHILOSOPHERS_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_RESET "\x1b[0m"

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/* FUNCTION
** DECLARATIONS
*/

int	check_arguments(int argc, char **argv);
int	check_all_parameters(char **argv);
int	display_error(char *error);

#endif /* _PHILOSOPHERS_H */
