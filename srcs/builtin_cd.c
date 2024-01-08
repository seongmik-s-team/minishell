/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:35 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 14:37:53 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// builtin_cd() 함수는 cd 명령어를 실행하는 함수이다.
int	builtin_cd(char *args[])
{
	char	*path;

	if (args[1] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (EXIT_FAILURE);
		}
	}
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// // execve()로 실행되는 경우
// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_env	*env;

// 	init_env(&env, envp);
// 	return (builtin_cd(argc, argv));
// }
