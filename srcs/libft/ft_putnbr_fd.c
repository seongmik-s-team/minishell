/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:19:03 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/20 18:25:49 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recursive(long long lln, int fd, int depth)
{
	char	buf;

	if (lln == 0 && depth > 0)
		return ;
	ft_putnbr_recursive(lln / 10, fd, depth + 1);
	buf = '0' + (lln % 10);
	write(fd, &buf, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	lln;

	lln = (long long)n;
	if (lln < 0)
	{
		write(fd, "-", 1);
		lln *= -1;
	}
	ft_putnbr_recursive(lln, fd, 0);
}
