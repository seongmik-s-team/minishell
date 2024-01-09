/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:11:16 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 18:15:01 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// convert_wildcard() 는 일반 string에 포함된 wildcard를 공백 하나로 구분된 일반 문자열로 치환하는 함수이다.
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
