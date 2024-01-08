/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:55 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 18:08:14 by seongmik         ###   ########.fr       */
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
	char	*pwd;
	char	*oldpwd;
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
int			judge_isspace(char c);
int			judge_isalldigit(char *str);
int			judge_isblank(char *str);
char		*modifier_tolower(char *str);

/* ******************************** here doc ******************************** */
int			heredoc_read(char *delimiter, int *heredoc_idx);

/* ********************************* signal ********************************* */
int			set_sigquit(void);
void		set_sigint_act(void);
int			set_sigint(void);

/* ***************************** minishell utils **************************** */
void		sh_error(char *cmd, char *msg);
char		*ft_getcwd(t_shell_info *shinfo);

/* ***************************** shell initialize *************************** */
int			init_oldpwd(t_env **env, char **sholdpwd);
int			init_pwd(t_env **env, char **shpwd);
int			init_pwds(t_env **env, char **shpwd, char **sholdpwd);
int			init_env(t_env **env, char *envp[]);
int			init_sig_setting(void);
int			init_shell(t_shell_info *shinfo, char *envp[]);

/* ******************************* word expand ****************************** */
void		word_expand(t_command *cmd, t_env *env);

/* ********************************* command ******************************** */
int			execute_command(t_shell_info *shinfo, t_command *cmd, t_env **env);
t_command	*command_new(char *path, char **args, char *redirect_in, \
						char *redirect_out);

/* ********************************* builtin ******************************** */
int			return_and_free(int builtin_nbr, char *lower_path);
int			is_builtin(char *path);
int			do_builtin(t_shell_info *shinfo, char **args, t_env **env, \
						int builtin_nbr);
int			builtin_main(t_shell_info *shinfo, int argc, char *argv[], \
						char *envp[]);
int			builtin_pwd(t_shell_info *shinfo);
int			builtin_cd(t_shell_info *shinfo, char *args[], t_env **env);

#endif