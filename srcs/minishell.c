/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:20 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 14:07:49 by seongmik         ###   ########.fr       */
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

// 빈 문자열인지 확인하는 메서드
int	is_blank(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// split을 이용해 커멘드 파싱 & 실행하는 테스트 메서드
void	do_split_command(char *line, t_env *env, int *heredoc_idx)
{
	t_command	*cmd;
	char		**args;

	args = ft_split(line, ' ');
	if (args[0] == NULL)
		return ;
	cmd = command_new(ft_strdup(args[0]), args, "stdin", "stdout");
	// print_args(cmd->args);
	word_expand(cmd, env);
	// print_args(cmd->args);
	if (cmd->path != NULL && is_builtin(cmd->path))
		do_builtin(cmd->args, env, is_builtin(cmd->path));
	else if (args[0] != NULL && ft_strncmp(args[0], "<<", 3) == 0)
		heredoc_read(args[1], heredoc_idx);
	else if (args[0] != NULL)
		execute_command(cmd, env);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_shell_info	shell_info;
	char			*line;

	(void) argc;
	(void) argv;
	shell_info.heredoc_idx = 0;
	init_sig_setting();
	init_env(&(shell_info.env), envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		add_history(line);
		do_split_command(line, shell_info.env, &(shell_info.heredoc_idx));
		free(line);
	}
	exit(0);
}
