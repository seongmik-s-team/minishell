/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_judge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:33:44 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 18:46:41 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// judge_isspace() 함수는 c가 공백인지 확인하는 함수이다.
int	judge_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (TRUE);
	return (FALSE);
}

// judge_isalldigit() 함수는 문자열이 모두 숫자로 이루어져 있는지 확인하는 함수이다.
int	judge_isalldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// judge_isblank() 함수는 문자열이 모두 공백으로 이루어져 있는지 확인하는 함수이다.
int	judge_isblank(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (judge_isspace(str[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// judge_isblank_and_null() 함수는 문자열이 모두 공백으로 이루어져 있는지 확인하는 함수이다.
int	judge_isblank_and_null(char *str)
{
	int	i;

	if (str == NULL)
		return (TRUE);
	i = 0;
	while (str[i] != '\0')
	{
		if (judge_isspace(str[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// judge_dot() 함수는 문자열이 '.' 또는 '..'인지 확인하는 함수이다.
int	judge_dot(char *str)
{
	if (ft_strncmp(str, ".", 2) == 0)
		return (DOT);
	else if (ft_strncmp(str, "..", 3) == 0)
		return (DOT_DOT);
	return (NOT_DOT);
}
