/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:32:39 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/03 19:35:27 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

EXIT_STATUS	builtin_main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**env;

	i = 0;
	env = envp;
	(void)env;
	builtin_echo(argc - 1, &argv[1]);
	builtin_pwd();
	builtin_cd(argc, argv);
	builtin_pwd();
	return (0);
}
