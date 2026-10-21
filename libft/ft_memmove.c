/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:51:18 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/12 12:38:18 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*dest_bth_src(size_t n, const unsigned char *s, void *dest)
{
	unsigned char	*d;

	d = dest;
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = src;
	d = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
		return (dest_bth_src(n, s, dest));
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
}
