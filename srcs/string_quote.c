/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:28:56 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 16:54:37 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// quote_delsingle() 함수는 str에서 '를 제거하는 함수이다.
char	*quote_delsingle(char *str)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*ret;

	tmp = ft_strdup(str);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\'')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	ret = ft_strdup(tmp);
	free(tmp);
	return (ret);
}

// quote_deldouble() 함수는 str에서 "를 제거하는 함수이다.
char	*quote_deldouble(char *str)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*ret;

	tmp = ft_strdup(str);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\"')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	ret = ft_strdup(tmp);
	free(tmp);
	return (ret);
}

// quote_del() 함수는 str에서 '와 "를 제거하는 함수이다.
char	*quote_del(char *str)
{
	char	*tmp;
	char	*ret;

	tmp = quote_delsingle(str);
	if (tmp == NULL)
		return (NULL);
	ret = quote_deldouble(tmp);
	free(tmp);
	free(str);
	return (ret);
}

// quote_judge_and_del() 함수는 str이 ' 또는 "로 둘러쌓여 있는지 확인하고 제거하는 함수이다.
int	quote_judge_and_del(char **str)
{
	int		ret;

	if (surrounded_singlequote(*str) || \
		surrounded_doublequote(*str))
	{
		ret = TRUE;
		*str = quote_del(*str);
	}
	else
		ret = FALSE;
	return (ret);
}
