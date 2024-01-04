/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:27:18 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 13:48:15 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "minishell.h"
# include <stddef.h>

typedef struct s_pair
{
	char	*key;
	char	*value;
}				t_pair;

typedef struct s_env
{
	t_pair			*pair;
	struct s_env	*prev;
	struct s_env	*next;
}				t_env;

int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s1);
t_env		*env_find(t_env *env, char *key);
int			env_del(t_env *env, char *key);
int			env_add(t_env **env, char *key, char *value);
size_t		find_equal(const char *env_str);
EXIT_STATUS	init_env(t_env **env, char *envp[]);

#endif