/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:21:02 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/19 13:07:30 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	if (ret == 0)
		return (0);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

static char	*ft_intmax(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 12);
	if (ret == 0)
		return (0);
	ret[0] = '-';
	ret[1] = '2';
	ret[2] = '1';
	ret[3] = '4';
	ret[4] = '7';
	ret[5] = '4';
	ret[6] = '8';
	ret[7] = '3';
	ret[8] = '6';
	ret[9] = '4';
	ret[10] = '8';
	ret[11] = '\0';
	return (ret);
}

static size_t	ft_nbrlen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*ret;

	if (n == 0)
		return (ft_zero());
	else if (n == -2147483648)
		return (ft_intmax());
	ret = (char *)malloc(sizeof(char) * ft_nbrlen(n) + 1);
	if (ret == 0)
		return (0);
	i = ft_nbrlen(n) - 1;
	ret[i + 1] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		ret[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
