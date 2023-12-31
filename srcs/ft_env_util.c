/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:07:59 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 15:21:28 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// env_copy() 함수는 env를 복사하는 함수이다.
t_env	*env_copy(t_env *origin)
{
	t_env	*copy;
	char	*copied_key;
	char	*copied_value;

	copy = NULL;
	while (origin != NULL)
	{
		copied_key = ft_strdup(origin->pair->key);
		if (origin->pair->value != NULL)
			copied_value = ft_strdup(origin->pair->value);
		else
			copied_value = NULL;
		env_add(&copy, copied_key, copied_value);
		origin = origin->next;
	}
	return (copy);
}

// free_env() 함수는 env를 free하는 함수이다.
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

// env_add() 함수는 key와 value를 가지는 pair를 생성하는 함수이다.
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
