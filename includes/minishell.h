/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:45:55 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 14:46:44 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "builtin.h"
# include "exit_status.h"
# include "env.h"
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_commend
{
	char	*cmd;
	char	*option;
	char	**args;
	char	*redirect_in;
	char	*redirect_out;
	int		type;
}				t_commend;

#endif