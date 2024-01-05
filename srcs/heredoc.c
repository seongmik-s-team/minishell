/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:54:56 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/05 19:46:41 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// heredoc_read() 함수는 delimiter를 입력받아서 그 delimiter가 나올 때까지 
// 표준입력으로부터 읽어서 HERE_DOC_TEMP 파일에 저장하는 함수이다.
// 이 함수는 '또는 "로 감싸진 deleimiter가 들어올 경우, 워드 확장을 하지 않고 그대로 저장한다.
int	heredoc_read(char *delimiter)
{
	int		fd;
	int		delimiter_len;
	char	*line;

	fd = open(HERE_DOC_TEMP, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (EXIT_FAILURE);
	delimiter_len = ft_strlen(delimiter) + 1;
	while (1)
	{
		line = readline("heredoc> ");
		if (ft_strncmp(line, delimiter, delimiter_len) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
