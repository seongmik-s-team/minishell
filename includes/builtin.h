/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:40:11 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/03 19:35:14 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "minishell.h"
# include "exit_status.h"

EXIT_STATUS	builtin_main(int argc, char *argv[], char *envp[]);
int			ft_strlen(char *str);
EXIT_STATUS	builtin_echo(int argc, char *args[]);
EXIT_STATUS	builtin_cd(int argc, char *args[]);
EXIT_STATUS	builtin_pwd(void);

#endif