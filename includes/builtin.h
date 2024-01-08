/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:40:11 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 17:53:50 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/* ***************************** custom headers ***************************** */
# include "minishell.h"
# include "env.h"

/* ******************************** defines ********************************* */
# define BUILTIN_ECHO	1
# define BUILTIN_CD		2
# define BUILTIN_PWD	3
# define BUILTIN_EXPORT	4
# define BUILTIN_UNSET	5
# define BUILTIN_ENV	6
# define BUILTIN_EXIT	7

/* ********************************* bulitin ******************************** */
int		builtin_echo(char *args[]);
int		builtin_export(char *args[], t_env **env);
int		builtin_env(t_env *env, char *args[]);
int		builtin_unset(t_env **env, char **args);
int		builtin_exit(char *args[]);

#endif