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

void	put_error(const char *prefix, const char *message)
{
	if (prefix)
		ft_putstr_fd((char *)prefix, 2);
	ft_putstr_fd(": ", 2);
	if (message)
		ft_putstr_fd((char *)message, 2);
	ft_putstr_fd("\n", 2);
}

void	free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
