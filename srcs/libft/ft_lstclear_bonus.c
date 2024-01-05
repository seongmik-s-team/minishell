/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:14:05 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/23 17:47:06 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*tmp;

	if (lst == 0 || del == 0)
		return ;
	p = *lst;
	while (p != 0)
	{
		tmp = p;
		p = p->next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}
