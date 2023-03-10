/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:02:19 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/28 17:16:19 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(t_pipex *pipex, char **env)
{
	close(pipex->end[0]);
	if (dup2(pipex->file[0], STDIN_FILENO) == -1
		|| dup2(pipex->end[1], STDOUT_FILENO) == -1 || !pipex->path1)
	{
		ft_free_end(pipex);
		perror("");
		exit(1);
	}
	if (pipex->path2)
		free(pipex->path2);
	if (pipex->cmd2)
		free_all(pipex->cmd2);
	execve(pipex->path1, pipex->cmd1, env);
}

static void	ft_sec_child(t_pipex *pipex, char **env)
{
	close(pipex->end[1]);
	if (dup2(pipex->end[0], STDIN_FILENO) == -1
		|| dup2(pipex->file[1], STDOUT_FILENO) == -1 || !pipex->path2)
	{
		ft_free_end(pipex);
		perror("");
		exit(1);
	}
	if (pipex->path1)
		free(pipex->path1);
	if (pipex->cmd1)
		free_all(pipex->cmd1);
	execve(pipex->path2, pipex->cmd2, env);
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
}

void	ft_main_proc(t_pipex *pipex)
{
	ft_close(pipex);
	waitpid(pipex->pid, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	ft_free_end(pipex);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac != 5)
		return (1);
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	ft_init(pipex, av, env);
	if (pipe(pipex->end) == -1)
	{
		ft_free_end(pipex);
		return (perror("Pipe"), 1);
	}
	pipex->pid = fork();
	if (pipex->pid == -1)
		ft_error(pipex);
	if (!pipex->pid)
		ft_child(pipex, env);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		ft_error(pipex);
	if (!pipex->pid2)
		ft_sec_child(pipex, env);
	ft_main_proc(pipex);
	return (0);
}
