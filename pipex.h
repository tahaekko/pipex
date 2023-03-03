/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:56:02 by msamhaou          #+#    #+#             */
/*   Updated: 2023/03/03 01:16:44 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	int		end[2];
	int		file[2];
	int		pid;
	int		pid2;
}	t_pipex;

char	*ft_get_path(char **cmd_raw, char **env);
void	free_all(char **s);
void	ft_free_end(t_pipex *pipex);
void	ft_close(t_pipex *pipex);
void	ft_error(t_pipex *pipex);
char	*ft_path_find(char **ev);
#endif