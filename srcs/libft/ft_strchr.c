/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:48:51 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/17 19:20:53 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	cmp;

	cmp = (char)c;
	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == cmp)
			return (p);
		p++;
	}
	if (cmp == '\0')
		return (p);
	else
		return (0);
}
