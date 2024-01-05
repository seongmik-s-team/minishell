/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:32:47 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/22 21:07:31 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (new == 0 || lst == 0)
		return ;
	p = *lst;
	if (p != 0)
	{
		while (p->next != 0)
		{
			p = p->next;
		}
		p->next = new;
	}
	else
	{
		*lst = new;
	}
}
