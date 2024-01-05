/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:32:39 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 17:05:30 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// bulitin 함수의 실행을 분기하는 함수이다.
int	do_builtin(t_command *cmd, t_env *env, int builtin_nbr)
{
	if (builtin_nbr == BUILTIN_CD)
		return (builtin_cd(env_len(env), cmd->args));
	else if (builtin_nbr == BUILTIN_ECHO)
		return (builtin_echo(env_len(env), cmd->args));
	else if (builtin_nbr == BUILTIN_ENV)
		return (builtin_env(env, cmd->args));
	else if (builtin_nbr == BUILTIN_EXIT)
		return (builtin_exit(cmd->args));
	else if (builtin_nbr == BUILTIN_EXPORT)
		return (builtin_export(cmd->args, env));
	else if (builtin_nbr == BUILTIN_PWD)
		return (builtin_pwd());
	else if (builtin_nbr == BUILTIN_UNSET)
		return (builtin_unset(env, &(cmd->args[1])));
	return (0);
}
