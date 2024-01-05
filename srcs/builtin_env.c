/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:03:24 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 17:46:02 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// find_equal() 함수는 envp로 들어온 초기 환경변수에서 '='의 위치를 찾는 함수이다.
size_t	find_equal(const char *env_str)
{
	size_t	idx;

	idx = 0;
	while (env_str[idx] != '=' && env_str[idx] != '\0')
		idx++;
	return (idx);
}

// init_env() 함수는 envp로 들어온 초기 환경변수를 env에 저장하는 함수이다.
int	init_env(t_env **env, char *envp[])
{
	size_t	i;
	size_t	idx;
	char	*key;
	char	*value;

	*env = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		idx = find_equal(envp[i]);
		envp[i][idx] = '\0';
		key = ft_strdup(envp[i]);
		value = ft_strdup(&envp[i][idx + 1]);
		if (key == NULL || value == NULL)
			return (EXIT_FAILURE);
		env_add(env, key, value);
		i++;
	}
	return (EXIT_SUCCESS);
}

// builtin_env() 함수는 env 명령어를 실행하는 함수이다.
// 인자가 없으면 환경변수를 모두 출력하고, 인자가 있으면 인자로 들어온 환경변수만 출력한다.
// value가 NULL이면 출력하지 않는다.
// env는 변경된 환경에서 command를 실행시켜야 하기 때문에 command가 구현되어야지 사용할 수 있다.
// TODO: command 구현
int	builtin_env(t_env *env, char *args[])
{
	(void) args;
	while (env != NULL)
	{
		if (env->pair->value != NULL)
		{
			write(1, env->pair->key, ft_strlen(env->pair->key));
			write(1, "=", 1);
			write(1, env->pair->value, ft_strlen(env->pair->value));
		}
		write(1, "\n", 1);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}

// // execve()로 실행되는 경우
// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_env	*env;

// 	(void) argc;
// 	init_env(&env, envp);
// 	return (builtin_env(env, &argv[1]));
// }
