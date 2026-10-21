/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:37:25 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:29:24 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			count;

	ptr = str;
	ch = c;
	count = 0;
	while (count < n)
	{
		*ptr = ch;
		ptr++;
		count++;
	}
	return (str);
}
