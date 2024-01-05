/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:24:28 by seongmik          #+#    #+#             */
/*   Updated: 2023/03/23 17:04:51 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**lst_ret;
	t_list	*new_node;
	t_list	*ret;

	lst_ret = (t_list **)malloc(sizeof(t_list *));
	if (lst_ret == 0)
		return (0);
	*lst_ret = 0;
	while (lst != 0)
	{
		new_node = ft_lstnew(lst->content);
		if (new_node == 0)
		{
			ft_lstclear(lst_ret, del);
			free(lst_ret);
			return (0);
		}
		new_node->content = f(new_node->content);
		ft_lstadd_back(lst_ret, new_node);
		lst = lst->next;
	}
	ret = *lst_ret;
	free(lst_ret);
	return (ret);
}
