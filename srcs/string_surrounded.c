/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_surrounded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:19:16 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 16:53:16 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// surrounded_singlequote() 함수는 str이 '로 둘러쌓여 있는지 확인하는 함수이다.
int	surrounded_singlequote(char *str)
{
	size_t	i;

	if (str[0] != '\'')
		return (FALSE);
	i = 1;
	while (str[i] != '\0')
		i++;
	if (i <= 1)
		return (FALSE);
	if (str[i - 1] != '\'')
		return (FALSE);
	return (TRUE);
}

// surrounded_doublequote() 함수는 str이 "로 둘러쌓여 있는지 확인하는 함수이다.
int	surrounded_doublequote(char *str)
{
	size_t	i;

	if (str[0] != '\"')
		return (FALSE);
	i = 1;
	while (str[i] != '\0')
		i++;
	if (i <= 1)
		return (FALSE);
	if (str[i - 1] != '\"')
		return (FALSE);
	return (TRUE);
}
