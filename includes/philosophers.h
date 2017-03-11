/*
** philosophers.h for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
** 
** Made by Lucas Debouté
** Login   <lucas.deboute@epitech.eu>
** 
** Started on  Wed Mar  8 21:41:21 2017 Lucas Debouté
** Last update Sat Mar 11 12:04:15 2017 Lucas Debouté
*/

#ifndef PHILOSOPHERS_H_
# define PHILOSOPHERS_H_

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_RESET "\x1b[0m"

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# include "extern.h"

/*
** STRUCT
*/

typedef enum		t_action
  {
    EAT,
    THINK,
    REST,
    NOTHING
  }			e_action;

typedef struct		s_philo
{
  int			id;
  int			bowl;
  //  int			chopsticks;
  int			has_resting;
  pthread_mutex_t	chopsticks;
  struct s_philo	*neighbor;
  e_action		action;
}			t_philo;

typedef struct		s_table
{
  t_philo		*philos;
  int			philosophers;
  int			occurences;
  //  pthread_mutex_t	*chopsticks;
  pthread_t		*threads;
}			t_table;

/* 
** FUNCTIONS
** DECLARATIONS
*/

int	check_arguments(int argc, char **argv);
int	check_all_parameters(char **argv);
int	display_error(char *error);
int	get_values(char **argv, t_table *table);
int	get_philosophers(char **argv);
int	get_occurences(char **argv);

int	init_philosopher(t_table *table);
int	init_simulator(t_table *table);

void	display_status(t_table *table);
void	display_help();

void	*philosophers(void *data);

#endif /* !PHILOSOPHERS_H */
