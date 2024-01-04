/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:27:48 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 14:08:38 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*temp;

	len = 0;
	while (*(s1 + len))
		len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	i = 0 - 1;
	while (++i < len)
		*(temp + i) = *(s1 + i);
	*(temp + i) = '\0';
	return (temp);
}

// env_find() 함수는 env에서 key에 해당하는 환경변수를 찾아서 리턴하는 함수이다.
t_env	*env_find(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_strcmp(env->pair->key, key) == 0)
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
