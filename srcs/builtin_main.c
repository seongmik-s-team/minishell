/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:32:39 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/03 21:43:19 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

EXIT_STATUS	builtin_main(int argc, char *argv[], char *envp[])
{
	t_env	*env;

	builtin_echo(argc - 1, &argv[1]);
	builtin_pwd();
	builtin_cd(argc, argv);
	builtin_pwd();
	init_env(&env, envp);
	builtin_env(env);
	return (0);
}
