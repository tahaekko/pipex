/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:14:25 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/28 01:46:18 by msamhaou         ###   ########.fr       */
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
