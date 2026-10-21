/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:43:43 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:34:04 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;
	unsigned char	x;

	p = (unsigned char *) s;
	i = 0;
	x = c;
	while (i < n)
	{
		if (p[i] == x)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
