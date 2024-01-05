/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:18:11 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/17 19:25:11 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	cmp;
	char	*ret;

	ret = 0;
	cmp = (char)c;
	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == cmp)
			ret = p;
		p++;
	}
	if (*p == cmp)
		ret = p;
	if (cmp == '\0' || ret != 0)
		return (ret);
	else
		return (0);
}
