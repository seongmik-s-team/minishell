/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:35 by seongmik          #+#    #+#             */
/*   Updated: 2024/01/04 13:45:55 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_putstr_fd(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

EXIT_STATUS	builtin_cd(int argc, char *args[])
{
	char	*path;

	if (argc == 1)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (EXIT_FAILURE);
		}
	}
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
