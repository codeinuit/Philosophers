/*
** philosophers.h for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 21:41:21 2017 Lucas Debouté
** Last update Wed Mar  8 23:17:20 2017 Lucas Debouté
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

/*
** STRUCT
*/

typedef struct	s_philosophers
{
  int		philosophers;
  int		occurences;
}		t_philosophers;
 
/* FUNCTION
** DECLARATIONS
*/

int	check_arguments(int argc, char **argv);
int	check_all_parameters(char **argv);
int	display_error(char *error);
int	get_values(char **argv, t_philosophers *philo);
int	get_philosophers(char **argv);
int	get_occurences(char **argv);


#endif /* _PHILOSOPHERS_H */