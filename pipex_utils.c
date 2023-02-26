/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:58:10 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/25 17:00:56 by msamhaou         ###   ########.fr       */
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
	res[i] = NULL;
	i = 0;
	while (raw_path[i])
	{
		res[i] = malloc(sizeof(char *)
				* (ft_strlen(raw_path[i]) + ft_strlen(cmd) + 2));
		if (!res)
			free_it(res, i);
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
	res = ft_concat_path(res, cmd);
	return (res);
}

char	*ft_get_path(char **cmd_raw, char **env)
{
	int		exec;
	int		i;
	char	**res;
	char	*path;

	path = NULL;
	exec = -1;
	i = 0;
	if (!ft_strchr(cmd_raw[0], '/'))
	{
		res = ft_paths(env, cmd_raw[0]);
		while (res[i] && exec == -1)
		{
			path = res[i];
			exec = access(res[i++], X_OK);
		}
		if (exec == -1)
			return (NULL);
	}
	else if (ft_strchr(cmd_raw[0], '/') && access(cmd_raw[0], X_OK) == -1)
		return (NULL);
	else if (ft_strchr(cmd_raw[0], '/') && access(cmd_raw[0], X_OK) == 0)
		path = cmd_raw[0];
	return (path);
}
