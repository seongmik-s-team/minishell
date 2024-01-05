/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 05:10:22 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/19 05:45:06 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isin_head(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				cnt++;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			return (cnt);
		i++;
	}
	return (cnt);
}

static size_t	ft_isin_rear(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	cnt;

	i = ft_strlen(s1) - 1;
	cnt = 0;
	while (i >= 0)
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				cnt++;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			return (cnt);
		i--;
	}
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	len -= ft_isin_head(s1, set);
	if (ft_strlen(s1) != 0)
		len -= ft_isin_rear(s1, set);
	if (ft_strlen(s1) == 0
		|| ft_strlen(s1) <= ft_isin_head(s1, set) + ft_isin_rear(s1, set))
	{
		ret = (char *)malloc(sizeof(char));
		if (ret == 0)
			return (0);
		ret[0] = '\0';
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, &s1[ft_isin_head(s1, set)], len + 1);
	return (ret);
}
