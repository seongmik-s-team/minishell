/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:27:48 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 22:19:02 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// env_find() 함수는 env에서 key에 해당하는 환경변수를 찾아서 리턴하는 함수이다.
t_env	*env_find(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->pair->key, key, ft_strlen(key) + 1) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

// env_del() 함수는 env에서 key에 해당하는 환경변수를 삭제하는 함수이다.
int	env_del(t_env *env, char *key)
{
	t_env	*target;

	target = env_find(env, key);
	if (target == NULL)
		return (SUCCESS);
	if (target->pair)
	{
		if (target->pair->key)
			free(target->pair->key);
		if (target->pair->value)
			free(target->pair->value);
		free(target->pair);
	}
	if (target->prev)
		target->prev->next = target->next;
	if (target->next)
		target->next->prev = target->prev;
	free(target);
	return (SUCCESS);
}

// env_add() 함수는 env에 key와 value를 가지는 환경변수를 추가하는 함수이다.
int	env_add(t_env **env, char *key, char *value)
{
	t_env	*new;
	t_env	*last;

	if (*env != NULL)
		env_del(*env, key);
	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		return (FAILURE);
	new->pair = (t_pair *)malloc(sizeof(t_pair));
	if (new->pair == NULL)
		return (FAILURE);
	new->pair->key = key;
	new->pair->value = value;
	new->prev = NULL;
	new->next = NULL;
	if (*env == NULL)
		*env = new;
	last = *env;
	while (last->next != NULL)
		last = last->next;
	if (last == new)
		return (SUCCESS);
	last->next = new;
	new->prev = last;
	return (SUCCESS);
}

// env_len() 함수는 env의 길이를 리턴하는 함수이다.
size_t	env_len(t_env *env)
{
	size_t	len;

	len = 0;
	while (env != NULL)
	{
		len++;
		env = env->next;
	}
	return (len);
}

// env_to_envp() 함수는 env를 envp로 변환하는 함수이다.
char	**env_to_envp(t_env *env)
{
	size_t	i;
	char	**envp;

	envp = (char **)malloc(sizeof(char *) * (env_len(env) + 1));
	if (envp == NULL)
		return (NULL);
	i = 0;
	while (env != NULL)
	{
		if (env->pair->value != NULL)
		{
			envp[i] = ft_strjoin(env->pair->key, "=");
			envp[i] = ft_strjoin(envp[i], env->pair->value);
		}
		else
			envp[i] = ft_strdup(env->pair->key);
		i++;
		env = env->next;
	}
	envp[i] = NULL;
	return (envp);
}
