/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:35 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 13:23:11 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// ft_getcwd() 함수는 현재 작업 디렉토리를 가져오는 함수이다.
// getcwd()가 실패한다면 쉘 내부의 pwd를 가져온다.
char	*ft_getcwd(t_shell_info *shinfo)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL && shinfo->pwd != NULL)
		return (ft_strdup(shinfo->pwd));
	if (cwd == NULL && shinfo->pwd == NULL)
		return (NULL);
	return (cwd);
}

// set_pwd() 함수는 env와 shinfo의 pwd를 설정하는 함수이다.
void	set_pwd(t_shell_info *shinfo, t_env **env, char *newpwd)
{
	t_env	*envpwd;

	envpwd = env_find(*env, "PWD");
	if (envpwd == NULL)
		return ;
	if (envpwd->pair != NULL && envpwd->pair->value != NULL)
		free(envpwd->pair->value);
	envpwd->pair->value = newpwd;
	if (shinfo->pwd != NULL)
		free(shinfo->pwd);
	shinfo->pwd = ft_strdup(newpwd);
}

// set_oldpwd() 함수는 env와 shinfo의 oldpwd를 설정하는 함수이다.
void	set_oldpwd(t_shell_info *shinfo, t_env **env, char *newpwd)
{
	t_env	*envpwd;

	envpwd = env_find(*env, "OLDPWD");
	if (envpwd == NULL)
		return ;
	if (envpwd->pair != NULL && envpwd->pair->value != NULL)
		free(envpwd->pair->value);
	envpwd->pair->value = newpwd;
	if (shinfo->oldpwd != NULL)
		free(shinfo->oldpwd);
	shinfo->oldpwd = ft_strdup(newpwd);
}

// do_cd() 함수는 cd 명령어를 실행하는 함수이다.
// oldcwd와 cwd를 세팅한다.
int	do_cd(t_shell_info *shinfo, char *path, t_env **env)
{
	char	*oldcwd;
	char	*cwd;

	oldcwd = ft_getcwd(shinfo);
	if (oldcwd == NULL)
		return (FAILURE);
	set_oldpwd(shinfo, env, oldcwd);
	if (chdir(path) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (FAILURE);
	}
	cwd = ft_getcwd(shinfo);
	if (cwd == NULL)
		return (FAILURE);
	set_pwd(shinfo, env, cwd);
	return (SUCCESS);
}

// builtin_cd() 함수는 cd 명령어를 실행하는 함수이다.
int	builtin_cd(char *args[], t_env **env, t_shell_info *shinfo)
{
	char	*path;
	t_env	*home;

	if (args[1] == NULL || ft_strncmp(args[1], "$HOME", 6) == 0)
	{
		home = env_find(*env, "HOME");
		if (home == NULL)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (FAILURE);
		}
		path = home->pair->value;
	}
	else
		path = args[1];
	if (do_cd(shinfo, path, env) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

// // execve()로 실행되는 경우
// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_env	*env;

// 	init_env(&env, envp);
// 	return (builtin_cd(argc, argv));
// }
