/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:43:18 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 15:41:00 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	echo_option_n(char *args[])
{
	int	n_flag;

	if (ft_strncmp(args[1], "-n", 3) == 0)
		n_flag = 1;
	else
		n_flag = 0;
	return (n_flag);
}

// builtin_echo() 함수는 echo 명령어를 실행하는 함수이다.
int	builtin_echo(char *args[])
{
	int	i;
	int	n_flag;

	i = 1;
	if (args[1] == NULL)
	{
		write(1, "\n", 1);
		return (EXIT_SUCCESS);
	}
	n_flag = echo_option_n(args);
	i = i + n_flag;
	while (args[i])
	{
		if (i != 1 + n_flag)
			write(1, " ", 1);
		write(1, args[i], ft_strlen(args[i]));
		i++;
	}
	if (n_flag == 0)
		write(2, "\n", 1);
	return (EXIT_SUCCESS);
}

// // execve()로 실행되는 경우
// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_env	*env;

// 	init_env(&env, envp);
// 	return (builtin_echo(argc, &argv[1]));
// }
