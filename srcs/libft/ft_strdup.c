/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:55:51 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/18 23:04:37 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	i;
	size_t	len;

	i = 0;
	len = (sizeof(char) * ft_strlen(s1)) + 1;
	ret = (char *)malloc(len);
	if (ret == 0)
		return ((void *)0);
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}
