/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:18:37 by ankozako          #+#    #+#             */
/*   Updated: 2025/09/22 12:18:39 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static int	usage(void)
{
	ft_puterr("Usage", "./pipex file1 cmd1 cmd2 file2");
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	px;

	if (ac != 5)
		return (usage());
	px.infile = av[1];
	px.cmd1 = av[2];
	px.cmd2 = av[3];
	px.outfile = av[4];
	px.envp = envp;
	return (run_pipex(&px));
}
