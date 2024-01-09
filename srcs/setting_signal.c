/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:34:55 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 17:50:54 by seongmik         ###   ########.fr       */
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

// set_sigint_act() 함수는 SIGINT가 발생했을 때 동작하는 함수이다.
// ctrl + c를 입력 시, 다음 줄로 넘어간다.
void	set_sigint_act(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

// set_sigint() 함수는 SIGINT를 무시하는 함수이다.
// TODO: 다음 줄로 넘어가게 처리 변경
int	set_sigint(void)
{
	static struct sigaction	act;

	act.sa_handler = (void *) set_sigint_act;
	return (sigaction(SIGINT, &act, NULL));
}
