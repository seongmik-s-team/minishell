/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:07:59 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/06 20:40:31 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*env_copy(t_env *origin)
{
	t_env	*copy;
	char	*copy_key;
	char	*copy_value;

	copy = NULL;
	while (origin != NULL)
	{
		copy_key = ft_strdup(origin->pair->key);
		if (origin->pair->value != NULL)
			copy_value = ft_strdup(origin->pair->value);
		else
			copy_value = NULL;
		env_add(&copy, copy_key, copy_value);
		origin = origin->next;
	}
	return (copy);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env != NULL)
	{
		tmp = env;
		env = env->next;
		if (tmp->pair)
		{
			if (tmp->pair->key)
				free(tmp->pair->key);
			if (tmp->pair->value)
				free(tmp->pair->value);
			free(tmp->pair);
			tmp->pair = NULL;
		}
		free(tmp);
	}
}

t_pair	make_pair(char *str)
{
	t_pair	pair;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	pair.key = ft_substr(str, 0, i);
	if (str[i] == '=')
		pair.value = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	else
		pair.value = NULL;
	return (pair);
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
		key = ft_substr(envp[i], 0, idx);
		value = ft_substr(envp[i], idx + 1, ft_strlen(envp[i]) - idx - 1);
		if (key == NULL || value == NULL)
			return (EXIT_FAILURE);
		env_add(env, key, value);
		i++;
	}
	return (EXIT_SUCCESS);
}
