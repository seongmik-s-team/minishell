/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:54:56 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/09 16:55:34 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// unique_filename() 함수는 heredoc 파일을 저장할 때 사용할 유니크한 이름의 파일을 생성하는 함수이다.
char	*unique_filename(void)
{
	static int	atomic_idx;
	char		*temppath;
	char		*filename;
	char		*tmp;

	temppath = ft_strdup(HERE_DOC_TEMP);
	tmp = ft_itoa(atomic_idx);
	atomic_idx += 1;
	filename = ft_strjoin(temppath, tmp);
	free(temppath);
	free(tmp);
	return (filename);
}

// heredoc_word_expand() 함수는 heredoc에서 환경변수를 확장하는 함수이다.
// delimiter에 따라서 확장하거나 확장하지 않는다.
int	heredoc_word_expand(int fd, char *line, int is_quoted, t_env *env)
{
	char	*expanded;

	if (is_quoted)
	{
		ft_putendl_fd(line, fd);
		free(line);
		return (1);
	}
	else
	{
		expanded = expand_by_env(line, env);
		ft_putendl_fd(expanded, fd);
		free(expanded);
		return (0);
	}
}

// heredoc_read() 함수는 delimiter를 입력받아서 그 delimiter가 나올 때까지 
// 표준입력으로부터 읽어서 HERE_DOC_TEMP 파일에 저장하는 함수이다.
// TODO: 이 함수는 '또는 "로 감싸진 deleimiter가 들어올 경우, 워드 확장을 하지 않고 그대로 저장한다.
// TODO: 이 함수는 랜덤한 이름의 파일을 생성해서 내용을 저장하고, 사용 후에 파일을 삭제한다.
int	heredoc_read(char **delimiter, int is_quoted, t_env *env)
{
	int		fd;
	char	*line;
	char	*filename;

	filename = unique_filename();
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	free(filename);
	if (fd == -1)
		return (FAILURE);
	while (1)
	{
		line = readline("> ");
		if (ft_strncmp(line, *delimiter, ft_strlen(*delimiter) + 1) == 0)
		{
			free(line);
			break ;
		}
		heredoc_word_expand(fd, line, is_quoted, env);
	}
	close(fd);
	return (SUCCESS);
}
