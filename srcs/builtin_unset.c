/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:27:58 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 14:32:37 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// builtin_unset() 함수는 unset 명령어를 실행하는 함수이다.
EXIT_STATUS	builtin_unset(t_env *env, char *target)
{
	env_del(env, target);
	return (EXIT_SUCCESS);
}
