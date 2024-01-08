/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:33:44 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/08 14:36:37 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// ft_str_tolower() 함수는 str을 소문자 문자열로 바꾸는 함수이다.
char	*ft_str_tolower(char *str)
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

// ft_isspace() 함수는 c가 공백인지 확인하는 함수이다.
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

// is_all_digit() 함수는 문자열이 모두 숫자로 이루어져 있는지 확인하는 함수이다.
int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// is_blank() 함수는 문자열이 모두 공백으로 이루어져 있는지 확인하는 함수이다.
int	is_blank(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
