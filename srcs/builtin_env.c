/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:03:24 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/03 21:41:37 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin.h"

size_t	find_equal(const char *env_str)
{
	size_t	idx;

	idx = 0;
	while (env_str[idx] != '=' && env_str[idx] != '\0')
		idx++;
	return (idx);
}

EXIT_STATUS	init_env(t_env **env, char *envp[])
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
	builtin_env(*env);
	return (EXIT_SUCCESS);
}

EXIT_STATUS	builtin_env(t_env *env)
{
	while (env != NULL)
	{
		write(1, env->pair->key, ft_strlen(env->pair->key));
		write(1, "=", 1);
		write(1, env->pair->value, ft_strlen(env->pair->value));
		write(1, "\n", 1);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
