/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:36:57 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:31:32 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)s;
	while (p[i] != '\0')
	{
		if (p[i] == (char) c)
			return (&p[i]);
		i++;
	}
	if ((char) c == '\0')
		return (&p[i]);
	return (NULL);
}
