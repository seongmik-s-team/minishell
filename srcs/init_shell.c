/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:14:03 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 13:24:38 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
			return (FAILURE);
		env_add(env, key, value);
		i++;
	}
	return (SUCCESS);
}

// init_sig_setting() 함수는 signal을 설정하는 함수이다.
int	init_sig_setting(void)
{
	if (set_sigquit())
		return (FAILURE);
	if (set_sigint())
		return (FAILURE);
	return (SUCCESS);
}

// init_shell() 함수는 minishell을 초기화하는 함수이다.
int	init_shell(t_shell_info *shinfo, char *envp[])
{
	shinfo->heredoc_idx = 0;
	init_sig_setting();
	init_env(&(shinfo->env), envp);
	if (init_pwds(&(shinfo->env), &(shinfo->pwd), &(shinfo->oldpwd)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
