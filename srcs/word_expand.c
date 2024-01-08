/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:41:56 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 14:25:27 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// find_word() 함수는 str에서 환경변수의 시작 인덱스를 찾는 함수이다.
int	find_word(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0' && str[i] != '$')
		i++;
	if (str[i] == '\0')
		return (-1);
	j = i + 1;
	while (str[j] != '\0' && str[j] != '$' && ft_isspace(str[j]) != 1)
		j++;
	if (i + 1 == j || ft_strlen(str) == 0)
		return (-1);
	return (i);
}

// to_word() 함수는 str에서 환경변수를 찾아내는 함수이다.
char	*to_word(char *str, int dollar_idx)
{
	int		i;
	int		size;

	i = dollar_idx + 1;
	size = 0;
	while (str[i] != '\0' && str[i] != '$' && ft_isspace(str[i]) == 0)
	{
		i++;
		size++;
	}
	if (dollar_idx + 1 == i)
		return (NULL);
	return (ft_substr(str, dollar_idx + 1, size));
}

// expand_by_env() 함수는 str에서 환경변수를 찾아내서 환경변수의 value로 바꾸는 함수이다.
char	*expand_by_env(char *str, t_env *env)
{
	int		dollar_idx;
	char	*word;
	char	*expanded_word;
	char	*rear_str;
	t_env	*tmp;

	while (1)
	{
		dollar_idx = find_word(str);
		if (dollar_idx == -1)
			return (str);
		word = to_word(str, dollar_idx);
		tmp = env_find(env, word);
		if (tmp == NULL)
			return (str);
		expanded_word = ft_substr(str, 0, dollar_idx);
		if (tmp->pair->value != NULL)
			expanded_word = ft_strjoin(expanded_word , tmp->pair->value);
		else
			expanded_word = ft_strjoin(expanded_word , "");
		rear_str = ft_substr(str, dollar_idx + ft_strlen(word) + 1, ft_strlen(str) - dollar_idx - ft_strlen(word));
		expanded_word = ft_strjoin(expanded_word, rear_str);
		str = expanded_word;
	}
	return (str);
}

// word_expand() 함수는 command 구조체에 저장된 path와 args를 환경변수로 워드확장하는 함수이다.
void	word_expand(t_command *cmd, t_env *env)
{
	int		i;

	i = 0;
	cmd->path = expand_by_env(cmd->path, env);
	while (cmd->args[i] != NULL)
	{
		cmd->args[i] = expand_by_env(cmd->args[i], env);
		i++;
	}
}
