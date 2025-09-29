/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:51:24 by ankozako          #+#    #+#             */
/*   Updated: 2025/09/22 11:51:25 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include "../lib/libft/libft.h"

typedef struct s_pipex
{
	const char	*infile;
	const char	*outfile;
	char		*cmd1;
	char		*cmd2;
	char		**envp;
}	t_pipex;

void	exit_error(void);
void	put_error(const char *prefix, const char *message);
void	free_split(char **array);

int		open_in(const char *infile);
int		open_out(const char *outfile);

char	*get_cmd_path(char *cmd, char **envp);
int		run_pipex(t_pipex *px);

#endif