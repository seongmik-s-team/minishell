/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:20 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 16:08:52 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// args를 출력하는 테스트 메서드
void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		printf("args[%d]: %s\n", i, args[i]);
		i++;
	}
}

// split을 이용해 커멘드 파싱 & 실행하는 테스트 메서드
void	do_split_command(char *line, t_env **env, t_shell_info *shinfo)
{
	t_command	*cmd;
	char		**args;

	args = ft_split(line, ' ');
	cmd = command_new(args, ft_strdup("stdin"), ft_strdup("stdout"));
	word_expand(cmd, *env);
	if (cmd->args[0] == NULL)
	{
		free_cmd(cmd);
		return ;
	}
	if (cmd->args[0] != NULL && is_builtin(cmd->args[0]))
		do_builtin(shinfo, cmd->args, env, is_builtin(cmd->args[0]));
	else if (cmd->args[0] != NULL && ft_strncmp(cmd->args[0], "<<", 3) == 0)
		heredoc_read(cmd->args[1]);
	else if (cmd->args[0] != NULL)
		execute_command(cmd, env, shinfo);
	free_cmd(cmd);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_shell_info	shell_info;
	char			*line;

	(void) argc;
	(void) argv;
	init_shell(&shell_info, envp);
	while (TRUE)
	{
		line = readline("minishell$ ");
		if (line == NULL)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		add_history(line);
		do_split_command(line, &(shell_info.env), &shell_info);
		free(line);
	}
	exit(SUCCESS);
}
