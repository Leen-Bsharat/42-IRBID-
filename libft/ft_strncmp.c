/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:41:37 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:32:57 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			i;

	i = 0;
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	while (i < n)
	{
		if (s_1[i] != '\0' && s_2[i] != '\0')
			if (s_1[i] != s_2[i])
				return (s_1[i] - s_2[i]);
		if (s_1[i] == '\0' || s_2[i] == '\0')
			return (s_1[i] - s_2[i]);
		i++;
	}
	return (0);
}
