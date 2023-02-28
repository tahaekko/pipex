/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:58:10 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/28 01:47:34 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_it(char **s, int pos)
{
	while (pos--)
		free(s[pos]);
	free(s);
}

static char	**ft_concat_path(char **raw_path, char *cmd)
{
	int		i;
	char	**res;

	i = 0;
	while (raw_path[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		exit(1);
	res[i] = NULL;
	i = 0;
	while (raw_path[i])
	{
		res[i] = malloc(sizeof(char)
				* (ft_strlen(raw_path[i]) + ft_strlen(cmd) + 2));
		if (!res[i])
			return (free_it(res, i), NULL);
		ft_strlcpy(res[i], raw_path[i], ft_strlen(raw_path[i]) + 1);
		free(raw_path[i]);
		ft_strlcat(res[i], "/", ft_strlen(res[i]) + 2);
		ft_strlcat(res[i], cmd, ft_strlen(res[i]) + ft_strlen(cmd) + 1);
		i++;
	}
	free(raw_path);
	return (res);
}

static char	**ft_paths(char **ev, char *cmd)
{
	char	*path;
	char	**res;
	char	*ned;
	int		i;

	ned = "PATH=";
	path = NULL;
	i = 0;
	while (ev[i] && path == NULL)
	{
		path = ft_strnstr(ev[i], ned, ft_strlen(ev[i]));
		i++;
	}
	path = ft_substr(path, ft_strlen(ned), ft_strlen(path));
	res = ft_split(path, ':');
	free(path);
	res = ft_concat_path(res, cmd);
	if (!res)
		exit(1);
	return (res);
}

char	*ft_find_exec_path(char **res)
{
	int		i;
	int		exec;
	char	*path;

	i = 0;
	exec = -1;
	while (res[i] && exec == -1)
	{
		exec = access(res[i], X_OK);
		if (exec == 0)
		{
			path = ft_strdup(res[i]);
			free_all(res);
			return (path);
		}
		i++;
	}
	if (exec == -1)
		free_all(res);
	return (NULL);
}

char	*ft_get_path(char **cmd_raw, char **env)
{
	char	*path;

	if(!cmd_raw)
		return (NULL);
	path = NULL;
	if (!ft_strchr(cmd_raw[0], '/'))
		path = ft_find_exec_path(ft_paths(env, cmd_raw[0]));
	else if (ft_strchr(cmd_raw[0], '/') && access(cmd_raw[0], X_OK) == -1)
		return (NULL);
	else if (ft_strchr(cmd_raw[0], '/') && access(cmd_raw[0], X_OK) == 0)
		path = ft_strdup(cmd_raw[0]);
	return (path);
}
