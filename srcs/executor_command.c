/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:44:57 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 17:28:59 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// is_builtin()은 path가 빌트인 함수인지 판별하는 함수이다.
int	is_builtin(char *path)
{
	if (ft_strncmp(path, "echo", 4) == 0)
		return (BUILTIN_ECHO);
	else if (ft_strncmp(path, "cd", 2) == 0)
		return (BUILTIN_CD);
	else if (ft_strncmp(path, "pwd", 3) == 0)
		return (BUILTIN_PWD);
	else if (ft_strncmp(path, "export", 6) == 0)
		return (BUILTIN_EXPORT);
	else if (ft_strncmp(path, "unset", 5) == 0)
		return (BUILTIN_UNSET);
	else if (ft_strncmp(path, "env", 3) == 0)
		return (BUILTIN_ENV);
	else if (ft_strncmp(path, "exit", 4) == 0)
		return (BUILTIN_EXIT);
	return (0);
}

// ft_exec() 함수는 execve()를 실행하는 함수이다.
int	ft_exec(t_command *cmd, t_env *env)
{
	char	**envp;
	char	**paths;
	char	*path;

	envp = env_to_envp(env);
	execve(cmd->path, cmd->args, envp);
	path = env_find(env, "PATH")->pair->value;
	if (path == NULL)
		return (EXIT_FAILURE);
	paths = ft_split(path, ':');
	free(path);
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd->path);
		execve(path, cmd->args, envp);
		free(*paths);
		free(path);
		paths++;
	}
	free(paths);
	return (EXIT_SUCCESS);
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
int	execute_command(t_command *cmd, t_env *env)
{
	int		pid;

	if (is_builtin(cmd->path))
		return (do_builtin(cmd, env, is_builtin(cmd->path)));
	pid = fork();
	if (pid == 0)
	{
		ft_exec(cmd, env);
		perror("execve");
		exit(errno);
	}
	else if (pid == -1)
	{
		write(2, "minishell: ", 11);
		write(2, cmd->args[0], ft_strlen(cmd->args[0]));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
	else
		wait(&pid);
	env_add(&env, "?", ft_itoa(pid));
	return (EXIT_SUCCESS);
}
