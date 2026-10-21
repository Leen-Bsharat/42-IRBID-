/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 10:41:05 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:35:38 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	total;	

	total = nmemb * size;
	if (nmemb != 0 && ((total / nmemb) != size))
		return (NULL);
	s = malloc(total);
	if (!s)
		return (NULL);
	ft_bzero(s, total);
	return (s);
}
