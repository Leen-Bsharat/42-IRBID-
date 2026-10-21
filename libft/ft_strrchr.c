/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:40:09 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:31:57 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s);
	ptr = (char *) s;
	if ((char) c == '\0')
		return (&ptr[size]);
	while (size > 0)
	{
		if (ptr[size - 1] == (char) c)
			return (&ptr[size - 1]);
		size--;
	}
	return (NULL);
}
