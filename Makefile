# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 17:00:30 by marvin            #+#    #+#              #
#    Updated: 2023/09/07 08:58:54 by mzarichn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread

SRC_PATH = ./

OBJ_PATH = ./objects

SRC_NAME = philosophers.c checker.c time.c init.c

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@clear
	@echo "$(GREEN)$(NAME) compiled $(DEFAULT)"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p objects
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -rf objects/
	@clear
	@echo "$(YELLOW)$(NAME).o files are removed$(DEFAULT)"

fclean:
	@rm -rf objects/
	@rm -f $(NAME)
	@clear
	@echo "$(RED)$(NAME) is deleted$(DEFAULT)"


re: fclean all