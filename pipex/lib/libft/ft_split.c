/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:03:06 by ankozako          #+#    #+#             */
/*   Updated: 2025/04/26 09:32:36 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	ft_substr_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_alloc_word(char const *s, char c, int *i)
{
	int	start;
	int	len;

	start = *i;
	len = 0;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		len++;
	}
	return (ft_substr(s, start, len));
}

static char	**ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = malloc((ft_substr_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = ft_alloc_word(s, c, &i);
			if (!str[j])
				return (ft_free(str, j));
			j++;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}
