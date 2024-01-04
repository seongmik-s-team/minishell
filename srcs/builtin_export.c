/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:29:50 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 14:21:06 by seongmik         ###   ########.fr       */
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
			write(1, env->pair->value, ft_strlen(env->pair->value));
		}
		write(1, "\n", 1);
		env = env->next;
	}
}

// builtin_export() 함수는 export 명령어를 실행하는 함수이다.
// key와 value가 모두 NULL이면 환경변수를 출력하고, NULL이 아니면 환경변수를 추가한다.
EXIT_STATUS	builtin_export(t_env *env, char *key, char *value)
{
	if (key == NULL && value == NULL)
	{
		export_print(env);
		return (EXIT_SUCCESS);
	}
	if (key == NULL)
		return (EXIT_FAILURE);
	if (value == NULL)
		return (env_add(&env, key, NULL));
	return (env_add(&env, key, value));
}
