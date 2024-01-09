/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:56:55 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 18:56:51 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// sh_print_error() 함수는 minishell에서 발생한 에러를 출력하는 함수이다.
void	sh_cd_print_error(void)
{
	write(2, "minishell: cd: error retrieving current directory: getcwd: "\
	, 60);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
}

// sh_error() 함수는 minishell에서 발생한 에러를 출력하고 프로그램을 종료하는 함수이다.
void	sh_error(char *cmd, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	exit(errno);
}
