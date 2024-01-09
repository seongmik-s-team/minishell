/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:39:07 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 14:52:20 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// command_new() 함수는 새로운 command를 생성하는 함수이다.
t_command	*command_new(char **args, char *infile, char *outfile)
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (cmd == NULL)
		return (FAULURE_NULL);
	cmd->args = args;
	cmd->redirects = (t_redirect **)malloc(sizeof(t_redirect *) * 3);
	if (cmd->redirects == NULL)
		return (FAULURE_NULL);
	cmd->redirects[0] = (t_redirect *)malloc(sizeof(t_redirect));
	cmd->redirects[1] = (t_redirect *)malloc(sizeof(t_redirect));
	if (cmd->redirects[0] == NULL || cmd->redirects[1] == NULL)
		return (FAULURE_NULL);
	cmd->redirects[2] = NULL;
	cmd->redirects[0]->file = infile;
	cmd->redirects[0]->delimiter = NULL;
	cmd->redirects[0]->type = REDIRECT_IN;
	cmd->redirects[1]->file = outfile;
	cmd->redirects[1]->delimiter = NULL;
	cmd->redirects[1]->type = REDIRECT_OUT;
	cmd->left = NULL;
	cmd->right = NULL;
	cmd->symbol = COMMAND;
	return (cmd);
}
