# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 19:51:24 by seongmik          #+#    #+#              #
#    Updated: 2024/01/09 18:12:45 by seongmik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#--------------------------------default flags---------------------------------#
NAME							=	minishell
CC								=	cc
CFLAGS							=	-Wall -Wextra -Werror


#--------------------------------readline flag---------------------------------#
REDLINE_FLAG					=	-lreadline


#---------------------------this flags is for M1 mac---------------------------#
#----before make, you should install readline with brew using below command----#
#----brew install readline-----------------------------------------------------#
M1_MAC_READLINE_FLAGS			=	-L/opt/homebrew/opt/readline/lib
M1_MAC_READLINE_OBJ_FLAGS		=	-I/opt/homebrew/opt/readline/include
#------------------------------------------------------------------------------#


#----------------------------------sources-------------------------------------#
INCLUDES 						:=	-I./includes
SRCS_DIR 						:=	srcs
LIB_DIR							:=	srcs/libft
SRCS							:=	$(SRCS_DIR)/minishell.c \
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
									$(SRCS_DIR)/execute_command.c \
									$(SRCS_DIR)/string_surrounded.c \
									$(SRCS_DIR)/string_judge.c \
									$(SRCS_DIR)/string_modifier.c \
									$(SRCS_DIR)/string_get.c \
									$(SRCS_DIR)/string_quote.c \
									$(SRCS_DIR)/command.c \
									$(SRCS_DIR)/heredoc.c \
									$(SRCS_DIR)/setting_signal.c \
									$(SRCS_DIR)/shell_error.c \
									$(SRCS_DIR)/shell_free.c \
									$(SRCS_DIR)/word_expand.c \
									$(SRCS_DIR)/word_expand_util.c \
									$(SRCS_DIR)/init_shell.c \
									$(SRCS_DIR)/init_pwds.c \
									$(SRCS_DIR)/convert_wildcard.c

#----------------------------------objects-------------------------------------#
OBJS							=	$(SRCS:.c=.o)


#-----------------------------------rules--------------------------------------#
all : $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling..."
	@$(MAKE) -C $(LIB_DIR);
	@cp $(LIB_DIR)/libft.a libft.a
	@$(CC) $(CFLAGS) -o $@ $^ libft.a $(REDLINE_FLAG) $(M1_MAC_READLINE_FLAGS) #-fsanitize=address
	@echo "Done !"

%.o : %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(M1_MAC_READLINE_OBJ_FLAGS) -c $^ -o $@ 
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


#-----------------------------------phony--------------------------------------#
.PHONY: all clean fclean re