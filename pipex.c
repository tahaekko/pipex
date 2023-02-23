/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:40:57 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/23 10:08:19 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	**ft_paths(char **ev)
{
	int	i;
	char	*path;
	char	*needle;
	char	**res;

	path = NULL;
	needle = "PATH=";
	i = 0;
	while (ev[i] && path == NULL)
	{
		path = ft_strnstr(ev[i], needle, ft_strlen(ev[i]));
		i++;
	}
	path = ft_substr(path, (unsigned int)ft_strlen(needle), ft_strlen(path));
	res = ft_split(path, ':');
	free(path);
	return (res);
}

char	**ft_cmd_paths(char **paths, char *cmd)
{
	int	i;
	char **res;

	i = 0;
	while (paths[i])
		i++;
	res = (char**)malloc(sizeof(char *) * (i + 1));
	res[i] = NULL;
	i = 0;
	while (paths[i])
	{
		res[i] = (char*)malloc(sizeof(char) * (ft_strlen(paths[i]) + ft_strlen(cmd) + 1));
		ft_strlcpy(res[i], paths[i], sizeof(char)*(ft_strlen(paths[i]) + 1));
		i++;
	}
	i = 0;
	while (res[i])
	{
		ft_strlcat(res[i], "/", ft_strlen(res[i]) + 2);
		ft_strlcat(res[i], cmd, ft_strlen(res[i]) + ft_strlen(cmd) + 1);
		i++;
	}
	return (res);
}

void	free_strings(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_exec_cmd(char **cmd_path, char **cmd)
{
	int i = 0;
	int ex = -1;
	while (cmd_path[i] &&ex == -1)
	{
		execve(cmd_path[i], cmd, NULL);
		i++;
	}
	if (ex == -1)
		perror("Execve : ");
}

int main(int ac, char **av, char **env)
{
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	char	**cmd_path1;
	char	**cmd_path2;
	int	end[2];
	int	inf;
	int	outf;

	//parse
	if (ac != 5)
		return 1;
	paths = ft_paths(env);
	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');

	cmd_path1 = ft_cmd_paths(paths, cmd1[0]);
	cmd_path2 = ft_cmd_paths(paths, cmd2[0]);
	free_strings(paths);
	//
	
	//fork
	inf = open(av[1], O_RDWR);
	outf = open(av[4], O_WRONLY | O_CREAT, 0777);
	pipe(end);
	int pid = fork();
	if (!pid)
	{
		dup2(inf, 0);
		dup2(end[1], 1);
		close(end[0]);
		ft_exec_cmd(cmd_path1, cmd1);
	}
	else
	{
		wait(0);
		close(end[1]);
		dup2(end[0], 0);
		dup2(outf, 1);
		ft_exec_cmd(cmd_path2, cmd2);
	}
}