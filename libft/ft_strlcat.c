/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:27:16 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:31:04 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			dst_size;
	size_t			src_size;
	size_t			i;
	size_t			c;

	src_size = ft_strlen(src);
	dst_size = 0;
	while (dst && dst[dst_size] != '\0' && dst_size < size)
		dst_size++;
	if (size <= dst_size)
		return (size + src_size);
	i = dst_size;
	c = 0;
	while (src[c] != '\0' && (i + 1) < size)
	{
		dst[i] = src[c];
		i++;
		c++;
	}
	dst[i] = '\0';
	return (dst_size + src_size);
}
