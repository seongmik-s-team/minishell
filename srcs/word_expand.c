/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:41:56 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 15:15:19 by seongmik         ###   ########.fr       */
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
	while (str[j] != '\0' && str[j] != '$' && judge_isspace(str[j]) != 1)
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
	while (str[i] != '\0' && str[i] != '$' && judge_isspace(str[i]) == 0)
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
	char	*expanded;
	char	*ret;
	t_env	*exist_env;

	if (str == NULL)
		return (NULL);
	while (TRUE)
	{
		dollar_idx = find_word(str);
		if (dollar_idx == -1)
			return (str);
		word = to_word(str, dollar_idx);
		exist_env = env_find(env, word);
		if (exist_env != NULL && exist_env->pair->value != NULL)
			expanded = exist_env->pair->value;
		else
			expanded = "";
		ret = modifier_replace(str, expanded, dollar_idx, ft_strlen(word) + 1);
		free(word);
		free(str);
		str = ret;
	}
	return (str);
}

// word_expand() 함수는 command 구조체에 저장된 args를 환경변수로 워드확장하는 함수이다.
void	word_expand(t_command *cmd, t_env *env)
{
	int		i;
	size_t	len;

	i = 0;
	len = get_strslen(cmd->args);
	while (cmd->args[i] != NULL)
	{
		cmd->args[i] = expand_by_env(cmd->args[i], env);
		i++;
	}
	args_pull(cmd->args, len);
}
