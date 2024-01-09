/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:27:58 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 13:23:57 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// builtin_unset() 함수는 unset 명령어를 실행하는 함수이다.
// 인자가 여러개면 모두 지워야 한다?
int	builtin_unset(char **args, t_env **env)
{
	size_t	i;

	i = 1;
	while (args[i] != NULL)
	{
		env_del(env, args[i]);
		i++;
	}
	return (SUCCESS);
}

// // execve()로 실행되는 경우
// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_env	*env;

// 	(void) argc;
// 	init_env(&env, envp);
// 	return (builtin_unset(env, argv[1]));
// }
