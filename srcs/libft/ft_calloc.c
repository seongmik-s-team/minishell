/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:46:50 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/18 22:55:37 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;
	size_t	len;

	i = 0;
	len = count * size;
	ret = (void *)malloc(len);
	if (ret == 0)
		return ((void *)0);
	while (i < len)
	{
		((unsigned char *)ret)[i] = 0;
		i++;
	}
	return (ret);
}
