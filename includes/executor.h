/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:47:22 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 14:48:16 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "minishell.h"
# include "builtin.h"
# include "exit_status.h"
# include "env.h"

EXIT_STATUS	execute_command(t_commend *cmd, t_env **env);

#endif
