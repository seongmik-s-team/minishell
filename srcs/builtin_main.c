/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:32:39 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 15:03:51 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_main(int argc, char *argv[], char *envp[])
{
	t_env	*env;

	builtin_echo(argc - 1, &argv[1]);
	builtin_pwd();
	builtin_cd(argc, argv);
	builtin_pwd();
	init_env(&env, envp);
	builtin_env(env);
	printf("-------------------------\n");
	builtin_export(env, NULL, NULL);
	printf("-------------------------\n");
	builtin_export(env, ft_strdup("a"), NULL);
	builtin_export(env, ft_strdup("b"), ft_strdup("c"));
	builtin_export(env, ft_strdup("a"), ft_strdup("d"));
	builtin_unset(env, ft_strdup("a"));
	printf("-------------------------\n");
	builtin_export(env, NULL, NULL);
	printf("-------------------------\n");
	builtin_exit(&argv[2]);
	return (0);
}
