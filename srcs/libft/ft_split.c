/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 05:45:25 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/19 12:20:23 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_error(char **ret, size_t idx, char *status)
{
	if (status != 0)
		return (0);
	while (idx > 0)
	{
		free(ret[idx]);
		idx--;
	}
	free(ret[0]);
	free(ret);
	return (1);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	cnt;
	int		flag;

	i = 0;
	cnt = 0;
	len = ft_strlen(s);
	flag = 1;
	while (i < len)
	{
		if (s[i] == c || s[i] == '\0')
			flag = 1;
		else if (flag)
		{
			cnt++;
			flag = 0;
		}
		i++;
	}
	return (cnt);
}

static int	ft_fill_word(char **ret, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	idx;
	size_t	len;

	i = 0;
	idx = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		j = 0;
		while (s[i + j] != c && i + j < len)
			j++;
		if (j > 0)
		{
			ret[idx] = (char *)malloc(sizeof(char) * (j + 1));
			if (ft_error(ret, idx, ret[idx]))
				return (0);
			ft_strlcpy(ret[idx], &s[i], j + 1);
			ret[idx++][j] = '\0';
		}
		i += j + 1;
	}
	ret[ft_count_word(s, c)] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	len;

	len = ft_strlen(s);
	ret = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (ret == 0)
		return (0);
	if (!ft_fill_word(ret, s, c))
		return (0);
	return (ret);
}
