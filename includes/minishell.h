/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:55 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 15:33:16 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ***************************** custom headers ***************************** */
# include "../srcs/libft/libft.h"
# include "builtin.h"
# include "env.h"

/* ***************************** system headers ***************************** */
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

/* ******************************** defines ********************************* */
# define EXIT_SUCCESS		0
# define EXIT_FAILURE		1
# define SUCCESS			0
# define FAILURE			1
# define INT_MAX			2147483647
# define INT_MIN			-2147483648
# define HERE_DOC_TEMP		"/tmp/sh-thd-"

/* ****************************** type defines ****************************** */
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

/* ****************************** string utils ****************************** */
int			ft_isspace(char c);
int			is_all_digit(char *str);
char		*ft_str_tolower(char *str);
int			is_blank(char *str);

/* ******************************** here doc ******************************** */
int			heredoc_read(char *delimiter, int *heredoc_idx);

/* ********************************* signal ********************************* */
int			set_sigquit(void);
void		set_sigint_act(void);
int			set_sigint(void);
int			init_sig_setting(void);

/* ***************************** minishell utils **************************** */
void		sh_error(char *cmd, char *msg);

/* ******************************* word expand ****************************** */
void		word_expand(t_command *cmd, t_env *env);

/* ********************************* command ******************************** */
int			execute_command(t_command *cmd, t_env *env);
t_command	*command_new(char *path, char **args, char *redirect_in, \
						char *redirect_out);

/* ********************************* builtin ******************************** */
int			return_and_free(int builtin_nbr, char *lower_path);
int			is_builtin(char *path);
int			do_builtin(char **args, t_env *env, int builtin_nbr);

#endif