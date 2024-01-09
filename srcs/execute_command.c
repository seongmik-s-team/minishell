/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:44:57 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 15:59:59 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// return_and_free() 함수는 builtin_nbr을 반환하고 lower_path를 free하는 함수이다.
int	return_and_free(int builtin_nbr, char *lower_path)
{
	free(lower_path);
	return (builtin_nbr);
}

// is_builtin()은 path가 빌트인 함수인지 판별하는 함수이다.
int	is_builtin(char *path)
{
	char	*lower_path;

	lower_path = modifier_tolower(path);
	if (lower_path == NULL)
		sh_error("minishell", strerror(errno));
	if (ft_strncmp(lower_path, "echo", 5) == 0)
		return (return_and_free(BUILTIN_ECHO, lower_path));
	else if (ft_strncmp(lower_path, "cd", 3) == 0)
		return (return_and_free(BUILTIN_CD, lower_path));
	else if (ft_strncmp(lower_path, "pwd", 4) == 0)
		return (return_and_free(BUILTIN_PWD, lower_path));
	else if (ft_strncmp(lower_path, "export", 7) == 0)
		return (return_and_free(BUILTIN_EXPORT, lower_path));
	else if (ft_strncmp(lower_path, "unset", 6) == 0)
		return (return_and_free(BUILTIN_UNSET, lower_path));
	else if (ft_strncmp(lower_path, "env", 4) == 0)
		return (return_and_free(BUILTIN_ENV, lower_path));
	else if (ft_strncmp(lower_path, "exit", 5) == 0)
		return (return_and_free(BUILTIN_EXIT, lower_path));
	return (return_and_free(0, lower_path));
}

// ft_exec() 함수는 execve()를 실행하는 함수이다.
int	ft_exec(t_command *cmd, t_env *env)
{
	char	**envp;
	char	**paths;
	char	*path;
	t_env	*path_env;
	size_t	i;

	envp = env_to_envp(env);
	execve(cmd->args[0], cmd->args, envp);
	path_env = env_find(env, "PATH");
	if (path_env == NULL || path_env->pair->value == NULL)
		return (FAILURE);
	paths = ft_split(path_env->pair->value, ':');
	i = 0;
	while (paths[i])
	{
		path = modifier_trpjoin(paths[i], "/", cmd->args[0]);
		execve(path, cmd->args, envp);
		if (paths[i] != NULL)
			free(paths[i]);
		if (path != NULL)
			free(path);
		i++;
	}
	free(paths);
	return (SUCCESS);
}

// ft_free_strs() 함수는 char** 자료형 strs를 free하는 함수이다.
void	ft_free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

// executor_command() 함수는 명령어를 실행하는 함수이다.
int	execute_command(t_command *cmd, t_env **env, t_shell_info *shinfo)
{
	int		pid;
	int		ret;
	t_env	*copied_env;

	if (is_builtin(cmd->args[0]))
		return (do_builtin(shinfo, cmd->args, env, is_builtin(cmd->args[0])));
	copied_env = env_copy(*env);
	pid = fork();
	if (pid == 0)
	{
		free_env(*env);
		ret = ft_exec(cmd, copied_env);
		if (ret == FAILURE)
			sh_error(cmd->args[0], strerror(errno));
		else
			sh_error(cmd->args[0], "command not found");
	}
	else if (pid == -1)
		sh_error(cmd->args[0], strerror(errno));
	else
		wait(&pid);
	free_env(copied_env);
	return (SUCCESS);
}
