/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:33:18 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 15:41:08 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_and_exit(int exit_code)
{
	write(2, "exit\n", 5);
	exit(exit_code);
}

// builtin_exit() 함수는 exit 명령어를 실행하는 함수이다.
int	builtin_exit(char *args[])
{
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	if (args[1] == NULL)
		print_and_exit(exit_code);
	if (args[1] != NULL && judge_isalldigit(args[1]) == 0)
	{
		write(2, "minishell: exit: ", 17);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": numeric argument required\n", 28);
		return (EXIT_FAILURE);
	}
	if (args[1] != NULL && args[2] != NULL)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		return (EXIT_FAILURE);
	}
	if (args[1] != NULL)
		exit_code = ft_atoi(args[1]);
	print_and_exit(exit_code);
	return (EXIT_SUCCESS);
}

// // execve()로 실행되는 경우
// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_env	*env;

// 	(void) argc;
// 	init_env(&env, envp);
// 	return (builtin_exit(&argv[1]));
// }
