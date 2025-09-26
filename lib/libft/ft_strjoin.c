/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:59:45 by ankozako          #+#    #+#             */
/*   Updated: 2025/04/17 12:30:07 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*concats;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	concats = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!concats)
		return (NULL);
	ft_memcpy(concats, s1, len1);
	ft_memcpy(concats + len1, s2, len2);
	concats[len1 + len2] = '\0';
	return (concats);
}
