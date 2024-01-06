# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 19:51:24 by seongmik          #+#    #+#              #
#    Updated: 2024/01/06 18:59:37 by seongmik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

INCLUDES 	:=	-I./includes
SRCS_DIR 	:=	srcs
LIB_DIR		:=	srcs/libft
SRCS		:=	$(SRCS_DIR)/minishell.c \
				$(SRCS_DIR)/builtin_main.c \
				$(SRCS_DIR)/builtin_echo.c \
				$(SRCS_DIR)/builtin_cd.c \
				$(SRCS_DIR)/builtin_pwd.c \
				$(SRCS_DIR)/builtin_export.c \
				$(SRCS_DIR)/builtin_env.c \
				$(SRCS_DIR)/builtin_unset.c \
				$(SRCS_DIR)/builtin_exit.c \
				$(SRCS_DIR)/ft_env.c \
				$(SRCS_DIR)/ft_env_util.c \
				$(SRCS_DIR)/executor_command.c \
				$(SRCS_DIR)/string_util.c \
				$(SRCS_DIR)/command.c \
				$(SRCS_DIR)/heredoc.c \
				$(SRCS_DIR)/setting_signal.c \
				$(SRCS_DIR)/shell_error.c

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling..."
	@$(MAKE) -C $(LIB_DIR);
	@cp $(LIB_DIR)/libft.a libft.a
	@$(CC) $(CFLAGS) -o $@ $^ libft.a -lreadline # -fsanitize=address
	@echo "Done !"

%.o : %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "Done !"

clean :
	@echo "Cleaning Objects..."
	@$(MAKE) -C $(LIB_DIR) clean;
	@rm -rf libft.a
	@rm -rf $(OBJS)
	@echo "Done !"

fclean : clean
	@echo "Cleaning..."
	@$(MAKE) -C $(LIB_DIR) fclean;
	@rm -rf $(NAME)
	@echo "Done !"

re : fclean all

.PHONY: all clean fclean re