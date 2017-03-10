##
## Makefile for philosophes in /home/codeine/Projects/B4/PSU/PSU_2016_philo
## 
## Made by Lucas Debouté
## Login   <lucas.deboute@epitech.eu>
## 
## Started on  Wed Mar  8 22:04:17 2017 Lucas Debouté
## Last update Fri Mar 10 02:02:50 2017 Lucas Debouté
##

CC	= gcc -lpthread -g
RM	= rm -f

CFLAGS	= -Wall -Wextra -I./includes -L./lib

SRCS	= src/main.c		\
	  src/check_error.c	\
	  src/parser.c		\
	  src/help.c		\
	  src/init.c		\
	  src/display.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
