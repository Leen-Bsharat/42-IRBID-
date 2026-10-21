/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 11:31:04 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:29:11 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*d = *s;
		i++;
		d++;
		s++;
	}
	return (dest);
}
