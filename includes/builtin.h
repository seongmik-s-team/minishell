/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:40:11 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 15:04:09 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "minishell.h"
# include "exit_status.h"
# include "env.h"

int	builtin_main(int argc, char *argv[], char *envp[]);
int	ft_strlen(char *str);
int	builtin_echo(int argc, char *args[]);
int	builtin_cd(int argc, char *args[]);
int	builtin_pwd(void);
int	builtin_export(t_env *env, char *key, char *value);
int	builtin_env(t_env *env);
int	builtin_unset(t_env *env, char *target);
int	builtin_exit(char *args[]);

#endif