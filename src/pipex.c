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

static void	run_cmd(char *cmd, char **envp)
{
	char	**argv;
	char	*path;

	argv = ft_split(cmd, ' ');
	if (!argv || !argv[0])
		exit(127);
	path = get_cmd_path(argv[0], envp);
	if (!path)
	{
		put_error(argv[0], "command not found");
		free_split(argv);
		exit(127);
	}
	execve(path, argv, envp);
	if (errno == EACCES || errno == EISDIR)
		exit(126);
	exit(127);
}

static void	in_child(int *fd, t_pipex *px)
{
	int	in_fd;

	in_fd = open_in(px->infile);
	if (dup2(in_fd, STDIN_FILENO) < 0)
		exit_error();
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		exit_error();
	close(fd[0]);
	close(in_fd);
	run_cmd(px->cmd1, px->envp);
}

static void	out_child(int *fd, t_pipex *px)
{
	int	out_fd;

	out_fd = open_out(px->outfile);
	if (dup2(fd[0], STDIN_FILENO) < 0)
		exit_error();
	if (dup2(out_fd, STDOUT_FILENO) < 0)
		exit_error();
	close(fd[1]);
	close(out_fd);
	run_cmd(px->cmd2, px->envp);
}

int	run_pipex(t_pipex *px)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(fd) < 0)
		return (exit_error(), 1);
	pid1 = fork();
	if (pid1 < 0)
		return (exit_error(), 1);
	if (pid1 == 0)
		in_child(fd, px);
	pid2 = fork();
	if (pid2 < 0)
		return (exit_error(), 1);
	if (pid2 == 0)
		out_child(fd, px);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WIFEXITED(status));
	return (1);
}
