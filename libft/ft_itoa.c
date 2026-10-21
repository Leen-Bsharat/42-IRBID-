/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:55:30 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/05 17:38:08 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	size(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		return (i + 1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*fill(char *s, long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		s[i] = '-';
		i++;
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		s[i] = n + '0';
		i++;
		s[i] = '\0';
		return (s);
	}
	while (n != 0)
	{
		s[i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	s[i] = '\0';
	return (s);
}

static char	*rev(long n, char *s)
{
	int		i;
	char	h;
	int		j;

	i = 0;
	j = size(n);
	if (n < 0)
		i = 1;
	if (size(n) <= 1)
		return (s);
	j--;
	while (i < j)
	{
		h = s[i];
		s[i] = s[j];
		s[j] = h;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size(n) + 1));
	if (!str)
		return (NULL);
	str = fill(str, n);
	return (rev(n, str));
}
