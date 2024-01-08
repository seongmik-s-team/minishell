/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:55 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 14:22:43 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../srcs/libft/libft.h"
# include "builtin.h"
# include "env.h"

# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <signal.h>

# define EXIT_SUCCESS		0
# define EXIT_FAILURE		1
# define SUCCESS			0
# define FAILURE			1
# define INT_MAX			2147483647
# define INT_MIN			-2147483648
# define HERE_DOC_TEMP		"/tmp/sh-thd-"

typedef struct s_shell_info
{
	int		heredoc_idx;
	t_env	*env;
}				t_shell_info;

typedef struct s_command
{
	char				*path;
	char				**args;
	char				*redirect_in;
	char				*redirect_out;
	int					type;
	struct s_command	*next;
}				t_command;

int			is_all_digit(char *str);
int			heredoc_read(char *delimiter, int *heredoc_idx);
int			init_sig_setting(void);
void		sh_error(char *cmd, char *msg);
void		word_expand(t_command *cmd, t_env *env);
int			ft_isspace(char c);
int			execute_command(t_command *cmd, t_env *env);
t_command	*command_new(char *path, char **args, char *redirect_in, \
						char *redirect_out);
int			is_builtin(char *path);
int			do_builtin(char **args, t_env *env, int builtin_nbr);

#endif