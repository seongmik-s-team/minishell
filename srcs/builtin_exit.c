/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:33:18 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 16:37:09 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// ft_atoi() 함수는 문자열을 정수로 변환하는 함수이다.
int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result * sign > INT_MAX)
			return (-1);
		if (result * sign < INT_MIN)
			return (0);
	}
	return (result * sign);
}

// builtin_exit() 함수는 exit 명령어를 실행하는 함수이다.
int	builtin_exit(char *args[])
{
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	if (args[0] == NULL)
		exit(exit_code);
	if (args[0] != NULL && is_all_digit(args[0]) == 0)
	{
		write(2, "minishell: exit: ", 17);
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": numeric argument required\n", 28);
		return (EXIT_FAILURE);
	}
	if (args[0] != NULL && args[1] != NULL)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		return (EXIT_FAILURE);
	}
	if (args[0] != NULL)
		exit_code = ft_atoi(args[0]);
	exit(exit_code);
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
