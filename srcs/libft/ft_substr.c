/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:19:18 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/19 05:04:28 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (ft_strlen(s) <= start)
	{
		ret = (char *)malloc(sizeof(char));
		if (ret == 0)
			return (0);
		ret[0] = '\0';
		return (ret);
	}
	if (ft_strlen(&s[start]) <= len)
		ret = (char *)malloc(sizeof(char) * ft_strlen(&s[start]) + 1);
	else
		ret = (char *)malloc(sizeof(char) * len + 1);
	if (ret == 0)
		return (0);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
