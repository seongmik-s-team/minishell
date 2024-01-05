/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:34:55 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 19:50:40 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// set_sigquit() 함수는 SIGQUIT를 무시하는 함수이다.
int	set_sigquit(void)
{
	static struct sigaction	act;

	act.sa_handler = SIG_IGN;
	return (sigaction(SIGQUIT, &act, NULL));
}

// set_sigint() 함수는 SIGINT를 무시하는 함수이다.
// TODO: 다음 줄로 넘어가게 처리 변경
int	set_sigint(void)
{
	static struct sigaction	act;

	act.sa_handler = (void *) rl_redisplay;
	return (sigaction(SIGINT, &act, NULL));
}

// init_sig_setting() 함수는 signal을 설정하는 함수이다.
int	init_sig_setting(void)
{
	if (set_sigquit())
		return (EXIT_FAILURE);
	if (set_sigint())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
