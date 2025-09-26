/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:03:48 by ankozako          #+#    #+#             */
/*   Updated: 2025/09/22 13:03:49 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static char	*get_pathline(char **envp)
{
	int	i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	**split_cmd(char *command)
{
	if (!command || !*command)
		return (NULL);
	return (ft_split(command, ' '));
}

static char	*find_cmd(char *cmd, char **envp)
{
	char	*pathline;
	char	**paths;
	char	*tmp;
	char	*full;
	int		i;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	pathline = get_pathline(envp);
	if (!pathline)
		return (NULL);
	paths = ft_split(pathline, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			break ;
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full)
			break ;
		if (access(full, X_OK) == 0)
			return (ft_free_arr(paths), full);
		free(full);
		i++;
	}
	ft_free_arr(paths);
	return (NULL);
}

static void	child_in(const char *infile, int pw, char *c, char **envp)
{
	int		fd;
	char	**argv;
	char	*path;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		ft_error(infile);
	if (fd >= 0 && dup2(fd, STDIN_FILENO) < 0)
		ft_error("dup2");
	if (dup2(pw, STDOUT_FILENO) < 0)
		ft_error("dup2");
	close(pw);
	if (fd >= 0)
		close(fd);
	argv = split_cmd(c);
	if (!argv || !argv[0])
		_exit(127);
	path = find_cmd(argv[0], envp);
	if (!path)
		ft_exit_error(argv[0]);
	execve(path, argv, envp);
	ft_exit_error(argv[0]);
}

static void	child_out(const char *outfile, int pr, char *c, char **envp)
{
	int		fd;
	char	**argv;
	char	*path;

	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		ft_error(outfile);
	if (dup2(pr, STDIN_FILENO) < 0)
		ft_error("dup2");
	if (fd >= 0 && dup2(fd, STDOUT_FILENO) < 0)
		ft_error("dup2");
	close(pr);
	if (fd >= 0)
		close(fd);
	argv = split_cmd(c);
	if (!argv || !argv[0])
		_exit(127);
	path = find_cmd(argv[0], envp);
	if (!path)
		ft_exit_error(argv[0]);
	execve(path, argv, envp);
	ft_exit_error(argv[0]);
}

int	run_pipex(t_pipex *px)
{
	int		fds[2];
	pid_t	p1;
	pid_t	p2;
	int		st;

	if (pipe(fds) < 0)
		return (ft_error("pipe"), 1);
	p1 = fork();
	if (p1 < 0)
		return (ft_error("fork"), close(fds[0]), close(fds[1]), 1);
	if (p1 == 0)
	{
		close(fds[0]);
		child_in(px->infile, fds[1], px->cmd1, px->envp);
		return (0);
	}
	p2 = fork();
	if (p2 < 0)
		return (ft_error("fork"), close(fds[0]), close(fds[1]), 1);
	if (p2 == 0)
	{
		close(fds[1]);
		child_out(px->outfile, fds[0], px->cmd2, px->envp);
		return (0);
	}
	close(fds[0]);
	close(fds[1]);
	waitpid(p1, NULL, 0);
	waitpid(p2, &st, 0);
	if (WIFEXITED(st))
		return (WEXITSTATUS(st));
	return (1);
}
