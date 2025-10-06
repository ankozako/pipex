/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:19:29 by ankozako          #+#    #+#             */
/*   Updated: 2025/09/27 13:19:31 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static char	*get_pathline(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) == envp[i])
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*path_join(const char *dir, const char *cmd)
{
	char	*temp;
	char	*full;

	temp = ft_strjoin((char *)dir, "/");
	if (!temp)
		return (NULL);
	full = ft_strjoin(temp, (char *)cmd);
	free(temp);
	return (full);
}

static char	*find_in_dirs(char **dirs, const char *cmd)
{
	int		i;
	char	*full;

	i = 0;
	while (dirs && dirs[i])
	{
		full = path_join(dirs[i], cmd);
		if (!full)
			return (NULL);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*pathline;
	char	**dirs;
	char	*full;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	pathline = get_pathline(envp);
	if (!pathline)
		return (NULL);
	dirs = ft_split(pathline, ':');
	if (!dirs)
		return (NULL);
	full = find_in_dirs(dirs, cmd);
	free_split(dirs);
	return (full);
}
