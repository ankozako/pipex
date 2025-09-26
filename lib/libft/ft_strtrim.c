/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:36:41 by ankozako          #+#    #+#             */
/*   Updated: 2025/04/25 14:47:48 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	substrlen;
	char	*trimmed;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	j = len - 1;
	while (j > i && ft_is_set(s1[j], set))
		j--;
	substrlen = j - i;
	trimmed = (char *)malloc(sizeof(char) * (substrlen + 2));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + i, substrlen + 1);
	trimmed[substrlen + 1] = '\0';
	return (trimmed);
}
