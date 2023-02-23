/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:18:35 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/23 13:43:13 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		inf;
	int		outf;
	int		pid;
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	char	**cmd_path1;
	char	**cmd_path2;
	int		end[2];
}	t_pipex;
void	free_strings(char **s);
char	**ft_cmd_paths(char **paths, char *cmd);
char	**ft_paths(char **ev);
void	ft_exec_cmd(char **cmd_path, char **cmd);
void	ft_openfile(t_pipex *pipex, char **av);
void	ft_assign_cmd(char **av, char **env, t_pipex *pipex);
void	ft_child(t_pipex *pipex);
void	ft_parent(t_pipex *pipex);

#endif