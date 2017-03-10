##
## Makefile for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
## 
## Made by Lucas Debouté
## Login   <lucas.deboute@epitech.eu>
## 
## Started on  Wed Mar  8 22:04:17 2017 Lucas Debouté
## Last update Fri Mar 10 17:30:28 2017 Lucas Debouté
##

CC	= gcc -lpthread

RM	= rm -f

CFLAGS	= -Wall -Wextra -I./includes -L./lib

SRCS	= src/main.c		\
	  src/check_error.c	\
	  src/parser.c		\
	  src/help.c		\
	  src/init.c		\
	  src/display.c

NAME	= philo

OBJS	= $(SRCS:.c=.o)

all: 	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
