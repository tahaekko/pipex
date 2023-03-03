/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:14:25 by msamhaou          #+#    #+#             */
/*   Updated: 2023/03/03 01:17:05 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_end(t_pipex *pipex)
{
	if (pipex->path1)
		free(pipex->path1);
	if (pipex->path2)
		free(pipex->path2);
	if (pipex->cmd1)
		free_all(pipex->cmd1);
	if (pipex->cmd2)
		free_all(pipex->cmd2);
	free(pipex);
}

void	ft_close(t_pipex *pipex)
{
	close(pipex->end[0]);
	close(pipex->end[1]);
	close(pipex->file[0]);
	close(pipex->file[1]);
}

void	ft_error(t_pipex *pipex)
{
	ft_free_end(pipex);
	perror("");
	exit(1);
}

void	free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

char	*ft_path_find(char **ev)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	while (ev[i] && path == NULL)
	{
		path = ft_strnstr(ev[i], "PATH=", ft_strlen(ev[i]));
		i++;
	}
	path = ft_substr(path, ft_strlen("PATH="), ft_strlen(path));
	if (!path)
		exit(1);
	return (path);
}
