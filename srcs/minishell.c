/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:20 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 22:07:05 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*line;
	char	**args;

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
		args = ft_split(line, ' ');
		if (args[0] != NULL && is_builtin(args[0]))
			do_builtin(args, env, is_builtin(args[0]));
		free(line);
	}
	exit(0);
}
