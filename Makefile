# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:29:12 by miahmadi          #+#    #+#              #
#    Updated: 2022/10/23 19:17:07 by miahmadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a
NAME_BONUS = pipex_a.a
PROG = pipex
PROG_BONUS = pipex_a

LIBFT = ./libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES =	main \
		utils \
		
FILES_B = bonus \
		  utils \
		  utils_bonus \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROG): $(NAME)
	$(CC) $(NAME) -o $(PROG) $(CFLAGS) -g

$(PROG_BONUS): $(NAME_BONUS)
	$(CC) $^ -o $@ $(CFLAGS) -g

$(NAME): libftmake $(OBJS)
	$(AR) $@ $(OBJS)

$(NAME_BONUS): libftmake_bonus $(OBJS_B)
	$(AR) $@ $(OBJS_B)

all: $(PROG)

bonus: $(PROG_BONUS)

libftmake:
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)

libftmake_bonus:
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	@cd $(LIBFT) && $(MAKE) clean

fclean: clean
	$(RM) $(PROG) $(NAME) $(PROG_BONUS) $(NAME_BONUS)
	@cd $(LIBFT) && $(MAKE) fclean

re: clean all

.PHONY: bonus all clean fclean re