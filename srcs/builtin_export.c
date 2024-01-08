/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:29:50 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/07 16:29:47 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// export_print() 함수는 export 명령어를 실행할 때 환경변수를 출력하는 함수이다.
// value가 NULL이면 key만 출력하고, value가 NULL이 아니면 key=value 형태로 출력한다.
void	export_print(t_env *env)
{
	while (env)
	{
		write(1, "declare -x ", 11);
		write(1, env->pair->key, ft_strlen(env->pair->key));
		if (env->pair->value != NULL)
		{
			write(1, "=", 1);
			write(1, "\"", 1);
			write(1, env->pair->value, ft_strlen(env->pair->value));
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		env = env->next;
	}
}

// in_a_row() 함수는 str에 공백이 있는지 확인하는 함수이다.
int	in_a_row(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

// builtin_export() 함수는 export 명령어를 실행하는 함수이다.
// key와 value가 모두 NULL이면 환경변수를 출력하고, NULL이 아니면 환경변수를 추가한다.
int	builtin_export(char *args[], t_env *env)
{
	size_t	i;
	t_pair	pair;

	if (args == NULL)
		return (FAILURE);
	i = 1;
	if (args[1] == NULL)
		export_print(env);
	while (args[i])
	{
		pair = make_pair(args[i]);
		if (in_a_row(pair.key) == FAILURE)
		{
			write(2, "minishell: export: `", 20);
			write(2, pair.key, ft_strlen(pair.key));
			write(2, "': not a valid identifier\n", 26);
			return (FAILURE);
		}
		else
			env_add(&env, pair.key, pair.value);
		args++;
	}	
	return (SUCCESS);
}

// // execve()로 실행되는 경우
// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_env	*env;

// 	(void) argc;
// 	init_env(&env, envp);
// 	return (builtin_export(&argv[1], env));
// }
