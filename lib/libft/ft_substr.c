/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:26:42 by ankozako          #+#    #+#             */
/*   Updated: 2025/04/21 15:00:29 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_size;

	i = 0;
	if (!s)
		return (NULL);
	str_size = ft_strlen(s);
	if (start >= str_size)
		len = 0;
	if (len > str_size - start)
		len = str_size - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
