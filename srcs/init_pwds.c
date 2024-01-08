/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pwds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:35:52 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 17:56:19 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// init_oldpwd() 함수는 env에 기본 OLDPWD를 추가하는 함수이다.
int	init_oldpwd(t_env **env, char **sholdpwd)
{
	t_env	*oldpwd;

	oldpwd = env_find(*env, "OLDPWD");
	if (oldpwd == NULL)
	{
		env_add(env, ft_strdup("OLDPWD"), NULL);
		*sholdpwd = NULL;
	}
	else
		*sholdpwd = ft_strdup(oldpwd->pair->value);
	return (SUCCESS);
}

// init_pwd() 함수는 env에 기본 PWD를 추가하는 함수이다.
int	init_pwd(t_env **env, char **shpwd)
{
	t_env	*pwd;
	char	*cwd;

	pwd = env_find(*env, "PWD");
	if (pwd == NULL)
	{
		cwd = getcwd(NULL, 0);
		if (cwd == NULL)
			return (FAILURE);
		env_add(env, ft_strdup("PWD"), cwd);
		cwd = getcwd(NULL, 0);
		if (cwd == NULL)
			return (FAILURE);
		*shpwd = ft_strdup(cwd);
	}
	else
		*shpwd = ft_strdup(pwd->pair->value);
	return (SUCCESS);
}

// init_pwds() 함수는 env에 기본 PWD와 OLDPWD를 추가하는 함수이다.
int	init_pwds(t_env **env, char **shpwd, char **sholdpwd)
{
	if (init_pwd(env, shpwd) == FAILURE)
		return (FAILURE);
	if (init_oldpwd(env, sholdpwd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
