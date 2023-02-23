/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:40:57 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/23 12:23:10 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_paths(char **ev)
{
	int		i;
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
	int		i;
	char	**res;

	i = 0;
	while (paths[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	res[i] = NULL;
	i = 0;
	while (paths[i])
	{
		res[i] = (char *)malloc(sizeof(char)
				* (ft_strlen(paths[i]) + ft_strlen(cmd) + 1));
		ft_strlcpy(res[i], paths[i], sizeof(char) * (ft_strlen(paths[i]) + 1));
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
		free(s[i++]);
	free(s);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac != 5)
		return (1);
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	ft_assign_cmd(av, env, pipex);
	if (pipe(pipex->end) == -1)
		exit(1);
	pipex->pid = fork();
	if (pipex->pid == -1)
		exit(1);
	if (!pipex->pid)
		ft_child(pipex);
	else
		ft_parent(pipex);
	free(pipex);
}
