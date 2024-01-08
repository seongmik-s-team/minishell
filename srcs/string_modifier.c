/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:35:54 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 15:43:57 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// modifier_tolower() 함수는 str을 소문자 문자열로 바꾸는 함수이다.
char	*modifier_tolower(char *str)
{
	size_t	i;
	char	*ret;

	ret = ft_strdup(str);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (ret[i])
	{
		ret[i] = ft_tolower(ret[i]);
		i++;
	}
	return (ret);
}
