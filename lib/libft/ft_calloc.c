/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:39:39 by ankozako          #+#    #+#             */
/*   Updated: 2025/04/23 14:06:23 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*p;

	total = nmemb * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	ft_memset(p, 0, total);
	return (p);
}
