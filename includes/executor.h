/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:47:22 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 17:31:24 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"
# include "builtin.h"
# include "exit_status.h"
# include "env.h"

typedef struct s_command
{
	char				*path;
	char				**args;
	char				*redirect_in;
	char				*redirect_out;
	int					type;
	struct s_command	*next;
}				t_command;

int			execute_command(t_command *cmd, t_env *env);
t_command	*command_new(char *path, char **args, char *redirect_in, \
						char *redirect_out);
int			do_builtin(t_command *cmd, t_env *env, int builtin_nbr);

#endif
