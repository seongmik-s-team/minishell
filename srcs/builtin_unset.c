/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:27:58 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 17:05:40 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// builtin_unset() 함수는 unset 명령어를 실행하는 함수이다.
// 인자가 여러개면 모두 지워야 한다?
int	builtin_unset(t_env *env, char **args)
{
	size_t	i;

	if (args[1] == NULL)
	{
		write(2, "minishell: unset: not enough arguments\n", 39);
		return (EXIT_FAILURE);
	}
	i = 1;
	while (args[i] != NULL)
	{
		env_del(env, args[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

// // execve()로 실행되는 경우
// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_env	*env;

// 	(void) argc;
// 	init_env(&env, envp);
// 	return (builtin_unset(env, argv[1]));
// }
