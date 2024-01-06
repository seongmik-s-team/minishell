/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:55 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/07 02:06:06 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../srcs/libft/libft.h"
# include "executor.h"
# include "builtin.h"
# include "exit_status.h"
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

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define HERE_DOC_TEMP "/tmp/sh-thd-"

typedef struct s_shell_info
{
	int		heredoc_idx;
	t_env	*env;
}				t_shell_info;

int		is_all_digit(char *str);
int		heredoc_read(char *delimiter, int *heredoc_idx);
int		init_sig_setting(void);
void	sh_error(char *cmd, char *msg);

#endif