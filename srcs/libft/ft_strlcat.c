/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:14:02 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/17 18:45:32 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	while (((unsigned char *)dst)[i] != '\0')
		i++;
	while (((unsigned char *)src)[j] != '\0' && dstlen + j + 1 < dstsize)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[j];
		i++;
		j++;
	}
	((unsigned char *)dst)[i] = '\0';
	if (dstsize < dstlen)
		return (srclen + dstsize);
	else
		return (dstlen + srclen);
}
