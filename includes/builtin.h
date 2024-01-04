/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:40:11 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 14:37:23 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "minishell.h"
# include "exit_status.h"
# include "env.h"

EXIT_STATUS	builtin_main(int argc, char *argv[], char *envp[]);
int			ft_strlen(char *str);
EXIT_STATUS	builtin_echo(int argc, char *args[]);
EXIT_STATUS	builtin_cd(int argc, char *args[]);
EXIT_STATUS	builtin_pwd(void);
EXIT_STATUS	builtin_export(t_env *env, char *key, char *value);
EXIT_STATUS	builtin_env(t_env *env);
EXIT_STATUS	builtin_unset(t_env *env, char *target);
EXIT_STATUS	builtin_exit(char *args[]);

#endif