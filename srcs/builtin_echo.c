/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:43:18 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 16:30:22 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// builtin_echo() 함수는 echo 명령어를 실행하는 함수이다.
int	builtin_echo(int argc, char *args[])
{
	int		i;
	int		n_flag;
	char	**strs;

	i = 0;
	if (ft_strncmp(args[0], "-n", 2) == 0)
	{
		n_flag = 1;
		i++;
	}
	else
		n_flag = 0;
	strs = args;
	while (i < argc)
	{
		if (i != n_flag)
			write(1, " ", 1);
		write(1, strs[i], ft_strlen(strs[i]));
		i++;
	}
	if (n_flag == 0)
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}

// // execve()로 실행되는 경우
// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_env	*env;

// 	init_env(&env, envp);
// 	return (builtin_echo(argc, &argv[1]));
// }
