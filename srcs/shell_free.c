/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:01:32 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 15:37:33 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// free_args() 함수는 args를 free하는 함수이다.
void	free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

// free_redirects() 함수는 redirects를 free하는 함수이다.
void	free_redirections(t_redirect **redirects)
{
	size_t	i;

	i = 0;
	while (redirects[i])
	{
		if (redirects[i]->delimiter)
			free(redirects[i]->delimiter);
		if (redirects[i]->file)
			free(redirects[i]->file);
		free(redirects[i]);
		i++;
	}
	free(redirects);
}

// free_cmd() 함수는 cmd를 free하는 함수이다.
void	free_cmd(t_command *cmd)
{
	free_args(cmd->args);
	free_redirections(cmd->redirects);
	if (cmd->left)
		free_cmd(cmd->left);
	if (cmd->right)
		free_cmd(cmd->right);
	free(cmd);
}
