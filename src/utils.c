/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:08:32 by ankozako          #+#    #+#             */
/*   Updated: 2025/09/27 12:08:37 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	dup2(int ftom, int to)
{
	if (dup2(from, to) < 0)
		exit_error();
}

int	open_in(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		put_error("pipex", infile);
		fd = open("/dev/null", O_RDONLY);
		if (fd < 0)
			exit_error();
	}
	return (fd);
}

int	open_out(char *outfile)
{
	int	fd;

	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		put_error("pipex", outfile);
		exit_error();
	}
	return (fd);
}
