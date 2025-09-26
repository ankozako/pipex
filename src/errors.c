/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:03:40 by ankozako          #+#    #+#             */
/*   Updated: 2025/09/22 13:03:41 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_puterr(const char *a, const char *b)
{
	if (a)
	{
		ft_putstr_fd((char *)a, 2);
		if (b)
			ft_putstr_fd(": ", 2);
	}
	if (b)
		ft_putstr_fd((char *)b, 2);
}

void	ft_error(const char *what)
{
	if (what)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd((char *)what, 2);
		ft_putstr_fd(": ", 2);
	}
	perror(NULL);
}

void	ft_free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_exit_error(const char *path)
{
	int	e;

	e = errno;
	if (path)
	{
		errno = e;
		perror(path);
	}
	if (e == EACCES || e == EISDIR)
		_exit(126);
	else
		_exit(127);
}
