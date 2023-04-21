# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 18:38:04 by fgarzi-c          #+#    #+#              #
#    Updated: 2023/04/21 02:09:13 by fgarzi-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
LIB_L = libft/libft.a
LIB_F = philo.a
SRCS = philo.c ft_free.c ft_handle_input.c ft_routine.c \
	ft_routine_utils.c ft_create_threads.c ft_master.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(%.c)
	@make -C libft/
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rcs $(LIB_F) $(OBJS)
	@$(CC) $(CFLAGS) $(LIB_L) $(LIB_F) $(OBJS) -o $(NAME)

%.c: %.o
	@$(CC) $(CFLAGS) -o $<

clean:
	@rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME) $(LIB_F)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
