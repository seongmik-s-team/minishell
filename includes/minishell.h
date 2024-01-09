/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:55 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 13:22:48 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ***************************** custom headers ***************************** */
# include "../srcs/libft/libft.h"

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
# include <stddef.h>

/* ******************************** defines ********************************* */
# define SUCCESS			0
# define FAILURE			1
# define INT_MAX			2147483647
# define INT_MIN			-2147483648
# define HERE_DOC_TEMP		"/tmp/sh-thd-"

# define BUILTIN_ECHO		1
# define BUILTIN_CD			2
# define BUILTIN_PWD		3
# define BUILTIN_EXPORT		4
# define BUILTIN_UNSET		5
# define BUILTIN_ENV		6
# define BUILTIN_EXIT		7

/* ****************************** type defines ****************************** */
typedef struct s_shell_info
{
	int		heredoc_idx;
	t_env	*env;
	char	*pwd;
	char	*oldpwd;
}				t_shell_info;

typedef struct s_redirect
{
	int		type;
	char	*file;
	char	*delimiter;
}				t_redirect;

typedef struct s_command
{
	char				**args;
	t_redirect			**redirects;
	int					symbol;
	struct s_command	*left;
	struct s_command	*right;
}				t_command;

typedef struct s_pair
{
	char	*key;
	char	*value;
}				t_pair;

typedef struct s_env
{
	t_pair			*pair;
	struct s_env	*prev;
	struct s_env	*next;
}				t_env;

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

/* *********************************** env ********************************** */
t_env		*env_find(t_env *env, char *key);
int			env_del(t_env **env, char *key);
int			env_add(t_env **env, char *key, char *value);
size_t		find_equal(const char *env_str);
int			init_env(t_env **env, char *envp[]);
char		**env_to_envp(t_env *env);
size_t		env_len(t_env *env);
t_env		*env_copy(t_env *origin);
void		free_env(t_env *env);
int			init_env(t_env **env, char *envp[]);
t_pair		make_pair(char *str);

/* ********************************* builtin ******************************** */
int			return_and_free(int builtin_nbr, char *lower_path);
int			is_builtin(char *path);
int			do_builtin(t_shell_info *shinfo, char **args, t_env **env, \
						int builtin_nbr);
int			builtin_main(t_shell_info *shinfo, int argc, char *argv[], \
						char *envp[]);
int			builtin_pwd(t_shell_info *shinfo);
int			builtin_cd(char *args[], t_env **env, t_shell_info *shinfo);
int			builtin_echo(char *args[]);
int			builtin_export(char *args[], t_env **env);
int			builtin_env(char *args[], t_env *env);
int			builtin_unset(char **args, t_env **env);
int			builtin_exit(char *args[]);

#endif