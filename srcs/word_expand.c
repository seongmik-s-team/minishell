/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:41:56 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/06 19:44:49 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*dollar_sign_expand(char *str, t_env *env)
{
	char	*tmp;

	if (str[0] == '$')
	{
		tmp = ft_strdup(str + 1);
		free(str);
		str = ft_strdup(expand_by_env(tmp, env));
		free(tmp);
	}
	return (str);
}

char	*expand_by_env(char *str, t_env *env)
{
	t_env	*tmp;
	char	*key;
	char	*value;
	char	*tmp_str;
	char	*tmp_str2;

	tmp = env;
	while (tmp != NULL)
	{
		key = ft_strjoin(tmp->pair->key, "=");
		if (ft_strncmp(str, key, ft_strlen(key)) == 0)
		{
			value = ft_strdup(tmp->pair->value);
			tmp_str = ft_strjoin(value, str + ft_strlen(key));
			tmp_str2 = ft_strdup(tmp_str);
			free(tmp_str);
			free(key);
			free(value);
			return (tmp_str2);
		}
		free(key);
		tmp = tmp->next;
	}
	return (NULL);

}

void	word_expand(t_command *cmd, t_env *env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (cmd->args[i] != NULL)
	{
		tmp = cmd->args[i];
		cmd->args[i] = ft_strdup(dollar_sign_expand(cmd->args[i], env));
		free(tmp);
		i++;
	}
}