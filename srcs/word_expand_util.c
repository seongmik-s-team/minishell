/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expand_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:34:21 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 14:55:09 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// arg_swap() 함수는 args[i]와 args[j]를 바꾸는 함수이다.
void	arg_swap(char **args, size_t i, size_t j)
{
	char	*tmp;

	tmp = args[i];
	args[i] = args[j];
	args[j] = tmp;
}

// replace_blank_to_null() 함수는 args에서 blank를 모두 null로 바꾸는 함수이다.
void	replace_blank_to_null(char **args, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (args[i] != NULL && judge_isblank(args[i]))
		{
			free(args[i]);
			args[i] = NULL;
		}
		i++;
	}
}

// args_pull() 함수는 args사이의 null을 모두 뒤로 보내는 함수이다.
void	args_pull(char **args, size_t len)
{
	size_t	i;
	size_t	j;

	while (TRUE)
	{
		i = 0;
		while (!judge_isblank_and_null(args[i]))
			i++;
		j = i;
		while (judge_isblank_and_null(args[j]) && j < len)
			j++;
		if (j == len)
			break ;
		arg_swap(args, i, j);
	}
	replace_blank_to_null(args, len);
}
