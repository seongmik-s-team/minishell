/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:20 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/06 19:13:38 by seongmik         ###   ########.fr       */
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
void	do_split_command(char *line, t_env *env)
{
	t_command	*cmd;
	char		**args;

	args = ft_split(line, ' ');
	print_args(args);
	if (args[0] != NULL && is_builtin(args[0]))
		do_builtin(args, env, is_builtin(args[0]));
	else if (args[0] != NULL && ft_strncmp(args[0], "<<", 3) == 0)
		heredoc_read(args[1]);
	else if (args[0] != NULL)
	{
		cmd = command_new(args[0], args, "stdin", "stdout");
		execute_command(cmd, env);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env		*env;
	char		*line;

	(void) argc;
	(void) argv;
	init_sig_setting();
	init_env(&env, envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		add_history(line);
		do_split_command(line, env);
		free(line);
	}
	exit(0);
}
