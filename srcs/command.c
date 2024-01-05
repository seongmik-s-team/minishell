/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:39:07 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 17:30:30 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// command_new() 함수는 새로운 command를 생성하는 함수이다.
t_command	*command_new(char *path, char **args, char *redirect_in, \
						char *redirect_out)
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (cmd == NULL)
		return (NULL);
	cmd->path = path;
	cmd->args = args;
	cmd->redirect_in = redirect_in;
	cmd->redirect_out = redirect_out;
	cmd->type = 0;
	cmd->next = NULL;
	return (cmd);
}
