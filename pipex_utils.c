/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:17:36 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/23 13:44:46 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_cmd(char **cmd_path, char **cmd)
{
	int	i;
	int	ex;

	i = 0;
	ex = -1;
	while (cmd_path[i] && ex == -1)
		ex = execve(cmd_path[i++], cmd, NULL);
	if (ex == -1)
		exit(1);
}

void	ft_openfile(t_pipex *pipex, char **av)
{
	pipex->inf = open(av[1], O_RDWR);
	if (pipex->inf == -1)
	{
		perror("Infile");
		exit(1);
	}
	pipex->outf = open(av[4], O_WRONLY | O_CREAT, 0777);
	if (pipex->outf == -1)
	{
		perror("Outfile");
		exit(1);
	}
}

void	ft_assign_cmd(char **av, char **env, t_pipex *pipex)
{
	pipex->paths = ft_paths(env);
	pipex->cmd1 = ft_split(av[2], ' ');
	pipex->cmd2 = ft_split(av[3], ' ');
	pipex->cmd_path1 = ft_cmd_paths(pipex->paths, pipex->cmd1[0]);
	pipex->cmd_path2 = ft_cmd_paths(pipex->paths, pipex->cmd2[0]);
	free_strings(pipex->paths);
	ft_openfile(pipex, av);
}

void	ft_child(t_pipex *pipex)
{
	if (dup2(pipex->inf, 0) == -1)
		exit(1);
	if (dup2(pipex->end[1], 1) == -1)
		exit(1);
	close(pipex->end[0]);
	ft_exec_cmd(pipex->cmd_path1, pipex->cmd1);
}

void	ft_parent(t_pipex *pipex)
{
	wait(0);
	close(pipex->end[1]);
	if (dup2(pipex->end[0], 0) == -1)
		exit(1);
	if (dup2(pipex->outf, 1) == -1)
		exit(1);
	ft_exec_cmd(pipex->cmd_path2, pipex->cmd2);
}
