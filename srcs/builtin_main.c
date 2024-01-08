/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:32:39 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 20:08:31 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// bulitin 함수의 실행을 분기하는 함수이다.
int	do_builtin(t_shell_info *shinfo, char **args, t_env **env, int builtin_nbr)
{
	if (builtin_nbr == BUILTIN_CD)
		return (builtin_cd(shinfo, args, env));
	else if (builtin_nbr == BUILTIN_ECHO)
		return (builtin_echo(args));
	else if (builtin_nbr == BUILTIN_ENV)
		return (builtin_env(*env, args));
	else if (builtin_nbr == BUILTIN_EXIT)
		return (builtin_exit(args));
	else if (builtin_nbr == BUILTIN_EXPORT)
		return (builtin_export(args, env));
	else if (builtin_nbr == BUILTIN_PWD)
		return (builtin_pwd(shinfo));
	else if (builtin_nbr == BUILTIN_UNSET)
		return (builtin_unset(env, args));
	return (0);
}
