/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:35:54 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 15:44:53 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// modifier_tolower() 함수는 str을 소문자 문자열로 바꾸는 함수이다.
char	*modifier_tolower(char *str)
{
	size_t	i;
	char	*ret;

	ret = ft_strdup(str);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (ret[i])
	{
		ret[i] = ft_tolower(ret[i]);
		i++;
	}
	return (ret);
}

// modifier_replace() 함수는 str에 put을 here 인덱스에 size만큼 바꾸는 함수이다.
char	*modifier_replace(char *str, char *put, size_t here, size_t size)
{
	char	*head;
	char	*rear;
	char	*tmp;
	char	*ret;

	head = ft_substr(str, 0, here);
	rear = ft_substr(str, here + size, ft_strlen(str) - here - size);
	tmp = ft_strjoin(head, put);
	ret = ft_strjoin(tmp, rear);
	free(head);
	free(rear);
	free(tmp);
	return (ret);
}

// modifier_strinsult() 함수는 str에 put을 here 인덱스에 삽입하는 함수이다.
char	*modifier_insult(char *str, char *put, size_t here)
{
	char	*head;
	char	*rear;
	char	*tmp;
	char	*ret;

	head = ft_substr(str, 0, here);
	rear = ft_substr(str, here, ft_strlen(str) - here);
	tmp = ft_strjoin(head, put);
	ret = ft_strjoin(tmp, rear);
	free(head);
	free(rear);
	free(tmp);
	return (ret);
}

// modifier_trpjoin() 함수는 strhead, put, strrear을 합쳐서 리턴하는 함수이다.
char	*modifier_trpjoin(char *strhead, char *put, char *strrear)
{
	char	*head;
	char	*rear;
	char	*tmp;
	char	*ret;

	head = ft_strdup(strhead);
	rear = ft_strdup(strrear);
	tmp = ft_strjoin(head, put);
	ret = ft_strjoin(tmp, rear);
	free(head);
	free(rear);
	free(tmp);
	return (ret);
}
