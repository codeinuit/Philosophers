##
## Makefile for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
## 
## Made by Lucas Debouté
## Login   <lucas.deboute@epitech.eu>
## 
## Started on  Wed Mar  8 22:04:17 2017 Lucas Debouté
## Last update Sat Mar 11 12:31:35 2017 Lucas Debouté
##

CC	= gcc -L./lib

RM	= rm -f

CFLAGS	= -Wall -Wextra -I./includes -lpthread 

SRCS	= src/main.c		\
	  src/check_error.c	\
	  src/parser.c		\
	  src/help.c		\
	  src/init.c		\
	  src/display.c		\
	  src/check.c

NAME	= philo

OBJS	= $(SRCS:.c=.o)

all: 	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lriceferee

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
