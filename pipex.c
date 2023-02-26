/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:02:19 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/25 16:58:27 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(t_pipex *pipex)
{
	close(pipex->end[0]);
	if (dup2(pipex->file[0], STDIN_FILENO) == -1
		|| dup2(pipex->end[1], STDOUT_FILENO) == -1)
	{
		perror("");
		exit(1);
	}
	execve(pipex->path1, pipex->cmd1, NULL);
	close(pipex->end[1]);
}

static void	ft_parent(t_pipex *pipex, int *status)
{
	wait(status);
	close(pipex->end[1]);
	if (dup2(pipex->end[0], STDIN_FILENO) == -1
		|| dup2(pipex->file[1], STDOUT_FILENO) == -1)
	{
		perror("Dup");
		exit(1);
	}
	execve(pipex->path2, pipex->cmd2, NULL);
	close(pipex->end[0]);
}

static void	ft_init(t_pipex *pipex, char **av, char **env)
{
	pipex->file[0] = open(av[1], O_RDONLY);
	pipex->file[1] = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->file[0] == -1 || pipex->file[1] == -1)
	{
		perror("Open File");
		exit(1);
	}
	pipex->cmd1 = ft_split(av[2], ' ');
	pipex->path1 = ft_get_path(pipex->cmd1, env);
	pipex->cmd2 = ft_split(av[3], ' ');
	pipex->path2 = ft_get_path(pipex->cmd2, env);
	if (!pipex->path1 && !pipex->path2)
	{
		perror("Open File");
		exit(1);
	}
}

int	main(int ac, char **av, char **env)
{
	int		status;
	t_pipex	*pipex;

	if (ac != 5)
		return (1);
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	ft_init(pipex, av, env);
	if (pipe(pipex->end) == -1)
		return (perror("Pipe"), 1);
	pipex->pid = fork();
	if (pipex->pid == -1)
		return (perror("Fork"), 1);
	if (!pipex->pid)
	{
		ft_child(pipex);
	}
	else
		ft_parent(pipex, &status);
}
