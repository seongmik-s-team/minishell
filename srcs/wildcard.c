/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:11:16 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 18:12:26 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*convert_wildcard(char *str)
{
	char	*ret;

	ret = ft_strdup(str);
	if (ret == NULL)
		return (NULL);
	ret = convert_wild_card_question(ret);
	ret = convert_wild_card_star(ret);
	return (ret);
}
