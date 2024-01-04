# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 19:51:24 by seongmik          #+#    #+#              #
#    Updated: 2024/01/04 14:48:34 by seongmik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes
SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/minishell.c \
$(SRCS_DIR)/builtin_main.c \
$(SRCS_DIR)/builtin_echo.c \
$(SRCS_DIR)/builtin_cd.c \
$(SRCS_DIR)/builtin_pwd.c \
$(SRCS_DIR)/builtin_export.c \
$(SRCS_DIR)/builtin_env.c \
$(SRCS_DIR)/builtin_unset.c \
$(SRCS_DIR)/builtin_exit.c \
$(SRCS_DIR)/ft_env.c \
$(SRCS_DIR)/executor_command.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)


$(NAME) : $(OBJS)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Done !"

%.o : %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "Done !"

clean :
	@echo "Cleaning Objects..."
	@rm -rf $(OBJS)
	@echo "Done !"

fclean : clean
	@echo "Cleaning..."
	@rm -rf $(NAME)
	@echo "Done !"

re : fclean all

.PHONY: all clean fclean re