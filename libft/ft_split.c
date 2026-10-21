/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:49:51 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:37:38 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	words_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_(char **s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	**fill(char **str, char const *s, char c)
{
	size_t	start;
	size_t	j;

	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			start = 0;
			while (s[start] && s[start] != c)
				start++;
			str[j] = ft_substr(s, 0, start);
			if (!str[j])
				return (free_(str, j), NULL);
			s += start;
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	w_count;

	if (!s)
		return (NULL);
	w_count = words_count(s, c);
	str = (char **) malloc (sizeof(char *) * (w_count + 1));
	if (!str)
		return (NULL);
	return (fill (str, s, c));
}
