/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:44:57 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 13:24:13 by seongmik         ###   ########.fr       */
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
	if (ft_strncmp(path, "echo", 5) == 0)
		return (return_and_free(BUILTIN_ECHO, lower_path));
	else if (ft_strncmp(path, "cd", 3) == 0)
		return (return_and_free(BUILTIN_CD, lower_path));
	else if (ft_strncmp(path, "pwd", 4) == 0)
		return (return_and_free(BUILTIN_PWD, lower_path));
	else if (ft_strncmp(path, "export", 7) == 0)
		return (return_and_free(BUILTIN_EXPORT, lower_path));
	else if (ft_strncmp(path, "unset", 6) == 0)
		return (return_and_free(BUILTIN_UNSET, lower_path));
	else if (ft_strncmp(path, "env", 4) == 0)
		return (return_and_free(BUILTIN_ENV, lower_path));
	else if (ft_strncmp(path, "exit", 5) == 0)
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
	execve(cmd->path, cmd->args, envp);
	path_env = env_find(env, "PATH");
	if (path_env == NULL)
		return (FAILURE);
	path = path_env->pair->value;
	if (path == NULL)
		return (FAILURE);
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd->path);
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
int	execute_command(t_shell_info *shinfo, t_command *cmd, t_env **env)
{
	int		pid;
	int		ret;

	// word_expand(cmd, env);
	if (is_builtin(cmd->path))
		return (do_builtin(shinfo, cmd->args, env, is_builtin(cmd->path)));
	pid = fork();
	if (pid == 0)
	{
		ret = ft_exec(cmd, *env);
		free_env(*env);
		if (ret == FAILURE)
			sh_error(cmd->args[0], strerror(errno));
		else
			sh_error(cmd->args[0], "command not found");
	}
	else if (pid == -1)
		sh_error(cmd->args[0], strerror(errno));
	else
		wait(&pid);
	return (SUCCESS);
}
