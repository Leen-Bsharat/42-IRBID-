/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 10:29:52 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:34:33 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_size;

	if (*little == '\0')
		return ((char *)big);
	little_size = ft_strlen(little);
	i = 0;
	while (big[i] != '\0' && (i + little_size) <= len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j])
			j++;
		if (j == little_size)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
