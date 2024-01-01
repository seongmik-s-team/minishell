
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes
SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/minishell.c
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